//Beatriz Herguedas Pinedo, DG209

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


struct tElem {
	int elem;
	int pos;
};

bool resuelveCaso() {
	int n, k, valor;
	deque <tElem> cola, maxcandidatos;
	tElem max = { 0, -1 };

	cin >> n >> k;

	if (n == 0 && k == 0)
		return false;

	for (int i = 0; i < k; i++) {
		cin >> valor;

		if (valor > max.elem)
			max = { valor, i };

		cola.push_back({ valor, i });
	}

	deque <tElem> aux = cola;

	int cont = 0;
	while (!aux.empty()) {

		if (aux.back().elem > cont && aux.back().pos != max.pos) {

			cont = aux.back().elem;
			maxcandidatos.push_back(aux.back());

		}
		aux.pop_back();
	}

	cout << max.elem;

	if (k < n)
		cout << " ";

	for (int i = k; i < n; i++) {

		cin >> valor;

		if (!maxcandidatos.empty() && maxcandidatos.back().pos == cola.front().pos)
			maxcandidatos.pop_back();

		if (cola.front().elem == max.elem) {

			if (!maxcandidatos.empty()) {
				max = maxcandidatos.back();
				maxcandidatos.pop_back();
			}

			else {
				max = { valor, i };
			}
		}

		cola.pop_front();

		if (valor > max.elem) {
			max = { valor, i };

			if (!maxcandidatos.empty())
				maxcandidatos.clear();
		}

		else {
			if (maxcandidatos.empty())
				maxcandidatos.push_back({ valor, i });

			else {

				if (valor >= maxcandidatos.front().elem) {
					while (!maxcandidatos.empty() && valor >= maxcandidatos.front().elem)
						maxcandidatos.pop_front();
				}

				maxcandidatos.push_front({ valor, i });
			}
		}

		cola.push_back({ valor, i });

		cout << max.elem;

		if (i < n - 1)
			cout << " ";
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