//Beatriz Herguedas Pinedo

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


void resuelveCaso() {
	int numcaps, cap;
	unordered_map<int, int> mapa;

	cin >> numcaps;

	int cont = 0;
	int maxi = 0;
	int ini = 0;

	for (int i = 0; i < numcaps; i++) {
		cin >> cap;

		auto it = mapa.find(cap);

		if (it == mapa.end()) {
			mapa.insert({ cap, i });
		}

		else {
			if (it->second >= ini) {
				ini = it->second;
				cont = i - it->second - 1;
			}

			it->second = i;
		}

		cont++;
		maxi = max(maxi, cont);
	}

	cout << maxi << '\n';

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
