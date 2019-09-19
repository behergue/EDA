//Beatriz Herguedas Pinedo, DG209

#include "list_eda.h"
#include "persona.h"

bool resuelveCaso() {
	int N, inf, sup, edad;
	list<persona> lista;
	string nombre;
	persona p;

	cin >> N >> inf >> sup;

	if (N == 0 && inf == 0 && sup == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> edad;
		getline(cin, nombre);
		p = { edad, nombre };
		lista.push_back(p);
	}

	lista.remove_if(condition(inf, sup));

	for (auto p : lista) {
		cout << p.getNombre().substr(1, p.getNombre().size()) << '\n';
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