//Beatriz Herguedas Pinedo

#include "bintree_eda.h"

bool esPrimo(int n) {

	bool primo = true;
	int i = 2;
	while (primo && i < n) {

		if (n % i == 0)
			primo = false;

		i++;
	}

	return primo;
}

bool multiploN(int N, int num) {

	if (num % N == 0)
		return true;

	return false;
}

void buscando(bintree<int> const &arbol, int &sol, int &profundidad, bool &haysol, int profActual) {

	if (arbol.empty()) {
		haysol = false;
	}

	else if (esPrimo(arbol.root())) {
		haysol = false;
	}

	else if (multiploN(7, arbol.root())) {
		sol = arbol.root();
		profundidad = profActual;
		haysol = true;
	}

	else {

		int solleft, solright, profleft, profright;
		bool haysolleft, haysolright;

		buscando(arbol.left(), solleft, profleft, haysolleft, profActual + 1);
		buscando(arbol.right(), solright, profright, haysolright, profActual + 1);

		if (haysolleft && haysolright) {
			haysol = true;

			if (profleft <= profright) {
				sol = solleft;
				profundidad = profleft;
			}

			else {
				sol = solright;
				profundidad = profright;
			}
		}

		else if(haysolleft) {
			haysol = true;
			sol = solleft;
			profundidad = profleft;
		}

		else if (haysolright) {
			haysol = true;
			sol = solright;
			profundidad = profright;
		}

		else {
			haysol = false;
		}
	}
}

void resuelveCaso() {
	bintree<int> arbol;
	int profundidad, sol;
	bool haysol;

	arbol = leerArbol(-1);

	buscando(arbol, sol, profundidad, haysol, 1);

	if (haysol)
		cout << sol << ' ' << profundidad << '\n';

	else
		cout << "NO HAY\n";
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
