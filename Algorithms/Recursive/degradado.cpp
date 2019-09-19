//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool degradado(vector<int> const &v, int ini, int fin, int &suma) {

	if (ini == fin) {
		suma = v[ini];
		return true;
	}

	else if (fin - ini == 1) {
		suma = v[ini] + v[fin];
		return v[ini] < v[fin];
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

		int sumaIzq, sumaDcha;
		bool izq = degradado(v, ini, mitad, sumaIzq);
		bool dcha = degradado(v, mitad + 1, fin, sumaDcha);

		suma = sumaIzq + sumaDcha;

		return izq && dcha && sumaIzq < sumaDcha;
	}
}

bool resuelveCaso() {
	int n, m, valor, suma;
	vector<int> v;
	bool sol = true;

	cin >> n >> m;

	if (!std::cin)
		return false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> valor;
			v.push_back(valor);
		}

		if (!degradado(v, 0, v.size() - 1, suma))
			sol = false;

		v.clear();
	}

	if (sol)
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
