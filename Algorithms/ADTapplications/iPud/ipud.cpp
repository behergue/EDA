//Beatriz Herguedas Pinedo

#include "ipud.h"

void ejecutar(string accion, ipud& ipud) {
	song s;
	artist a;
	duration d;
	int n;

	try {
		if (accion == "addSong") {
			cin >> s >> a >> d;
			ipud.addSong(s, a, d);
		}

		else if (accion == "addToPlaylist") {
			cin >> s;
			ipud.addToPlaylist(s);
		}

		else if (accion == "current") {
			ipud.current();
		}

		else if (accion == "play") {
			s = ipud.play();

			if (s == "")
				cout << "No hay canciones en la lista\n";

			else
				cout << "Sonando " << s << '\n';
		}

		else if (accion == "totalTime") {
			int tiempo = ipud.totalTime();
			cout << "Tiempo total " << tiempo << '\n';
		}

		else if (accion == "recent") {
			cin >> n;
			auto lista = ipud.recent(n);

			if (lista.empty()) 
				cout << "No hay canciones recientes\n";

			else {
				cout << "Las " << lista.size() << " mas recientes\n";

				for (auto i : lista)
					cout << "    " << i << '\n';
			}
		}

		else if (accion == "deleteSong") {
			cin >> s;
			ipud.deleteSong(s);
		}
	}

	catch (domain_error e) {
		cout << e.what() << " " << accion << '\n';
	}
}

bool resuelveCaso() {
	string accion;
	ipud ipud;

	cin >> accion;

	if (!std::cin)
		return false;

	while (accion != "FIN") {
		ejecutar(accion, ipud);
		cin >> accion;
	}

	cout << "----\n";

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