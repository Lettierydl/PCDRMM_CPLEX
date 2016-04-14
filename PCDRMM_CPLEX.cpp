//============================================================================
// Name        : PCDRMM_CPLEX.cpp
// Author      : Lettiery DLamare
// Version     :
// Copyright   : UFPB
// Description : Hello World in C, Ansi-style
//============================================================================

#include "Dados.h"
#include "Arquivo.h"
#include "Solucao.h"
#include "Grafico.h"
#include "Teste.h"

#include <iostream>

#include <iostream>
#include <iomanip>

#include <ilcplex/ilocplex.h>

using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::endl;
using std::setprecision;

#include <fstream>
#include <list>
#include <vector>

using std::ifstream;

#include <stdlib.h>

#include <climits>
#include <string.h>

#include <math.h>

using namespace std;

Solucao* OptimizeCplex(Dados *d);

int main(int argc, char **argv) {

	cout << "PCDRMM_CPLEX" << endl;

	int qt = 1;

	vector<float> execucao(qt, 0);
	vector<float> tempos(qt, 0);
	vector<float> valores(qt, 0);
	vector< string > instancia_name(qt);
	//cout << "PSPLIB/j20" << endl;

	for (int i = 1; i <= qt; i++) {
		cout << "instancia " << i << endl;

		clock_t start_time;
		start_time = clock();

		/*
		string instancia = "Instancias_Denise";
		Arquivo arq(instancia, i);
		Dados *d = arq.lerInstancia();
		*/

		string instancia = "PSPLIB/j20";
		Arquivo arq(instancia, i);

		Dados *d = arq.lerInstanciaPSPLIB();

		Solucao *cus = new Solucao(d);
		cus->iniciarSolucaoComMelhorCusto();
		d->D = cus->tempo;

		//d->D = limites[i-1];

//	d->print();

		Solucao *s = OptimizeCplex(d);

		cout << s->custo << " X " << s->tempo << endl;

		//cout << cus->tempo << endl;

		float time_in_seconds = (clock() - start_time) / (double) CLOCKS_PER_SEC;
		execucao[i] = time_in_seconds;
		valores[i] = s->custo;
		tempos[i] = s->tempo;
		//instancia_name[i] = arq.nomeArquivo;

		arq.salvarResposta(i, s->custo, s->tempo, time_in_seconds);

		//s->print();

		//Teste t(d);
		//t.testarSolucao(s);

		//Grafico g;
		//g.plotarGraficoDaSolucao(s);

	}

	for (int i = 0; i <= qt; i++) {
		//cout << instancia_name[i]<<"\t\t" << valores[i]<<"\t" <<  tempos[i] << "\t"<< execucao[i] <<endl;
		cout << valores[i]<< "\t"<< execucao[i] <<endl;
		//printf(".s\t %.2f\t%.2f\n", instancia_name[i], valores[i], tempos[i]);
	}

	return EXIT_SUCCESS;
}

void restricaoCusto(int T, IloEnv env, IloArray<IloArray<IloBoolVarArray> > x,
		const IloModel& modelo, const IloNumVarArray& a, Dados* d) {
	//mostrar que o recurso é renovavel
	//terceira restricao
	//garante que durante a execucao da atividade a quantidade ak nao será exedida

	for (int t = 0; t < T; t++) {
		for (int k = 0; k < d->tipos; k++) {
			IloExpr recs(env);
			for (int j = 0; j < d->j; j++) {
				for (int i = 0; i < d->M[j]; i++) {

					if (t + d->d[j][i] < T) {
						for (int du = t; du <= t + d->d[j][i]; du++) {
							recs += d->r[j][i][k] * x[j][i][du];
						}
					} else if (t < T) {
						for (int du = t; du < T; du++) {
							recs += d->r[j][i][k] * x[j][i][du];
						}
					}

				}
			}
			modelo.add(recs <= a[k]);
		}
	}
}

void restricaoJanelaDeTempoDeJ(IloEnv env,
		IloArray<IloArray<IloBoolVarArray> > x, const IloModel& modelo,
		Dados* d, int T) {

//restricao que garante que uma ativaida j so pode ter o tempo de inicio 0 do modo i
	for (int j = 1; j < d->j - 1; j++) {
		for (int i = 0; i < d->M[j]; i++) {
			IloExpr TIMJI(env);
			for (int t = 0; t < d->d[j][i]; t++) {
				TIMJI += x[j][i][t];
			}
			modelo.add(TIMJI == 0);
		}
	}

}

void restricaoDePrecedencia(IloEnv env, int T,
		IloArray<IloArray<IloBoolVarArray> > x, const IloModel& modelo,
		Dados* d) {
//segunda restricao
//garante que as restricoes de precedencias sao obedecidas
//ou seja, uma atividade j so inicia (t) quando todas suas predecessoras h (t + dhi ) tiverem terminado
//(t + dhi ) >= t-dj
	for (int j = 0; j < d->j; j++) {
		IloExpr Tij(env);
		for (int i = 0; i < d->M[j]; i++) {
			for (int t = 0; t < T; t++) {
				Tij += x[j][i][t] * (t - d->d[j][i]);
				//Tij += x[j][i][t];
			}
		}
		list<int>::iterator h;
		for (h = d->H[j].begin(); h != d->H[j].end(); h++) {
			//	cout << *h <<" -> "<< j << endl;
			IloExpr Tfh(env);
			for (int i = 0; i < d->M[*h]; i++) {
				for (int t = 0; t < T; t++) {
					Tfh += x[*h][i][t] * t;
					//Tfh += x[*h][i][t] * (t - d->d[*h][i]);
				}
			}
			modelo.add(Tfh <= Tij);
		}
	}

}

Solucao* OptimizeCplex(Dados *d) {

	try {

		IloEnv env;

		// Criando um modelo
		IloModel modelo(env);

		int T = d->D + 1; // prazo para o makespan
		cout << T << endl;

		//variaveis de desisao

		//xjit se a atividade j e executada no pode i e inicia no tempo t
		IloArray<IloArray<IloBoolVarArray> > x(env, d->j);

		for (int j = 0; j < d->j; j++) {
			IloArray<IloBoolVarArray> matriz(env, d->M[j]);
			x[j] = matriz;
			for (int i = 0; i < d->M[j]; i++) {
				IloBoolVarArray vetor(env, T);
				x[j][i] = vetor;
			}
		}

		//add variavel x no modelo
		char var[100];
		for (int j = 0; j < d->j; j++) {
			for (int i = 0; i < d->M[j]; i++) {
				for (int t = 0; t < T; t++) {
					sprintf(var, "x(%d,%d,%d)", j, i, t);
					x[j][i][t].setName(var);
					modelo.add(x[j][i][t]);
				}
			}
		}

		//ak quantidade de recurso do tipo k disponivel ao longo do projeto
		IloNumVarArray a(env, d->tipos, 0, IloInfinity, ILOINT);

		//add varialve a no modelo
		for (int k = 0; k < d->tipos; k++) {
			sprintf(var, "a(%d)", k);
			a[k].setName(var);
			modelo.add(a[k]);
		}

		/*adicionando variavel de medicao de ak no modelo*/

		//funcao objetivo FO
		IloExpr FO(env);

		for (int k = 0; k < d->tipos; k++) {
			FO += a[k] * d->custo_recurso[k];
		}

		//add FO no modelo
		modelo.add(IloMinimize(env, FO));

		// Restricoes

		//primeira restricao
		//cada atividade j é executada apenas uma vez em apenas um modo de execucao

		for (int j = 0; j < d->j; j++) {

			IloExpr sum(env);
			for (int i = 0; i < d->M[j]; i++) {
				for (int t = 0; t < T; t++) {
					sum += x[j][i][t];
				}
			}
			modelo.add(sum == 1);
		}

		//restricao que garante que uma ativaida j so pode ter o tempo de inicio 0 do modo i
		restricaoJanelaDeTempoDeJ(env, x, modelo, d, T);

		//segunda restricao
		//garante que as restricoes de precedencias sao obedecidas
		//ou seja, uma atividade j so inicia (t) quando todas suas predecessoras h (t + dhi ) tiverem terminado
		//(t + dhi ) >= t-dj
		restricaoDePrecedencia(env, T, x, modelo, d);

		//mostrar que o recurso é renovavel

		//terceira restricao
		//garante que durante a execucao da atividade a quantidade ak nao será exedida
		//restricaoCusto(T, env, x, modelo, a, d);

		restricaoCusto(T, env, x, modelo, a, d);

		//Executa o modelo
		IloCplex PCDRMM(modelo);
		PCDRMM.exportModel("PCDRMM.lp");

		//PCDRMM.setOut(env.getNullStream());

		PCDRMM.solve();

		cout << PCDRMM.getObjValue() << endl;

		for (int k = 0; k < d->tipos; k++) {
			cout << PCDRMM.getValue(a[k]) << " | ";
		}
		cout << endl << endl;
		//preencher solucao com resposta
		Solucao *s = new Solucao(d);

		for (int j = 0; j < d->j; j++) {
			for (int i = 0; i < d->M[j]; i++) {
				for (int t = 0; t < T; t++) {
					if (PCDRMM.getValue(x[j][i][t]) > 0.99) {//a atividade j foi executada no modo i e termina no tempo t?

						s->alocarAtividade(j, t - d->d[j][i], i);
						//s->alocarAtividade(j, t, i);

					}
				}
			}
		}
		s->atualizarDemanda(0, s->calcular_tempo());
		s->calcular_custo();

		env.end();

		return s;

	} catch (IloException & e) {
		cerr << "Erro : " << e << endl;
		return NULL;
	}

}
