//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*PRECONDICIÓN :
P = {0 < N and existe i: 0 < i < N: v[i] > altura}
*/

void arboles(vector<int> const &v, int altura, int &ini, int &fin) {

	int fakeini, fakefin;
	int j = 0;
	int max = - 1;


	/*INVARIANTE:
		alto(v, a, b) = {forall i: a <= i <= b: v[i] > altura}
		Inv = {max = {max a, b: 0 <= a <= i < b < N and alto(v, a, b): b - a}}

	  FUNCIÓN DE COTA:
		c(i) = N - i
	*/
	for (int i = 0; i < v.size(); i = j + 1) {
		j = i;
		fakeini = j;

		/*INVARIANTE:
			Inv = {j: i <= j < N and v[j] > altura}

		  FUNCIÓN DE COTA:
			c(j) = N - j
		*/
		while (j < v.size() && v[j] > altura) {
			j++;
		}

		fakefin = j - 1;

		if (fakefin - fakeini > max) {
			ini = fakeini;
			fin = fakefin;
			max = fin - ini;
		}
	}
}

/*POSTCONDICIÓN:
Q = {max a, b: 0 <= a <= b < N and alto(v, a, b):b - a}
*/

void resuelveCaso() {
	int numArboles, altura, valor, ini, fin;
	vector<int> v;

	cin >> numArboles >> altura;

	for (int i = 0; i < numArboles; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	arboles(v, altura, ini, fin);

	cout << ini << " " << fin << '\n';
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
