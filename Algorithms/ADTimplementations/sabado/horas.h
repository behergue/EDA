#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#ifndef horas_h
#define horas_h

class horas {

private:

	int hora, minuto, segundo;

public:
	horas() {};

	horas(int h, int m, int s) {

		if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
			throw domain_error("ERROR");
		}

		else {
			this->hora = h;
			this->minuto = m;
			this->segundo = s;
		}
	}

	int geth() {
		return this->hora;
	}

	int getm() {
		return this->minuto;
	}

	int gets() {
		return this->segundo;
	}

	bool operator<(horas const& h) {
		return (this->hora < h.hora || this->hora == h.hora && this->minuto < h.minuto ||
			this->hora == h.hora && this->minuto == h.minuto && this->segundo < h.segundo);
	}

	bool operator==(horas const& h) {
		return (this->hora == h.hora && this->minuto == h.minuto && this->segundo == h.segundo);
	}

	horas operator+(horas const& h) {

		int s = (h.segundo + this->segundo);
		int m = (h.minuto + this->minuto + s/ 60);
		int ho = (h.hora + this->hora + m / 60);

		if (ho > 23)
			throw domain_error("ERROR");

		return { ho, m % 60, s % 60 };
	}
};

inline istream &operator>>(istream &in, horas &h) {

	int hor, min, sec;
	char aux;

	in >> hor >> aux >> min >> aux >> sec;
	h = horas(hor, min, sec);

	return in;
}

inline ostream &operator<<(ostream &out, horas &h) {

	out << setfill('0') << setw(2) << h.geth() << ":" << setfill('0') << setw(2)
		<< h.getm() << ":" << setfill('0') << setw(2) << h.gets();

	return out;
}
#endif