//Beatriz Herguedas Pinedo

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int minimo(vector<int> const &v, int ini, int fin) {

	if (fin - ini == 0) {
		return v[ini];
	}

	else if (fin - ini == 1) {
		return min(v[ini], v[fin]);
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

		if (v[mitad] > v[mitad + 1])
			return minimo(v, mitad + 1, fin);

		else if (v[mitad] > v[mitad - 1])
			return minimo(v, ini, mitad);

		else
			return v[mitad];
	}
}

bool resuelveCaso() {
	int num, valor;
	vector<int> v;

	cin >> num;

	if (!std::cin)
		return false;

	for (int i = 0; i < num; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	cout << minimo(v, 0, v.size() - 1) << '\n';

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
