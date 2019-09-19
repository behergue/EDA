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

void quitanieves(int & max, int & suma, vector<int> &camino, vector<vector<int>> const &calidades, vector<int> const &anchoCarretera,
	vector<int> const &anchoMaquina, int fila, int numCarreteras, int numMaquinas, vector<bool> &ocupada, vector<int> const &maxFila) {

	for (int col = 0; col < numCarreteras; col++) {
	
		if (!ocupada[col]) {

			if (anchoCarretera[col] >= anchoMaquina[fila]) {
	
				camino.push_back(calidades[fila][col]);
				suma += calidades[fila][col];
				ocupada[col] = true;

				if (fila == numMaquinas - 1) {
					if (suma > max) max = suma;
				}

				else if (suma + maxFila[maxFila.size() - 1] - maxFila[fila] > max) {
					quitanieves(max, suma, camino, calidades, anchoCarretera, anchoMaquina, fila + 1, numCarreteras, numMaquinas, ocupada, maxFila);
				}

				camino.pop_back();
				suma -= calidades[fila][col];
				ocupada[col] = false;

			}
		}
	}
}


void resuelveCaso() {
	int numMaquinas, numCarreteras, valor;
	vector<int> anchoCarretera, anchoMaquina, aux, camino, maxFila;
	vector<vector<int>> calidades;
	int max = 0;
	int suma = 0;
	int m = 0, s = 0;

	cin >> numMaquinas >> numCarreteras;

	vector<bool> ocupada(numCarreteras, false);

	for (int i = 0; i < numMaquinas; i++) {
		cin >> valor;
		anchoMaquina.push_back(valor);
	}

	for (int i = 0; i < numCarreteras; i++) {
		cin >> valor;
		anchoCarretera.push_back(valor);
	}

	for (int i = 0; i < numMaquinas; i++) {
		for (int j = 0; j < numCarreteras; j++) {
			cin >> valor;
			aux.push_back(valor);
		}
		calidades.push_back(aux);

		m = 0;
		for (int i = 0; i < aux.size(); i++) {
			if (aux[i] > m)
				m = aux[i];
		}
		s += m;
		maxFila.push_back(s);
		aux.clear();
	}

	if (numMaquinas != 0) {
		quitanieves(max, suma, camino, calidades, anchoCarretera, anchoMaquina, 0, numCarreteras, numMaquinas, ocupada, maxFila);

		cout << max << '\n';
	}

	else {
		cout << 0 << '\n';
	}
}
/*
void vueltaAtras(vector<int> const &anchuraMaq, vector<int> const &anchuraCar, int k, int &solMejor, int & solActual,
	vector<vector<int>> const &matrizCalidad, vector<bool> &usadas, int &sumaMin, vector<int> &mins)
{
	for (int i = 0; i < usadas.size(); ++i) {
		if (!usadas[i] && anchuraMaq[k] <= anchuraCar[i]) {
			
			usadas[i] = true;
			solActual += matrizCalidad[k][i];
			sumaMin -= mins[k];
			if (sumaMin + solActual > solMejor) {
				if (k < anchuraMaq.size() - 1) {
					if (solActual > solMejor) solMejor = solActual;
					vueltaAtras(anchuraMaq, anchuraCar, k + 1, solMejor, solActual, matrizCalidad, usadas, sumaMin, mins);
				}
				else {
					if (solActual > solMejor) solMejor = solActual;
				}
			}
		
			solActual -= matrizCalidad[k][i];
			usadas[i] = false;
			sumaMin += mins[k];
		}
	}
}

void resuelveCaso()
{
	int n, m;

	cin >> m >> n;

	vector<int> anchuraMaq(m);
	vector<int> anchuraCar(n);
	vector<int> mins(m, 1000);

	int sumaMin = 0;

	for (int i = 0; i < m; ++i) {
		std::cin >> anchuraMaq[i];
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> anchuraCar[i];
	}

	vector<vector<int>> matrizCalidad(m);
	int aux;

	for (int i = 0; i < m; ++i) { 
		for (int j = 0; j < n; ++j) {
			std::cin >> aux;
			matrizCalidad[i].push_back(aux);
			if (mins[i] < aux) mins[i] = aux;
		}
		sumaMin += mins[i];
	}

	int solMejor = 0;
	int solActual = 0;
	vector<bool> usadas(n, false);

	if (m > 0) {

		vueltaAtras(anchuraMaq, anchuraCar, 0, solMejor, solActual, matrizCalidad, usadas, sumaMin, mins);

		cout << solMejor << "\n";
	}

	else {
		cout << 0 << '\n';
	}
}*/

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 

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
