//Beatriz Herguedas Pinedo

#include "bintree_eda.h"

void resuelveCaso() {

	bintree<int> arbol;
	vector<int> v;

	arbol = leerArbol(-1);

	arbol.frontera(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];

		if (i < v.size() - 1)
			cout << ' ';
	}

	cout << '\n';
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
