//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool balanceado(int & peso) {
	int pi, pd, di, dd, aux;
	bool b;

	cin >> pi >> di >> pd >> dd;

	if (pi != 0 && pd != 0) {
		peso += pi + pd;
	    b = pi * di == pd * dd;
	}

	else if (pi == 0 && pd != 0) {
		aux = 0;
		b = balanceado(aux) && aux * di == pd * dd;
		peso += pd + aux;
	}

	else if (pi != 0 && pd == 0) {
		aux = 0;
		b = balanceado(aux) && pi * di == aux * dd;
		peso += pi + aux;
	}

	else {
		aux = 0;
		bool bizq = balanceado(aux);
		pi = aux;
		aux = 0;
		bool bdcha = balanceado(aux);
		pd = aux;
		b = bizq && bdcha && pi * di == pd * dd;
		peso = pi + pd;
	}
	
	return b;
}

void resuelveCaso() {

	int peso;

	if (balanceado(peso))
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
