// Beatriz Herguedas Pinedo

// comentario sobre la solución y su coste

// la solucion tiene coste lineal

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#include "bintree_eda.h"

// aquí tu función o funciones
void calculaMayorCompleto(bintree<char> const &arbol, int &altura, int &maxaltura) {

	if (arbol.empty()) {
		altura = 0;
		maxaltura = 0;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		altura = 0;
		maxaltura = 1;
	}

	else if (arbol.left().empty()) {
		int alturaright, maxalturaright;
		bool doshijosright;

		calculaMayorCompleto(arbol.right(), alturaright, maxalturaright);

		maxaltura = maxalturaright;
		altura = 0;
	}

	else if (arbol.right().empty()) {
		int alturaleft, maxalturaleft;
		bool doshijosleft;

		calculaMayorCompleto(arbol.left(), alturaleft, maxalturaleft);

		maxaltura = maxalturaleft;
		altura = 0;
	}

	else {

		int alturaright, maxalturaright, alturaleft, maxalturaleft;

		calculaMayorCompleto(arbol.right(), alturaright, maxalturaright);
		calculaMayorCompleto(arbol.left(), alturaleft, maxalturaleft);

		//si el nodo tiene dos hijos y sus descendientes tb
		if (alturaleft != 0 && alturaright != 0)
			altura = min(alturaleft, alturaright) + 1;

		//si el nodo tiene dos hijos pero sus descendientes no
		else
			altura = 2;

		maxaltura = max(max(maxalturaleft, maxalturaright), altura);
	}
}

int subarbolMayor(bintree<char> const &arbol) {
	int maxaltura, altura;

	calculaMayorCompleto(arbol, altura, maxaltura);

	return maxaltura;
}

void resuelveCaso() {
	auto arbol = leerArbol('.');
	cout << subarbolMayor(arbol) << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
