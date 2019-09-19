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

bool esVocal(char c) {

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
		return true;

	return false;
}

bool resuelveCaso() {
	deque<char> cola1, cola2;
	stack<char> pila;
	string palabra;

	getline(cin, palabra);

	if (!std::cin)
		return false;

	int i = 0;

	for (auto c : palabra) {

		if (i % 2 == 0)
			cola1.push_back(c);

		else
			pila.push(c);

		i++;
	}

	while (!pila.empty()) {
		cola2.push_back(pila.top());
		pila.pop();
	}

	while(!cola2.empty()) {
		cola1.push_back(cola2.front());
		cola2.pop_front();
	}

	while (!cola1.empty()) {

		if (!esVocal(cola1.front())) {
			pila.push(cola1.front());
			cola1.pop_front();
		}

		else {
			while (!pila.empty()) {
				cola2.push_back(pila.top());
				pila.pop();
			}
			cola2.push_back(cola1.front());
			cola1.pop_front();
		}
	}

	while (!pila.empty()) {
		cola2.push_back(pila.top());
		pila.pop();
	}

	for (int i = 0; i < cola2.size(); i++) {
		cout << cola2[i];

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
