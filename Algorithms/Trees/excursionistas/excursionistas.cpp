//Beatriz Herguedas Pinedo

#include "bintree_eda.h"

void rescate(bintree<int> const& arbol, int &equipos, int &atrapados, bool &rescatado) {

	if (arbol.empty()) {
		equipos = 0;
		atrapados = 0;
		rescatado = false;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {

		if (arbol.root() != 0) {
			equipos = 1;
			atrapados = arbol.root();
			rescatado = true;
		}

		else {
			equipos = 0;
			atrapados = 0;
			rescatado = false;
		}
	}

	else if (arbol.left().empty()) {

		int equiposright, atrapadosright;
		bool rescatadoright;

		rescate(arbol.right(), equiposright, atrapadosright, rescatadoright);

		if (arbol.root() != 0 && !rescatadoright) {
			equipos = equiposright + 1;
			atrapados = atrapadosright + arbol.root();
			rescatado = true;
		}

		else if (arbol.root() != 0 && rescatadoright) {
			equipos = equiposright;
			atrapados = atrapadosright + arbol.root();
			rescatado = rescatadoright;
		}

		else {
			equipos = equiposright;
			atrapados = atrapadosright;
			rescatado = rescatadoright;
		}
	}

	else if (arbol.right().empty()) {

		int equiposleft, atrapadosleft;
		bool rescatadoleft;

		rescate(arbol.left(), equiposleft, atrapadosleft, rescatadoleft);

		if (arbol.root() != 0 && !rescatadoleft) {
			equipos = equiposleft + 1;
			atrapados = atrapadosleft + arbol.root();
			rescatado = true;
		}

		else if (arbol.root() != 0 && rescatadoleft) {
			equipos = equiposleft;
			atrapados = atrapadosleft + arbol.root();
			rescatado = rescatadoleft;
		}

		else {
			equipos = equiposleft;
			atrapados = atrapadosleft;
			rescatado = rescatadoleft;
		}
	}

	else {
		int equiposright, equiposleft, atrapadosright, atrapadosleft;
		bool rescatadoright, rescatadoleft;

		rescate(arbol.left(), equiposleft, atrapadosleft, rescatadoleft);
		rescate(arbol.right(), equiposright, atrapadosright, rescatadoright);

		bool r = rescatadoleft || rescatadoright;

		if (arbol.root() != 0 && !r) {
			equipos = equiposright + equiposleft + 1;
			atrapados = max(atrapadosright, atrapadosleft) + arbol.root();
			rescatado = true;
		}

		else if (arbol.root() != 0 && r) {
			equipos = equiposright + equiposleft;
			atrapados = max(atrapadosright, atrapadosleft) + arbol.root();
			rescatado = r;
		}

		else {
			equipos = equiposright + equiposleft;
			atrapados = max(atrapadosright, atrapadosleft);
			rescatado = r;
		}
	}
}

void resuelveCaso() {
	bintree<int> arbol;
	int equipos, atrapados;
	bool rescatado;

	arbol = leerArbol(-1);

	rescate(arbol, equipos, atrapados, rescatado);

	cout << equipos << ' ' << atrapados << '\n';
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
