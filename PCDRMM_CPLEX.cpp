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

void OptimizeCplex(Dados *d);

int main(int argc, char **argv) {

	int i = 1;

	string instancia = "Instancias_Denise";
	Arquivo arq(instancia, i);
	Dados *d = arq.lerInstancia();

	d->print();

	OptimizeCplex(d);

	cout << "FIM"<< endl;

	return EXIT_SUCCESS;
}




void OptimizeCplex(Dados *d)
{
	IloEnv env;

	// Criando um modelo

	IloModel modelo(env);

//-O0 -g3 -c -fmessage-length=0 -MMD -MP
	env.end();

}
