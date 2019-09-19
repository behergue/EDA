//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*PRECONDICIÓN :
P = {0 < N < 100000 and forall i: 0 < i < N: 0 <= v[i]}
*/

int tamSegmentoMaximo(vector<int> const &v) {

	int a, b;
	int j;
	int max = 0;                                   

	/*INVARIANTE:
		iguales(v, a, b) = {forall i: a <= i <= b: v[i + 1] = v[i]}
		Inv = {max = {max a, b: 0 <= a <= i < b < N and iguales (v, a, b): b - a}}

	  FUNCIÓN DE COTA:
		c(i) = N - i
	*/
	for (int i = 0; i < v.size(); i = j + 1) {
		j = i;
		a = j;

		/*INVARIANTE:
			Inv = {j: i <= j < N - 1 and v[j] = v[j + 1]}

		  FUNCIÓN DE COTA:
			c(i) = N - j
		*/
		while (j < v.size() - 1 && v[j] == v[j + 1])
			j++;

		b = j;

		if (b - a > max) 
			max = b - a;
	}
	return max;
}

/*POSTCONDICIÓN:
Q = {max a, b: 0 <= a <= b < N and iguales (v, a, b):b - a}
*/

bool resuelveCaso() {
	int valor;
	vector<int> v;

	cin >> valor;

	if (valor == -1)
		return false;

	while (valor != -1) {
		v.push_back(valor);
		cin >> valor;
	}

	int sol = tamSegmentoMaximo(v);

	if (sol == 0)
		cout << "HOY NO COMEN\n";

	else
		cout << sol << '\n';

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
