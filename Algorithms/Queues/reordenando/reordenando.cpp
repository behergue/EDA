//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <iostream>
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
	int N, valor;
	queue<int> cola;
	queue<int> positivos;
	stack<int> negativos;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		if (valor <= 0)
			negativos.push(valor);
		else
			positivos.push(valor);
	}

	while (!negativos.empty()) {
		cola.push(negativos.top());
		negativos.pop();
	}

	while (!positivos.empty()) {
		cola.push(positivos.front());
		positivos.pop();
	}

	while (!cola.empty()) {
		cout << cola.front() << ' ';
		cola.pop();
	}

	cout << '\n';

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
