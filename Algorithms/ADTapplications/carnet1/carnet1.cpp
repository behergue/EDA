//Beatriz Herguedas Pinedo

#include "carnet_puntos.h"

void resolver(string accion, carnet &c) {
	dni d;
	puntos p;

	try {
		if (accion == "nuevo") {
			cin >> d;
			c.nuevo(d);
		}

		else if (accion == "quitar") {
			cin >> d >> p;
			c.quitar(d, p);
		}

		else if (accion == "consultar") {
			cin >> d;
			cout << "Puntos de " << d << ": " << c.consultar(d) <<'\n';
		}

		else if (accion == "cuantos_con_puntos") {
			cin >> p;
			cout << "Con " << p << " puntos hay " << c.cuantos_con_puntos(p) << '\n';
		}
	}

	catch(domain_error e){
		cout << e.what() << '\n';
	}
}

bool resuelveCaso() {
	string accion;
	carnet c;

	cin >> accion;

	if (!std::cin)
		return false;

	while (accion != "FIN") {
		resolver(accion, c);
		cin >> accion;
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