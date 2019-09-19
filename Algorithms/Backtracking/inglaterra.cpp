//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool inv(vector<pair<int, int>> const &invalidas, int fila, int col) {

	bool esta = false;
	int i = 0;

	while (!esta && i < invalidas.size()) {

		if (fila == invalidas[i].first && col == invalidas[i].second)
			esta = true;

		i++;
	}

	return esta;
}

void turing(int &cont, int fila, vector<pair<int, int>> invalidas, int T, int R,
	vector<bool> & columna, vector<pair<bool, bool>> & diagonal, int &tcolocadas, int &rcolocadas) {

	for (int i = 0; i < columna.size(); i++) {

		if (tcolocadas < T) {
			if (!columna[i] && !inv(invalidas, fila, i) && !diagonal[i - fila + R + T].first
				&& !diagonal[i + fila + 2 * (R + T) - 1].first) {

				tcolocadas++;

				bool aux1 = diagonal[i - fila + R + T].second;
				bool aux2 = diagonal[i + fila + 2 * (R + T) - 1].second;

				columna[i] = true;
				diagonal[i - fila + R + T].second = true;
				diagonal[i + fila + 2 * (R + T) - 1].second = true;

				//if (tcolocadas + rcolocadas == T + R)
				if (fila == R + T - 1) 
					cont++;

				else
					turing(cont, fila + 1, invalidas, T, R, columna, diagonal, tcolocadas, rcolocadas);

				columna[i] = false;

				if(!aux1)
					diagonal[i - fila + R + T].second = false;

				if(!aux2)
					diagonal[i + fila + 2 * (R + T) - 1].second = false;

				tcolocadas--;
			}
		}

		if (rcolocadas < R) {
			if (!columna[i] && !inv(invalidas, fila, i) && !diagonal[i - fila + R + T].first && !diagonal[i - fila + R + T].second
				&& !diagonal[i + fila + 2 * (R + T) - 1].first && !diagonal[i + fila + 2 * (R + T) - 1].second) {

				rcolocadas++;

				columna[i] = true;
				diagonal[i - fila + R + T].first = true;
				diagonal[i - fila + R + T].second = true;
				diagonal[i + fila + 2 * (R + T) - 1].first = true;
				diagonal[i + fila + 2 * (R + T) - 1].second = true;

				//if (tcolocadas + rcolocadas == T + R)
				if (fila == R + T - 1)
					cont++;

				else
					turing(cont, fila + 1, invalidas, T, R, columna, diagonal, tcolocadas, rcolocadas);

				columna[i] = false;
				diagonal[i - fila + R + T].first = false;
				diagonal[i - fila + R + T].second = false;
				diagonal[i + fila + 2 * (R + T) - 1].first = false;
				diagonal[i + fila + 2 * (R + T) - 1].second = false;

				rcolocadas--;

			}
		}
	}
}

bool resuelveCaso() {
	int T, R, n;
	int cont = 0;
	pair<int, int> invalida;
	vector<pair<int, int>> invalidas;

	cin >> T >> R >> n;

	if (!std::cin)
		return false;

	for (int i = 0; i < n; i++) {
		cin >> invalida.first >> invalida.second;
		invalida.first--;
		invalida.second--;
		invalidas.push_back(invalida);
	}

	vector<bool> columna(T + R);
	vector<pair<bool, bool>> diagonal(4 * (T + R) - 2);

	int tcolocadas = 0;
	int rcolocadas = 0;

	turing(cont, 0, invalidas, T, R, columna, diagonal, tcolocadas, rcolocadas);

	cout << cont << '\n';

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
