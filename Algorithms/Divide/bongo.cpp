//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int bingo(vector<int> const &v, int ini, int fin, int cantado) {

	if (fin - ini == 0) {
		if (cantado + ini == v[ini])
			return v[ini];
		else
			return -1;
	}

	else if (fin - ini == 1) {
		if (cantado + ini == v[ini])
			return v[ini];

		else if (cantado + fin == v[fin])
			return v[fin];

		else
			return -1;
	}

	/*Teorema de la división:

		T(n)= k0                       si 0 ≤ n < b
			  a * T(n / b) + k1 * n^k  si n ≥ b

		T(n) ∈ Θ(n^k)          si a < b^k
				Θ(n^k * log(n)) si a = b^k
				Θ(n^logb(a))    si a > b^k

		Con b = 2, a = 1, k = 0
		Entonces a = 1 = b^k = 1 y por tanto el algoritmo tiene coste n^K * log(n) = log(n)
	*/

	else {
		int mitad = (ini + fin) / 2;

		if (cantado + mitad < v[mitad])
			return bingo(v, ini, mitad, cantado);

		else if (cantado + mitad > v[mitad])
			return bingo(v, mitad + 1, fin, cantado);
			
		else
			return v[mitad];
	}
}


void resuelveCaso() {
	int num, cantado, valor;
	vector<int> v;

	cin >> num >> cantado;

	for (int i = 0; i < num; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	int sol = bingo(v, 0, v.size() - 1, cantado);

	if (sol != -1)
		cout << sol << '\n';
	else
		cout << "NO\n";
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
