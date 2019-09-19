#ifndef fecha_h
#define fecha_h

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

class fecha {

private:

	int dia;
	int hora;
	int min;

public:

	fecha(int dia, int hora, int min) {

		this->dia = dia;
		this->hora = hora;
		this->min = min;
	}

	int getDia() {
		return dia;
	}

	int getHora() {
		return hora;
	}

	int getMin() {
		return min;
	}

	bool const operator< (fecha const& f) const {
		return ((dia < f.dia) || (dia == f.dia && hora < f.hora) || (dia == f.dia && hora == f.hora && min < f.min));
	}

};

inline ostream & operator<< (ostream & out, fecha & f) {

	out << setfill('0') << setw(2) << f.getHora() << ":" << setfill('0') << setw(2) << f.getMin();

	return out;
}

#endif