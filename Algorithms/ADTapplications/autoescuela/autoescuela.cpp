//Beatriz Herguedas Pinedo

#include "autoescuela.h"

void resolver(string accion, autoescuela& gala) {
	alumno a;
	profesor p;
	puntos n;

	try {
		if (accion == "alta") {
			cin >> a >> p;
			gala.alta(a, p);
		}

		else if (accion == "es_alumno") {
			cin >> a >> p;
			if (gala.es_alumno(a, p))
				cout << a << " es alumno de " << p << '\n';

			else
				cout << a << " no es alumno de " << p << '\n';
		}

		else if (accion == "puntuacion") {
			cin >> a;
			cout << "Puntuacion de " << a << ": " << gala.puntuacion(a) << '\n';
		}

		else if (accion == "actualizar") {
			cin >> a >> n;
			gala.actualizar(a, n);
		}

		else if (accion == "examen") {
			cin >> p >> n;
			list<alumno> l = gala.examen(p, n);
			cout << "Alumnos de " << p << " a examen:\n";
			for (auto i : l)
				cout << i << '\n';
		}

		else if (accion == "aprobar") {
			cin >> a;
			gala.aprobar(a);
		}
	}

	catch (domain_error e) {
		cout << "ERROR" << '\n';
	}
}

bool resuelveCaso() {
	string accion;
	autoescuela a;

	cin >> accion;

	if (!std::cin)
		return false;

	while (accion != "FIN") {
		resolver(accion, a);
		cin >> accion;
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