#ifndef persona_h
#define persona_h

#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class persona {

private:

	string nombre;
	int edad;

public:

	persona(){};

	persona(int e, string n) {
		this->edad = e;
		this->nombre = n;
	}

	string getNombre() {
		return this->nombre;
	}

	int getEdad() {
		return this->edad;
	}
};


class condition {

private:

	int min, max;

public:

	condition(int mi, int ma) {
		this->min = mi;
		this->max = ma;
	}

	bool operator()(persona p) {
		return (p.getEdad() < this->min || p.getEdad() > this->max);
	}

};
#endif // !persona_h
