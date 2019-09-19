//Beatriz Herguedas Pinedo

#include "bintree_eda.h"


void diametro(bintree<char> const &arbol, int &sol, int &altura) {

	if (arbol.empty()) {
		sol = 0;
		altura = 0;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		sol = 1;
		altura = 1;
	}

	else  if (arbol.left().empty()) {
		int altd, sold;
		diametro(arbol.right(), sold, altd);
		altura = altd + 1;
		sol = max(sold, altura);
	}

	else if (arbol.right().empty()) {
		int alti, soli;
		diametro(arbol.left(), soli, alti);
		altura = alti + 1;
		sol = max(soli, altura);
	}

	else {
	
		int altd, alti, sold, soli;
		diametro(arbol.right(), sold, altd);
		diametro(arbol.left(), soli, alti);
		altura = max(altd, alti) + 1;
		sol = max(altd + alti + 1, max(sold, soli));
	}
}

void resuelveCaso() {
	bintree<char> arbol;
	int d, m, sol, altura;

	arbol = leerArbol('.');

	diametro(arbol, sol, altura);

	cout << sol << '\n';
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
