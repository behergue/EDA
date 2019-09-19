//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int libros(vector<int> const& v, int ini, int fin) {

	if (fin - ini == 0) {
		return ini;
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

		if (fin - ini + 1 == 3 || (fin - ini + 1) % 4 == 3) {

			if (v[mitad] == v[mitad - 1])
				return libros(v, mitad + 1, fin);

			else if (v[mitad] == v[mitad + 1])
				return libros(v, ini, mitad - 1);

			else
				return mitad;
		}

		else if ((fin - ini + 1) % 4 == 1) {

			if (v[mitad] == v[mitad - 1])
				return libros(v, ini, mitad);

			else if (v[mitad] == v[mitad + 1])
				return libros(v, mitad, fin);

			else
				return mitad;
		}
	}
}

void resuelveCaso() {
	int num, valor;
	vector<int> v;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	cout << libros(v, 0, v.size() - 1) << '\n';
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
