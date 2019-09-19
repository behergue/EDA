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

void genealogico(bintree<int> const &arbol, int &altura, bool &gen) {

	if (arbol.empty()) {
		altura = 0;
		gen = true;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		altura = 1;
		gen = true;
	}

	else if (arbol.left().empty()) {

		int alturaright;
		bool genright;

		genealogico(arbol.right(), alturaright, genright);
		altura = alturaright + 1;

		gen = false;
	}

	else if (arbol.right().empty()) {

		int alturaleft;
		bool genleft;

		genealogico(arbol.left(), alturaleft, genleft);
		altura = alturaleft + 1;

		gen = ((arbol.root() >= arbol.left().root() + 18) && genleft);
	}

	else {
		int alturaleft, alturaright;
		bool genright, genleft;

		genealogico(arbol.left(), alturaleft, genleft);
		genealogico(arbol.right(), alturaright, genright);

		altura = max(alturaleft, alturaright) + 1;

		gen = ((arbol.root() >= arbol.left().root() + 18) &&
			(arbol.left().root() >= arbol.right().root() + 2) && genleft && genright);
	}
}

void resuelveCaso() {
	bintree<int> arbol;
	int altura;
	bool gen;

	arbol = leerArbol(-1);

	genealogico(arbol, altura, gen);

	if (gen)
		cout << "SI " << altura << '\n';

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