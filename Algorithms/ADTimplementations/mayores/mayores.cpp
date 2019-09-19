//Beatriz Herguedas Pinedo

#include "conjunto.h"

bool resuelveCaso() {
	char tipo;
	int k;

	cin >> tipo >> k;

	if (!std::cin)
		return false;

	if (tipo == 'N') {

		set<int> n;
		int valor, pos;

		cin >> valor;

		while (valor != -1) {

			if (n.size() < k) 
				n.insert(valor);
			
			else if (valor > n.consultaMenor() && !n.contains(valor, pos)) {
				n.eliminarMenor();
				n.insert(valor);
			}

			cin >> valor;
		}

		cout << n;

	}

	else {
		set<string> p;
		string valor;
		int pos;

		cin >> valor;

		while (valor != "FIN") {

			if (p.size() < k)
				p.insert(valor);

			else if (valor > p.consultaMenor() && !p.contains(valor, pos)) {
				p.eliminarMenor();
				p.insert(valor);
			}

			cin >> valor;
		}

		cout << p;
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