#include "horas.h"

#ifndef pelicula_h
#define pelicula_h

class pelicula {

private:

	horas inicio, fin, duracion;
	string titulo;

public:

	pelicula() {};

	pelicula(horas ini, horas dur, string tit) {
		this->inicio = ini;
		this->duracion = dur;
		this->fin = ini + dur;
		this->titulo = tit;
	}

	string gettit() {
		return this->titulo;
	}

	horas getfin() {
		return this->fin;
	}

	bool operator<(pelicula p) {
		return (this->fin < p.fin || this->fin == p.fin && this->titulo < p.titulo);
	}
};

#endif