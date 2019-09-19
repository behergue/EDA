//Beatriz Herguedas Pinedo, DG209

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool siemprePremio(vector<int> const& v, int ini, int fin, int &minimo, int &maximo) {

	int indiceMax = ini;
	maximo = v[ini];
	minimo = v[ini];

	for (int i = ini + 1; i < fin; i++) {

		if (v[i] > maximo) {
			maximo = v[i];
			indiceMax = i;
		}

		if (v[i] < minimo) 
			minimo = v[i];
	}

	if (fin - ini < 3)
		return true;

	else {
		int maxDcha, maxIzq, minDcha, minIzq;

		if (ini == indiceMax)
			return siemprePremio(v, indiceMax + 1, fin, minDcha, minIzq);

		else if (fin == indiceMax + 1)
			return siemprePremio(v, ini, indiceMax, minIzq, maxIzq);

		else
			return siemprePremio(v, ini, indiceMax, minIzq, maxIzq) &&
			siemprePremio(v, indiceMax + 1, fin, minDcha, maxDcha) &&
			minIzq >= maxDcha;
	}
}

bool resuelveCaso() {
	int num, aux, aux2;
	vector<int> v;

	cin >> num;

	if (!std::cin)
		return false;

	for (int i = 0; i < num; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	if (siemprePremio(v, 0, num, aux, aux2))
		cout << "SIEMPRE PREMIO\n";

	else
		cout << "ELEGIR OTRA\n";

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