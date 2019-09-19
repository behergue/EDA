//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*PRECONDICIÓN :
P = {0 < D < 1000000 and 0 < N < 200000 and forall i: 0 < i < N: 0 < v[i] < 1000000}
*/

bool apta(vector<int> const &v, int D) {

	int max = 0;
	bool apta;
	int j;

	/*INVARIANTE:
		creciente(j, k) = {forall i: j <= i < k: v[i + 1] > v[i]}
		Inv = {max = {max j, k: 0 <= j <= k < i < N and creciente (j, k): v[k] - v[j]}}

	  FUNCIÓN DE COTA:
		c(i) = N - i
	*/
	for (int i = 0; i < v.size(); i = j + 1) {

		int ini, fin;
		j = i;
		ini = v[i];

		/*INVARIANTE:
			Inv = {j: i <= j < N - 1 and v[j] < v[j + 1]}

		  FUNCIÓN DE COTA:
			c(i) = N - j
		*/
		while (j < v.size() - 1 && v[j] < v[j + 1]) 
			j++;

		fin = v[j];

		if (fin - ini > max)
			max = fin - ini;
	}

	if (max <= D)
		apta = true;

	else
		apta = false;

	return apta;
}

/*POSTCONDICIÓN:
max = {max j, k: 0 <= j <= k < N and creciente (j, k): v[k] - v[j]}
Q = {apta = max <= D}
*/

bool resuelveCaso() {
	int D, N, valor;
	vector<int> v;

	cin >> D;

	if (!std::cin)
		return false;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	if (apta(v, D))
		cout << "APTA\n";

	else
		cout << "NO APTA\n";

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
