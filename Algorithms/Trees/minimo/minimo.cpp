//Beatriz Herguedas Pinedo

#include "bintree_eda.h"

template <class T>
T minimo(bintree<T> const &arbol) {

	if (!arbol.empty()) {
		
		if (arbol.left().empty() && arbol.right().empty()) {
			return arbol.root();
		}

		else if (arbol.left().empty()) {
			return min(minimo(arbol.right()), arbol.root());
		}

		else if (arbol.right().empty()) {
			return min(minimo(arbol.left()), arbol.root());
		}

		else {
			T aux = min(minimo(arbol.left()), minimo(arbol.right()));
			return min(aux, arbol.root());
		}
	}
}

bool resuelveCaso() {
	char tipo;

	cin >> tipo;

	if (!std::cin)
		return false;


	if (tipo == 'N') {
		bintree<int> arbol;

		arbol = leerArbol(-1);

		cout << minimo(arbol) << '\n';
	}

	else if(tipo == 'P'){
		bintree<string> arbol;
		string aux = "#";

		arbol = leerArbol(aux);

		cout << minimo(arbol) << '\n';
	}

	return true;
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}
