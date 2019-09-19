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

void aguaslimpias(bintree<int> const &arbol, int & caudal, int &navegables){

	if (arbol.empty()) {
		caudal = 0;
		navegables = 0;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		caudal = 1;
		navegables = 0;
	}

	else if (arbol.left().empty()) {
		int caudalright, navegablesright;

		aguaslimpias(arbol.right(), caudalright, navegablesright);

		caudal = max(caudalright - arbol.root(), 0);

		navegables = navegablesright;

		if (caudal >= 3)
			navegables++;
	}

	else if (arbol.right().empty()) {
		int caudalleft, navegablesleft;

		aguaslimpias(arbol.left(), caudalleft, navegablesleft);

		caudal = max(caudalleft - arbol.root(), 0);

		navegables = navegablesleft;

		if (caudal >= 3)
			navegables++;
	}

	else {
		int caudalleft, caudalright, navegablesleft, navegablesright;

		aguaslimpias(arbol.left(), caudalleft, navegablesleft);
		aguaslimpias(arbol.right(), caudalright, navegablesright);

		caudal = max(caudalleft + caudalright - arbol.root(), 0);

		navegables = navegablesleft + navegablesright;

		if (caudal >= 3)
			navegables++;
	}
}


void resuelveCaso() {
	bintree<int> arbol;
	int caudal1, caudal2, navegables1, navegables2;

	arbol = leerArbol(-1);

	aguaslimpias(arbol.left(), caudal1, navegables1);
	aguaslimpias(arbol.right(), caudal2, navegables2);

	cout << navegables1 + navegables2 << '\n';
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