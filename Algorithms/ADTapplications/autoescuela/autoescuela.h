#ifndef autoescuela_h
#define autoescuela_h

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

using alumno = string;
using profesor = string;
using puntos = int;

class autoescuela {

private:
	map<alumno, pair<profesor, puntos>> alumnos;

public:

	void alta(alumno a, profesor p) {
		auto it = alumnos.find(a);

		if (it == alumnos.end())
			alumnos.insert({ a, {p, 0} });

		else
			it->second.first = p;
	}

	bool es_alumno(alumno a, profesor p) {
		auto it = alumnos.find(a);

		if (it != alumnos.end() && it->second.first == p)
			return true;

		else
			return false;
	}

	int puntuacion(alumno a) {
		auto it = alumnos.find(a);

		if (it == alumnos.end())
			throw domain_error("El alumno " + a + " no esta matriculado");

		return it->second.second;
	}

	void actualizar(alumno a, int n) {
		auto it = alumnos.find(a);

		if (it == alumnos.end())
			throw domain_error("El alumno " + a + " no esta matriculado");

		it->second.second = it->second.second + n;
	}

	list<alumno> examen(profesor p, int n) {
		list<alumno> lista;

		for (auto i : alumnos) {
			if (i.second.first == p && i.second.second >= n)
				lista.push_back(i.first);
		}

		return lista;
	}

	void aprobar(alumno a) {
		auto it = alumnos.find(a);

		if (it == alumnos.end())
			throw domain_error("El alumno " + a + " no esta matriculado");

		alumnos.erase(it);
	}
};
#endif