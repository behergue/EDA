//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

/*PRECONDICIÓN :
P = {N > 0 and 0 <= pos < N}
*/

bool divideComoQuiereDoc(vector<int> const & temperaturas, int pos) {

	bool div;

	if (pos == temperaturas.size() - 1) {
		div =  true;
	}

	else {
		int maxIzq = temperaturas[0];
		int minDcha = temperaturas[pos + 1];

		/*INVARIANTE:
		Inv = {maxIzq >= temperaturas[j] forall j: 0 < j <= i}
		FUNCIÓN DE COTA:
		c(i) = pos + 1 - i
		*/
		for (int i = 0; i < pos + 1; i++) {
			if (temperaturas[i] > maxIzq)
				maxIzq = temperaturas[i];
		}

		/*INVARIANTE:
		Inv = {minDcha <= temperaturas[j] forall j: pos + 1 < j <= i}
		FUNCIÓN DE COTA:
		c(i) = N - (pos + 1) - i
		*/
		for (int i = pos + 1; i < temperaturas.size(); i++) {
			if (temperaturas[i] < minDcha)
				minDcha = temperaturas[i];
		}

		if (maxIzq < minDcha)
			div = true;

		else
			div = false;
	}

	return div;
}

/*POSTCONDICIÓN:
Q = {div = temperaturas[i] < temperaturas[j] forall i, j: 0 <= i <= pos, pos < j < N}
*/

bool resuelveCaso() {
	int N, valor, tam, pos;
	vector<int> temperaturas;

	cin >> tam >> pos;

	for (int i = 0; i < tam; i++) {
		cin >> valor;
		temperaturas.push_back(valor);
	}

	if (divideComoQuiereDoc(temperaturas, pos))
		cout << "SI\n";

	else
		cout << "NO\n";

	return true;
}

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
		resuelveCaso();

	return 0;
}
