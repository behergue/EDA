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

void aminusculas(string &palabra) {
	
	for (int i = 0; i < palabra.size(); i++) {
		if (isupper(palabra[i])) {
			palabra[i] = tolower(palabra[i]);
		}
	}
}

bool resuelveCaso() {
	int N;
	vector<int> v;
	string linea, palabra, aux;
	map<string, vector<int>> mapa;

	cin >> N;

	if (N == 0)
		return false;

	stringstream ss;
	getline(cin, aux);

	for (int i = 1; i < N + 1; i++) {

		v.push_back(i);
		getline(cin, linea);
		ss.clear();
		ss << linea;

		while (ss >> palabra) {
			aminusculas(palabra);

			if (palabra.size() > 2) {

				auto it = mapa.find(palabra);

				if (it == mapa.end()) {

					mapa.insert({ palabra, v });
				}

				else if (!binary_search(it->second.begin(), it->second.end(), i)) {
					it->second.push_back(i);
				}
			}
		}

		v.clear();
	}

	for (auto i : mapa) {
		cout << i.first;

		for (int j = 0; j < i.second.size(); j++) {
			cout << " " << i.second[j];
		}

		cout << '\n';
	}

	cout << "----\n";

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
