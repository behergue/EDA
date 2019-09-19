//Beatriz Herguedas Pinedo

#include "horas.h"

bool resuelveCaso() {
	int T, H;
	horas aux, hora;
	vector<horas> trenes;

	cin >> T >> H;

	if (T == 0 && H == 0)
		return false;

	for (int i = 0; i < T; i++) {
		cin >> aux;
		trenes.push_back(aux);
	}


	for (int i = 0; i < H; i++) {

		try {
			cin >> hora;

			int j = 0;
			bool encontrado = false;

			while (!encontrado && j < trenes.size()) {
				if (hora < trenes[j] || hora == trenes[j])
					encontrado = true;
				j++;
			}

			if (!encontrado)
				cout << "NO\n";

			else
				cout << trenes[j - 1];
		}

		catch (domain_error e) {
			cout << e.what() << '\n';
		}
	}

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