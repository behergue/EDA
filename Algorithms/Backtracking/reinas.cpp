//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void reinas(vector<bool> & columna, vector<bool> & diagonal, int &sol, int N, int fila) {

	for (int i = 0; i < N; i++) {

		if (!columna[i] && !diagonal[i - fila + N] && !diagonal[i + 2 * N + fila - 1]) {

			columna[i] = true;
			diagonal[i - fila + N] = true;
			diagonal[i + 2 * N + fila - 1] = true;

			if (fila == N - 1)
				sol++;

			else
				reinas(columna, diagonal, sol, N, fila + 1);

			columna[i] = false;
			diagonal[i - fila + N] = false;
			diagonal[i + 2 * N + fila - 1] = false;

		}
	}
}


void resuelveCaso() {
	int N;
	int sol = 0;

	cin >> N;

	vector<bool> columna(N, false);
	vector<bool> diagonal(4 * N - 2, false);

	reinas(columna, diagonal, sol, N, 0);

	cout << sol << '\n';

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
