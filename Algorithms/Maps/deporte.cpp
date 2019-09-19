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

bool orden(pair<string, int> p1, pair<string, int> p2) {
	return ((p1.second > p2.second) || p2.second == p1.second && p1.first < p2.first);
}

bool resuelveCaso() {
	string deporte, nombre;
	vector<pair<string, int>> v;
	unordered_map<string, int> deportes;
	unordered_map<string, pair<string, bool>> alumnos;


	getline(cin, deporte);

	if (!cin)
		return false;

	nombre = deporte;

	while (nombre != "_FIN_") {

		if (isupper(nombre.front())) {
			deportes.insert({ nombre, 0 });
			deporte = nombre;
		}

		else {
			auto it = alumnos.find(nombre);

			if (it == alumnos.end()) {
				alumnos.insert({ nombre, { deporte, true } });
			}

			else {
				if (it->second.first != deporte)
					it->second.second = false;
			}
		}

		getline(cin, nombre);
	}

	for (auto i : alumnos) {
		if (i.second.second) {
			auto it = deportes.find(i.second.first);
			it->second++;
		}
	}

	for (auto i : deportes) {
		v.push_back(i);
	}

	sort(v.begin(), v.end(), orden);

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	cout << "***\n";

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
