//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*PRECONDICIÓN :
P = {0 < N < 10000 and forall i: 0 < i < N: -274 < v[i] < 1000}
*/

void picosyvalles(vector<int> &v, int &numPicos, int &numValles) {

	numPicos = 0;
	numValles = 0;

	if (v.size() > 2) {

		/*INVARIANTE:
		pico[i] = {v[i - 1] < v[i] and v[i] > v[i + 1]}
		valle[i] = {v[i - 1] > v[i] and v[i] < v[i + 1]}

		Inv = {numPicos = {#j: 1 <= j < n < N - 1 and pico[j]} and
		numValles = {#j: 1 <= j < n < N - 1 and valle[j]}}

	  FUNCIÓN DE COTA:
		c(i) = N - i
	*/

		for (int i = 1; i < v.size() - 1; i++) {
			if (v[i - 1] < v[i] && v[i + 1] < v[i])
				numPicos++;
			else if (v[i - 1] > v[i] && v[i + 1] > v[i])
				numValles++;
		}
	}
}

/*POSTCONDICIÓN:
Q ={numPicos = {#j: 0 <= j < N and pico[j]} and
	numValles = {#j: 0 <= j < N and valle[j]}}
*/

void resuelveCaso() {
	int num, valor, numPicos, numValles;
	vector<int> v;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	picosyvalles(v, numPicos, numValles);

	cout << numPicos << " " << numValles << '\n';
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
