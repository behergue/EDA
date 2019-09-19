//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int tiempo(vector<int> &v, int ini, int mitad, int fin) {

	vector<int> aux(fin - ini + 1);
	int i = ini, j = mitad + 1, k = 0, cont = 0;

	while (i < mitad + 1 && j < fin + 1) {
		if (v[i] < v[j]) {
			aux[k] = v[i];
			i++;
		}
		else {
			aux[k] = v[j];
			cont += j - ini - k;
			j++;
		}
		k++;
	}

	while (i < mitad + 1) {
		aux[k] = v[i];
		i++;
		k++;
	}

	while (j < fin + 1) {
		aux[k] = v[j];
		j++;
		k++;
	}

	for (int n = 0; n < aux.size(); ++n)
		v[ini + n] = aux[n];

	return cont;
}

/*Teorema de la división:

	T(n)= k0                       si 0 ≤ n < b
		  a * T(n / b) + k1 * n^k  si n ≥ b

	T(n) ∈ Θ(n^k)          si a < b^k
			Θ(n^k * log(n)) si a = b^k
			Θ(n^logb(a))    si a > b^k

	Con b = 2, a = 2, k = 1
	Entonces a = 2 = b^k = 2 y por tanto el algoritmo tiene coste n^K * log(n) = n * log(n)
*/

void mergeSort(vector<int> &v, int ini, int fin, int &contador) {

	if (ini < fin) {

		int mitad = (ini + fin) / 2;

		mergeSort(v, ini, mitad, contador);
		mergeSort(v, mitad + 1, fin, contador);
		contador += tiempo(v, ini, mitad, fin);
	}
}

bool resuelveCaso() {
	int num, valor;
	vector<int> v;
	int cont = 0;

	cin >> num;

	if (!std::cin)
		return false;

	for (int i = 0; i < num; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	mergeSort(v, 0, v.size() - 1, cont);

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
