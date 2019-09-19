//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void polidivisible(long long int N, int D, int tam) {

	if (N % tam == 0) {
		cout << N << '\n';
		if (tam + 1 < D + 1) {
			for (int i = 0; i < 10; i++) 
				polidivisible(N * 10 + i, D, tam + 1);
		}
	}
}

bool resuelveCaso() {
	long long int N;
	int D;

	cin >> N >> D;

	if (!std::cin)
		return false;

	string secuencia = to_string(N);
	polidivisible(N, D, secuencia.size());
	cout << "---\n";

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
