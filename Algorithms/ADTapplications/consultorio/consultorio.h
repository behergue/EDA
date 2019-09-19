#ifndef consultorio_h
#define consultorio_h

#include "fecha.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

using medico = string;
using paciente = string;

class consultorio {

private:
	unordered_map<medico, map<fecha, paciente>> hospi;

public:

	void nuevoMedico(medico m) {
		auto it = hospi.find(m);
		if (it == hospi.end())
			hospi.insert({ m, {} });
	}

	void pideConsulta(paciente p, medico m, fecha f) {
		auto it = hospi.find(m);
		if (it == hospi.end())
			throw domain_error("Medico no existente");

		auto it2 = it->second.find(f);
		if (it2 == it->second.end())
			it->second.insert({ f, p });
			
		else
			throw domain_error("Fecha ocupada");
			
	}

	string siguientePaciente(medico m) {
		auto it = hospi.find(m);
		if (it == hospi.end())
			throw domain_error("Medico no existente");

		if (it->second.empty())
			throw domain_error("No hay pacientes");

		return it->second.begin()->second;
	}

	void atiendeConsulta(medico m) {
		auto it = hospi.find(m);
		if (it == hospi.end())
			throw domain_error("Medico no existente");

		if (it->second.empty())
			throw domain_error("No hay pacientes");

		it->second.erase(it->second.begin());
	}

	//de menor a mayor por hora de consulta
	list<pair<fecha, paciente>> listaPacientes(medico m, int d) {
		auto it = hospi.find(m);
		list<pair<fecha, paciente>> lista;
		if (it == hospi.end())
			throw domain_error("Medico no existente");

		if (it->second.empty())
			return lista;

		for (auto i : it->second) {
			fecha aux = i.first;

			if (d == aux.getDia())
				lista.push_back(i);
		}

		return lista;
	}
};
#endif