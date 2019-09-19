//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*PRECONDICIÓN :
P = {N < 10000 and forall i: 0 < i < N: 0 < v[i] < 10^18}
*/

void maxmin (vector<long long int> const &v,long long int &maximo, 
	long long int &minimo, int &vecesmax, int &vecesmin) {

	maximo = v[0];
	minimo = v[0];
	vecesmax = 1;
	vecesmin = 1;

	/*INVARIANTE:
		Inv = {maximo = {max i: 0 <= i <= n < N: v[i]} and 
		vecesMax = {#j: 0 <= j < n < N and v[j] = maximo} and 
		minimo = {min i: 0 <= i <= n < N: v[i]} and
		vecesMin = {#j: 0 <= j < n < N and v[j] = minimo}}

	  FUNCIÓN DE COTA:
		c(i) = N - i
	*/
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == maximo)
			vecesmax++;
		if (v[i] == minimo)
			vecesmin++;
		else if (v[i] < minimo) {
			minimo = v[i];
			vecesmin = 1;
		}
		else if (v[i] > maximo) {
			maximo = v[i];
			vecesmax = 1;
		}
	}
}

/*POSTCONDICIÓN:
Q = {maximo = {max i: 0 <= i <= N: v[i]} and 
	vecesMax = {#j: 0 <= j < N and v[j] = maximo} and 
	minimo = {min i: 0 <= i <= N: v[i]} and
	vecesMin = {#j: 0 <= j < N and v[j] = minimo}}
*/

void resuelveCaso() {
	vector<long long int> v;
	int vecesmax, vecesmin;
	long long int valor, maximo, minimo; 

	cin >> valor;

	while (valor != 0) {
		v.push_back(valor);
		cin >> valor;
	}

	maxmin(v, maximo, minimo, vecesmax, vecesmin);

	cout << minimo << " " << vecesmin << " " << maximo <<
		" " << vecesmax << '\n';
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
