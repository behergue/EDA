//Beatriz Herguedas Pinedo

#include "polinomio.h"

bool resuelveCaso() {
	monomio m;
	polinomio p;
	int N, n;

	cin >> m.coeficiente >> m.exponente;

	if (!std::cin)
		return false;

	while (m.coeficiente != 0 || m.exponente != 0) {
		
		p.anademonomio(m);
		cin >> m.coeficiente >> m.exponente;
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		cout << p.evaluar(n) << ' ';
	}

	cout << '\n';

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