//Beatriz Herguedas Pinedo, DG209

#include "set_eda.h"

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


bool resuelveCaso() {
	int N, M, valor;
	set<int> conjunto;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		conjunto.insert(valor);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> valor;

		bool exist;
		int sol;
		conjunto.lower_bound(valor, exist, sol);

		if (exist)
			cout << sol << '\n';

		else
			cout << "NO HAY\n";
	}

	cout << "---\n";

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