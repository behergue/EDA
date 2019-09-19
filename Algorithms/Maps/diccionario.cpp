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
#include <sstream>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void resuelveCaso() {
	int num;
	string palabra, l1, l2;
	map<string, int> antiguo, nuevo;
	vector<string> anadidos, modificados, eliminados;

	stringstream ss;

	getline(cin, l1);

	ss << l1;

	while (ss >> palabra >> num) {
		antiguo.insert({ palabra, num });
	}

	getline(cin, l2);

	ss.clear();
	ss << l2;

	while (ss >> palabra >> num) {
		nuevo.insert({ palabra, num });
	}

	if (!antiguo.empty()) {
		for (auto a : antiguo) {

			auto it = nuevo.find(a.first);

			if (it == nuevo.end()) {
				eliminados.push_back(a.first);
			}

			else if (a.second != it->second) {
				modificados.push_back(a.first);
			}
		}
	}

	if (!nuevo.empty()) {
		for (auto n : nuevo) {

			auto it = antiguo.find(n.first);

			if (it == antiguo.end()) {
				anadidos.push_back(n.first);
			}
		}
	}

	if (anadidos.empty() && modificados.empty() && eliminados.empty()) {
		cout << "Sin cambios\n";
	}

	else {

		if (!anadidos.empty()) {

			cout << "+ ";

			for (int i = 0; i < anadidos.size(); i++) {
				cout << anadidos[i];

				if (i < anadidos.size() - 1)
					cout << " ";
			}

			cout << '\n';
		}

		if (!eliminados.empty()) {

			cout << "- ";

			for (int i = 0; i < eliminados.size(); i++) {
				cout << eliminados[i];

				if (i < eliminados.size() - 1)
					cout << " ";
			}

			cout << '\n';
		}

		if (!modificados.empty()) {

			cout << "* ";

			for (int i = 0; i < modificados.size(); i++) {
				cout << modificados[i];

				if (i < modificados.size() - 1)
					cout << " ";
			}

			cout << '\n';
		}
	}

	cout << "----\n";
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	string aux;
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	getline(cin, aux);
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}
