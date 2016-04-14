/*
 * Arquivo.cpp
 *
 *  Created on: 18/11/2014
 *      Author: Leo
 */

#include "Arquivo.h"

#include <dirent.h>
#include <sys/dirent.h>
#include <list>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

void Arquivo::instancia_denise(int numero, const string& nomeArquivo) {

	this->numeroInstacia = numero;
	stringstream ss;
	ss << nomeArquivo << "/a10" << numero << "_1";
	this->nomeArquivo = ss.str();
	//cout << "vai abrir o aquivo "<< this->nomeArquivo + ".dat"<<endl;

	this->dados.open((this->nomeArquivo + ".dat").c_str(), ios::in);
	this->funcao.open((this->nomeArquivo + ".tx2").c_str(), ios::in);
	if (!(this->dados.is_open())) {
		cout << "arquivo nao pode ser aberto" << endl;
	}
}

void Arquivo::instancia_PSPLIB(int indice, vector<string> arq, const string& nomeArquivo) {
	stringstream ss;
	ss << nomeArquivo << "/" << arq[indice];
	this->nomeArquivo = ss.str();
	this->dados.open((this->nomeArquivo).c_str(), ios::in);

	if (!(this->dados.is_open())) {
		cout << "arquivo "<< nomeArquivo << " nao pode ser aberto" << endl;
	}else{
		cout <<nomeArquivo << "/" << arq[indice]<< endl;

	}
}

Arquivo::Arquivo(string nomeArquivo, int numero) {
	if(nomeArquivo.compare("Instancias_Denise") == 0){
		instancia_denise(numero, nomeArquivo);
	}else{
		vector<string> arq = arquivosInstancias(&nomeArquivo);
		instancia_PSPLIB(numero, arq, nomeArquivo);
	}
}


Dados * Arquivo::lerInstancia() {
	Dados * d;
	string linha;
	string c; // cache de palavras nao utilizadas
	int contline = 1;

	while (!this->dados.fail()) {
		int tipos;
		getline(this->dados, linha);
		contline++;

		switch (contline) {
		case 9: {
			this->dados >> c >> c >> c;

			this->dados >> tipos;
			break;
		}
		case 16: {
			int j, D;
			this->dados >> c;
			this->dados >> j;
			j += 2; //atividades virtuais

			this->dados >> c;
			this->dados >> D;
			d = new Dados(tipos, j, D);
			break;
		}
		case 20: {
			for (int j = 0; j < d->j; j++, contline++) {
				this->dados >> c;
				this->dados >> d->M[j];
				int sj = 0; // quantidade de sucessores que j tem
				this->dados >> sj;

				for (int qs = 0; qs < sj; qs++) {
					int s;
					this->dados >> s;
					d->H[s - 1].push_back(j);
					d->S[j].push_back(s - 1);
					d->G[j].insert(s - 1);
				}

				getline(this->dados, linha);
			}

			for (int j = 0; j < d->j; ++j) {
				d->d[j] = vector<int>(d->M[j]); // quantidade de modos das atividades
			}
			for (int j = 0; j < d->j; ++j) {
				d->r[j] = vector<vector<int> >(d->M[j]);
				for (int i = 0; i < d->M[j]; ++i) {
					d->r[j][i] = vector<int>(d->tipos);
				}
			}
			break;
		}
		case 35: {
			for (int j = 0; j < d->j; j++) {
				for (int i = 0; i < d->M[j]; ++i) {
					if (i == 0) { // toda primeira linha tem um nuermo a mais
						this->dados >> c;
					}
					this->dados >> c;
					this->dados >> d->d[j][i];
					for (int k = 0; k < d->tipos; ++k) {

						this->dados >> d->r[j][i][k];
					}

					getline(this->dados, linha);
				}
			}

			contline = 67;
			break;
		}
		case 70: {

			for (int k = 0; k < d->tipos; ++k) {
				this->dados >> d->disponibilidade[k];
			}
			break;
		}

		} //fim do case

	} // fim do while final de leitura do arquivo

	contline = 1;

	while (!this->funcao.fail()) {
		contline++;
		getline(this->funcao, linha);
		if (contline == 16) {
			for (int k = 0; k < d->tipos; ++k) {
				this->funcao >> d->custo_recurso[k];
			}
		}
	}

	d->numeroInstacia = this->numeroInstacia;
	return d;
}


Dados * Arquivo::lerInstanciaPSPLIB() {
	Dados * d;
	//?? acredito o erro esta na linha abaixo
	//d->arquivo = &nomeArquivo;

	string linha;
	string c; // cache de palavras nao utilizadas
	int contline = 1;
	int d_j = 12;

	while (!this->dados.fail()) {
		int tipos;
		getline(this->dados, linha);
		contline++;

		switch (contline) {
		case 9: {
			this->dados >> c >> c >> c;

			this->dados >> tipos;
			break;
		}
		case 10: { //Tipo nao renovável
			this->dados >> c >> c >> c;
			int nonrenewable;
			this->dados >> nonrenewable;
			tipos += nonrenewable;
			break;
		}
		case 15: {
			int j, D;
			this->dados >> c;
			this->dados >> j;
			j += 2; //atividades virtuais

			this->dados >> c;
			this->dados >> D;
			d = new Dados(tipos, j, D);
			d_j = j;
			break;
		}
		case 19: {
			for (int j = 0; j < d->j; j++, contline++) {
				this->dados >> c;
				this->dados >> d->M[j];
				int sj = 0; // quantidade de sucessores que j tem
				this->dados >> sj;

				for (int qs = 0; qs < sj; qs++) {
					int s;
					this->dados >> s;
					d->H[s - 1].push_back(j);
					d->S[j].push_back(s - 1);
					d->G[j].insert(s - 1);
				}

				getline(this->dados, linha);
			}

			for (int j = 0; j < d->j; ++j) {
				d->d[j] = vector<int>(d->M[j]); // quantidade de modos das atividades
			}
			for (int j = 0; j < d->j; ++j) {
				d->r[j] = vector<vector<int> >(d->M[j]);
				for (int i = 0; i < d->M[j]; ++i) {
					d->r[j][i] = vector<int>(d->tipos);
				}
			}
			break;
		}
		default: {
			if (contline == 19+d_j+4) {
				for (int j = 0; j < d->j; j++) {
					for (int i = 0; i < d->M[j]; ++i) {
						if (i == 0) { // toda primeira linha tem um nuermo a mais
							this->dados >> c;
						}
						this->dados >> c;
						this->dados >> d->d[j][i];
						for (int k = 0; k < d->tipos; ++k) {

							this->dados >> d->r[j][i][k];
						}

						getline(this->dados, linha);
						contline++;
					}

				}

				getline(this->dados, linha);
				getline(this->dados, linha);
				getline(this->dados, linha);
				getline(this->dados, linha);
				for (int k = 0; k < d->tipos; ++k) {
					this->dados >> d->disponibilidade[k];
				}


			}
			break;
		}

		} //fim do case

	} // fim do while final de leitura do arquivo

	contline = 1;

	while (!this->funcao.fail()) {
		contline++;
		getline(this->funcao, linha);
		if (contline == 16) {
			for (int k = 0; k < d->tipos; ++k) {
				this->funcao >> d->custo_recurso[k];
			}
		}
	}

	d->numeroInstacia = this->numeroInstacia;
	d->criarCustos();
	return d;
}

vector<string> Arquivo::arquivosInstancias(string *url) {
	struct dirent *dp;
	DIR *dir;

	vector<string> arquivos;

	dir = opendir(url->c_str());
	if (dir == NULL) {
		cout << *url<< endl;
		perror("Erro ao abrir diretorio");
		return arquivos;
	}


	/* Loop atraves da entrada do diretorio */
	while (dp = readdir(dir)) {
		/* Obter informaçoes de entrada */
		stringstream ss;

		if (dp->d_namlen >= 10 ) {
			ss<<dp->d_name;
			arquivos.push_back(ss.str());
		}
	}

	return arquivos;
}


void Arquivo::salvarResposta(int index_instance, float custo, int tempo, float tempo_de_execucao){
	char url[]="heuristica_repostas.txt";
	stringstream ss;
	ss << index_instance <<"\t"<< custo << "\t" << tempo<<"\t\t\t" <<tempo_de_execucao << "\n";
	char cr;

		FILE *arq;
		arq = fopen(url, "a");


		if(arq == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
		}else{

			fprintf(arq, ss.str().c_str());

			fclose(arq);
		}
}


void Arquivo::gravarSolucao(int instancia, Solucao *s) {

}

Arquivo::~Arquivo() {
	this->dados.close();
	this->funcao.close();
}

