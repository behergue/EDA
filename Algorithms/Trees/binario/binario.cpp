//Beatriz Herguedas Pinedo

#include "bintree_eda.h"

using namespace std;

void binariodebusqueda(bintree<int> const &arbol, int &maximo, int &minimo, bool &esbinario) {

	if (arbol.empty()) {
		esbinario = true;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		maximo = arbol.root();
		minimo = arbol.root();
		esbinario = true;
	}

	else if (arbol.left().empty()) {
		int maxdcha, mindcha;
		bool bin;

		binariodebusqueda(arbol.right(), maxdcha, mindcha, bin);

		maximo = max(arbol.root(), maxdcha);
		minimo = min(arbol.root(), mindcha);

		if (mindcha > arbol.root() && bin)
			esbinario = true;

		else
			esbinario = false;
	}

	else if (arbol.right().empty()) {
		int maxizq, minizq;
		bool bin;

		binariodebusqueda(arbol.left(), maxizq, minizq, bin);

		maximo = max(arbol.root(), maxizq);
		minimo = min(arbol.root(), minizq);

		if (maxizq < arbol.root() && bin)
			esbinario = true;

		else
			esbinario = false;
	}

	else {
		int maxizq, maxdcha, minizq, mindcha;
		bool binizq, bindcha;

		binariodebusqueda(arbol.left(), maxizq, minizq, binizq);
		binariodebusqueda(arbol.right(), maxdcha, mindcha, bindcha);

		maximo = max(arbol.root(), max(maxizq, maxdcha));
		minimo = min(arbol.root(), min(minizq, mindcha));

		if (maxizq < arbol.root() && binizq && mindcha > arbol.root() && bindcha)
			esbinario = true;

		else
			esbinario = false;
	}
}

void resuelveCaso() {
	bintree<int> arbol;
	int maximo, minimo;
	bool esbin;
	
	arbol = leerArbol(-1);

	binariodebusqueda(arbol, maximo, minimo, esbin);

	if (esbin)
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
