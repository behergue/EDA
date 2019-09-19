//Beatriz Herguedas Pinedo, DG209

#include "queue_eda.h"

bool resuelveCaso() {
	int valor;
	queue<int> cola;

	cin >> valor;

	if (!std::cin)
		return false;

	while (valor != 0) {
		cola.push(valor);
		cin >> valor;
	}

	cola.invertir();
	cola.mostrar();

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