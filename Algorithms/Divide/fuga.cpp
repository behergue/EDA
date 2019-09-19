//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

char fugado(char x1, char x2, vector<char> const &v, int ini, int fin) {

	if (v[ini] != x1) {
		return x1;
	}

	else if (v[fin] != x2) {
		return x2;
	}

	else {

		if (fin - ini == 0) {
			if (v[ini] != x1)
				return x1;
			else
				return x2;
		}

		else if (fin - ini == 1) {
			if (v[ini] != x1)
				return x1;

			else if (v[fin] != x2)
				return x2;

			else
				return v[ini] + 1;
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

			if ((x2 - x1) % 2 == 0) {
				if (v[mitad] - v[ini] >= (x2 - x1) / 2)
					return fugado(x1, v[mitad], v, ini, mitad);

				else if (v[fin] - v[mitad + 1] >= (x2 - x1) / 2)
					return fugado(v[mitad + 1], x2, v, mitad + 1, fin);

				else
					return v[mitad] + 1;
			}

			else {
				if (v[mitad] - v[ini] > (x2 - x1) / 2)
					return fugado(x1, v[mitad], v, ini, mitad);

				else if (v[fin] - v[mitad + 1] >= (x2 - x1) / 2)
					return fugado(v[mitad + 1], x2, v, mitad + 1, fin);

				else
					return v[mitad] + 1;
			}
		}
	}
}

void resuelveCaso() {
	char x1, x2, valor;
	vector<char> v;

	cin >> x1 >> x2;

	for (int i = 0; i < x2 - x1; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	cout << fugado(x1, x2, v, 0, v.size() - 1) << '\n';
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
