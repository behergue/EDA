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

int precarios(int k, int num) {

	int n;

	cin >> n;

	// si es un becario pero no precario
	if (n == 0 && num < k)
		return 0;

	// si es un becario precario
	else if (n == 0 && num >= k)
		return 1;

	// si no es un becario
	else {
		int aux = 0;
		for (int i = 0; i < n; i++) {
			aux += precarios(k, num + 1);
		}
		return aux;
	}
}

bool resuelveCaso() {
	int k;

	cin >> k;

	if (!std::cin)
		return false;

	cout << precarios(k, 0) << '\n';

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