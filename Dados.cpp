/*
 * Dados.cpp
 *
 *  Created on: 25/11/2014
 *      Author: Leo
 */

#include "Dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Dados::Dados(int tipos, int j, int d) :
		tipos(tipos), j(j), D(d), M(j), S(j), H(j), r(j), d(j), custo_recurso(
				j), disponibilidade(tipos) {
}

void Dados::print() {
	cout << "J | D |Tipos" << endl;
	cout << j << " | " << D << " | " << tipos << endl;

	cout << "custos" << endl;
	for (int k = 0; k < tipos; k++) {
		cout << custo_recurso[k] << " | ";
	}
	cout << endl;

	cout << "Rjik" << endl;
	for (int j = 0; j < this->j; j++) {
		cout << j;
		for (int i = 0; i < this->M[j]; i++) {
			cout << "\t\t" << i << "\t\t";
			for (int k = 0; k < this->tipos; k++) {
				cout << r[j][i][k] << "\t";
			}
			cout << endl;
		}
	}

	cout << endl;

	cout << "Duracao" << endl;
	for (int j = 0; j < this->j; j++) {
		cout << j;
		for (int i = 0; i < this->M[j]; i++) {
			cout << "\t\t" << i << "\t " << this->d[j][i] << endl;
		}
	}

	cout << endl;

	cout << "Precedencia" << endl;
	for (int j = 0; j < this->j; j++) {
		cout << j << "\t\t{ ";
		for (list<int>::iterator it = this->H[j].begin();
				it != this->H[j].end(); it++) {
			cout << *it << ", ";
		}
		cout << " }" << endl;

	}

}

void Dados::criarCustos() {
	vector<int> uso_tipos(this->tipos, 0);
	for (int j = 0; j < this->j; j++) {
		for (int i = 0; i < this->M[j]; i++) {

			for (int k = 0; k < this->tipos; k++) {
				uso_tipos[k] += (r[j][i][k] * d[j][i]);

			}
		}
	}
	float max = 0;
	float min = INT_MAX;
	float total = 0;
	for (int k = 0; k < this->tipos; k++) {
		if (max < uso_tipos[k]) {
			max = uso_tipos[k];
		}

		if (min > uso_tipos[k]) {
			min = uso_tipos[k];
		}
		total += uso_tipos[k];

	}

	for (int k = 0; k < this->tipos; k++) {
		custo_recurso[k] = ((total - uso_tipos[k]) / max);
	}
}

Dados::~Dados() {
	/*
	 delete this->M;
	 delete this->S;
	 delete this->custo_recurso;
	 delete this->d;
	 delete this->disponibilidade;
	 delete this->r;
	 */
}

