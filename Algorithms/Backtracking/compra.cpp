//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <climits>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void compra(int & pagar, int & minimo, vector<vector<int>> const &matriz, vector<int> prodmismosuper,
	bool &haysol, int col, int numProd, int numSuper, vector<int> &coste, int & suma) {

	for (int i = 0; i < numSuper; i++) {

		if (prodmismosuper[i] < 3) {

			prodmismosuper[i]++;
			pagar += matriz[i][col];
			suma -= coste[col];

			if (pagar + suma < minimo) {

				if (col == numProd - 1) {
					minimo = pagar;
					haysol = true;
				}

				else
					compra(pagar, minimo, matriz, prodmismosuper, haysol, col + 1, numProd, numSuper, coste, suma);
			}

			prodmismosuper[i]--;
			pagar -= matriz[i][col];
			suma += coste[col];
		}
	}
}

void resuelveCaso() {
	int numSuper, numProd, prod;
	vector<int> col;
	vector<vector<int>> matriz;

	cin >> numSuper >> numProd;

	vector<int> coste(numProd);
	vector<int> prodmismosuper(numSuper);

	for (int i = 0; i < numSuper; i++) {
		for (int j = 0; j < numProd; j++) {
			cin >> prod;
			col.push_back(prod);
		}
		matriz.push_back(col);
		col.clear();
	}

	int minimo = INT_MAX;
	int pagar = 0;
	bool haysol = false;
	int suma = 0;

	for (int i = 0; i < numProd; i++) {

		int mini = matriz[0][i];

		for (int j = 1; j < numSuper; j++)
			mini = min(mini, matriz[j][i]);

		coste[i] = mini;
		suma += mini;
	}

	compra(pagar, minimo, matriz, prodmismosuper, haysol, 0, numProd, numSuper, coste, suma);

	if (haysol)
		cout << minimo << '\n';

	else
		cout << "Sin solucion factible\n";
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
