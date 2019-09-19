//Beatriz Herguedas Pinedo

#include "libreria.h"

using namespace std;

void resolver(string accion, libreria& biblioteca) {
	existencias e;
	libro l;
	int n;

	try {
		if (accion == "nuevoLibro") {
			cin >> e;
			getline(cin, l);
			l = l.substr(1, l.size());
			biblioteca.nuevoLibro(e, l);
		}

		else if (accion == "comprar") {
			getline(cin, l);
			l = l.substr(1, l.size());
			biblioteca.comprar(l);
		}

		else if (accion == "estaLibro") {
			getline(cin, l);
			l = l.substr(1, l.size());

			if (biblioteca.estaLibro(l))
				cout << "El libro " << l << " esta en el sistema\n";

			else
				cout << "No existe el libro " << l << " en el sistema\n";

			cout << "---\n";
		}

		else if (accion == "elimLibro") {
			getline(cin, l);
			l = l.substr(1, l.size());
			biblioteca.elimLibro(l);
		}

		else if (accion == "numEjemplares") {
			try {
				getline(cin, l);
				l = l.substr(1, l.size());
				n = biblioteca.numEjemplares(l);
				cout << "Existen " << n << " ejemplares del libro " << l << '\n';
			}

			catch (invalid_argument e) {
				cout << "No existe el libro " << l << " en el sistema\n";
			}

			cout << "---\n";
		}

		else if (accion == "top10") {
			auto lista = biblioteca.top10();

			for (auto libro : lista) 
				cout << libro << '\n';

			cout << "---\n";
		}

	}
	catch (invalid_argument e) {
		cout << e.what() << '\n';
		cout << "---\n";
	}
	catch (out_of_range e) {
		cout << e.what() << '\n';
		cout << "---\n";
	}
}

bool resuelveCaso() {
	string accion;
	libreria biblioteca;
	int n;

	cin >> n;

	if (!std::cin)
		return false;

	for (int i = 0; i < n; i++) {
		cin >> accion;
		resolver(accion, biblioteca);
	}

	cout << "------\n";

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