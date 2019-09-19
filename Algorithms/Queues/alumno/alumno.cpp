//Beatriz Herguedas Pinedo

#include "deque_eda.h"

bool resuelveCaso() {
	int num, salta;
	deque<int> cola;

	cin >> num >> salta;

	if (num == 0 && salta == 0)
		return false;

	for (int i = 1; i <= num; i++) {
		cola.push_back(i);
	}

	cola.jugar(salta);
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
