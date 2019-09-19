//Beatriz Herguedas Pinedo, DG209

#include "bintree_eda.h"

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void zurdo(bintree<char> const &arbol, bool &zur, int &nelems) {

	if (arbol.empty()) {
		zur = true;
		nelems = 0;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		zur = true;
		nelems = 1;
	}

	else if (arbol.left().empty()) {
		bool zurright;
		int nelemsright;

		zurdo(arbol.right(), zurright, nelemsright);

		nelems = nelemsright + 1;

		zur = false;
	}

	else if (arbol.right().empty()) {
		bool zurleft;
		int nelemsleft;

		zurdo(arbol.left(), zurleft, nelemsleft);

		nelems = nelemsleft + 1;

		zur = zurleft;
	}

	else {
		bool zurright, zurleft;
		int nelemsleft, nelemsright;

		zurdo(arbol.right(), zurright, nelemsright);
		zurdo(arbol.left(), zurleft, nelemsleft);

		nelems = nelemsright + nelemsleft + 1;

		zur = (zurright && zurleft && nelemsleft > (nelems - 1)/ 2);
	}
}


void resuelveCaso() {
	bintree<char> arbol;
	int nelems;
	bool zur;

	arbol = leerArbol('.');

	zurdo(arbol, zur, nelems);

	if (zur)
		cout << "SI\n";

	else
		cout << "NO\n";
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}