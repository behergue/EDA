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

void trabajo(vector<vector<int>> const& matriz, int N, int &tiempo, 
	int &tiempomin, int fila, vector<bool> &marcado, vector<int> const &sumaminima) {

	for (int i = 0; i < N; i++) {

		if (!marcado[i]) {

			marcado[i] = true;
			tiempo += matriz[fila][i];

			if (fila == N - 1)
				tiempomin = min(tiempo, tiempomin);

			else {
				int suma = tiempo + sumaminima[N - 2 - fila];

				if(suma < tiempomin)
					trabajo(matriz, N, tiempo, tiempomin, fila + 1, marcado, sumaminima);
			}

			marcado[i] = false;
			tiempo -= matriz[fila][i];
		}
	}
}

bool resuelveCaso() {
	int N, valor;
	vector<int> fila;
	vector<vector<int>> matriz;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> valor;
			fila.push_back(valor);
		}
		matriz.push_back(fila);
		fila.clear();
	}

	int tiempo = 0;
	int tiempomin = INT_MAX;
	vector<bool> marcado(N);
	vector<int> sumaminima;

	int cont = 0;

	for (int i = N - 1; i > -1; i--) {

		int minFila = INT_MAX;

		for (int j = 0; j < N; j++) {
			minFila = min(minFila, matriz[i][j]);
		}

		cont += minFila;
		sumaminima.push_back(cont);
	}

	trabajo(matriz, N, tiempo, tiempomin, 0, marcado, sumaminima);

	cout << tiempomin << '\n';

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
