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

	int i = 1;
	cout <<"instancia "<< i << endl;

	string instancia = "Instancias_Denise";
	Arquivo arq(instancia, i);
	Dados *d = arq.lerInstancia();

//	d->print();

	Solucao *s = OptimizeCplex(d);

	s->print();

	return EXIT_SUCCESS;
}

Solucao* OptimizeCplex(Dados *d) {

	try {

		IloEnv env;

		// Criando um modelo
		IloModel modelo(env);

		int T = d->D + 1; // prazo para o makespan

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

		//funcao objetivo FO
		IloExpr FO(env);

		for (int k = 0; k < d->tipos; k++) {
			FO += a[k] * d->custo_recurso[k];
		}

		/*for (int j = 0; j < d->j; j++) {
		 for (int i = 0; i < d->M[j]; i++) {
		 for (int t = 0; t < T; t++) {
		 FO += x[j][i][t] * t;
		 }
		 }
		 }*/

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
		for (int j = 1; j < d->j - 1; j++) {

			for (int i = 0; i < d->M[j]; i++) {
				IloExpr TIMJI(env);
				for (int t = 0; t < d->d[j][i]; t++) {
					TIMJI += x[j][i][t];
				}
				modelo.add(TIMJI == 0);
			}

		}

		//segunda restricao
		//garante que as restricoes de precedencias sao obedecidas
		//ou seja, uma atividade j so inicia (t) quando todas suas predecessoras h (t + dhi ) tiverem terminado
		//(t + dhi ) >= t-dj
		for (int j = 0; j < d->j; j++) {

			IloExpr Tij(env);
			for (int i = 0; i < d->M[j]; i++) {
				for (int t = 0; t < T; t++) {

					Tij += x[j][i][t] * (t - d->d[j][i]);

				}
			}

			list<int>::iterator h;
			for (h = d->H[j].begin(); h != d->H[j].end(); h++) {
				//	cout << *h <<" -> "<< j << endl;
				IloExpr Tfh(env);
				for (int i = 0; i < d->M[*h]; i++) {
					for (int t = 0; t < T; t++) {
						Tfh += x[*h][i][t] * t;

					}
				}
				modelo.add(Tfh <= Tij);
			}

		}
		//mostrar que o recurso é renovavel

		//terceira restricao
		//garante que durante a execucao da atividade a quantidade ak nao será exedida
		for (int k = 0; k < d->tipos; k++) {
			IloExpr sum(env);
			for (int t = 0; t < T; t++) {

				for (int j = 0; j < d->j; j++) {

					for (int i = 0; i < d->M[j]; i++) {

						sum += d->r[j][i][k] * x[j][i][t];
					}
				}
			}
			modelo.add(sum <= a[k]);

		}

		//Executa o modelo
		IloCplex PCDRMM(modelo);
		PCDRMM.exportModel("PCDRMM.lp");
		PCDRMM.solve();

		cout << PCDRMM.getObjValue() << endl;
		cout << endl;

		//preencher solucao com resposta
		Solucao *s = new Solucao(d);

		for (int j = 0; j < d->j; j++) {
			for (int i = 0; i < d->M[j]; i++) {
				for (int t = 0; t < T; t++) {
					if (PCDRMM.getValue(x[j][i][t]) > 0.99) {//a atividade j foi executada no modo i e termina no tempo t?

						s->alocarAtividade(j, t - d->d[j][i], i);

					}
				}
			}
		}

		env.end();

		return s;

	} catch (IloException & e) {
		cerr << "Erro : " << e << endl;
	}

}
