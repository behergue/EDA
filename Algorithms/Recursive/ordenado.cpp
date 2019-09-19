//Beatriz Herguedas Pinedo

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool parcialmenteOrdenado(vector<int> const &v, int ini, int fin, int &maxim, int &minim) {

	if (ini == fin) {
		maxim = v[ini];
		minim = v[ini];
		return true;
	}

	else if (fin - ini == 1) {
		maxim = max(v[ini], v[fin]);
		minim = min(v[ini], v[fin]);

		return v[ini] <= v[fin];
	}

	/*Teorema de la división:

	T(n)= k0                       si 0 ≤ n < b
		  a * T(n / b) + k1 * n^k  si n ≥ b

	T(n) ∈ Θ(n^k)          si a < b^k
			Θ(n^k * log(n)) si a = b^k
			Θ(n^logb(a))    si a > b^k

	Con b = 2, a = 2, k = 0
	Entonces a = 2 > b^k = 1 y por tanto el algoritmo tiene coste n^log2(2) = n^1 = n
	*/

	else {
		int mitad = (ini + fin) / 2;

		int maxIzq, maxDcha, minIzq, minDcha;
		bool izq = parcialmenteOrdenado(v, ini, mitad, maxIzq, minIzq);
		bool dcha = parcialmenteOrdenado(v, mitad + 1, fin, maxDcha, minDcha);

		maxim = max(maxIzq, maxDcha);
		minim = min(minIzq, minDcha);

		return izq && dcha && maxIzq <= maxDcha && minIzq <= minDcha;
	}
}

bool resuelveCaso() {
	int valor, max, min;
	vector<int> v;

	cin >> valor;

	if (valor == 0)
		return false;

	while (valor != 0) {
		v.push_back(valor);
		cin >> valor;
	}

	if (parcialmenteOrdenado(v, 0, v.size() - 1, max, min))
		cout << "SI\n";
	else
		cout << "NO\n";

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
