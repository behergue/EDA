//Beatriz Herguedas Pinedo

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

bool simetrico(bintree<char> arbol1, bintree<char> arbol2) {

	if (arbol1.empty() && arbol2.empty())
		return true;

	else if (arbol1.empty() || arbol2.empty())
		return false;

	else
		return simetrico(arbol1.left(), arbol2.right()) && simetrico(arbol1.right(), arbol2.left());
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');

	if (arbol.empty() || simetrico(arbol.left(), arbol.right()))
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
