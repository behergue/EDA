//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "consultorio.h"

using namespace std;

void ejecutar(string accion, consultorio& consult) {
	string paciente, medico;
	int dia, hora, min;

	try {
		if (accion == "nuevoMedico") {
			cin >> medico;
			consult.nuevoMedico(medico);
		}

		else if (accion == "pideConsulta") {
			cin >> medico >> paciente >> dia >> hora >> min;

			consult.pideConsulta(medico, paciente, { dia, hora, min });
		}

		else if (accion == "siguientePaciente") {
			cin >> medico;
			paciente = consult.siguientePaciente(medico);

			cout << "Siguiente paciente doctor " << medico << '\n';
			cout << paciente << '\n';
			cout << "---\n";
		}

		else if (accion == "atiendeConsulta") {
			cin >> medico;

			consult.atiendeConsulta(medico);
		}

		else if (accion == "listaPacientes") {
			cin >> medico >> dia;

			auto lista = consult.listaPacientes(medico, dia);

			cout << "Doctor " << medico << " dia " << dia << '\n';

			for (auto l : lista) {
				cout << l.second << " " << l.first << '\n';
			}

			cout << "---\n";
		}
	}
	catch (domain_error e) {
		cout << e.what() << '\n';
		cout << "---\n";
	}

}

bool resuelveCaso() {
	int num;
	consultorio c;
	string accion;

	cin >> num;

	if (!std::cin)
		return false;

	for (int i = 0; i < num; i++) {
		cin >> accion;

		ejecutar(accion, c);

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