#ifndef carnet_puntos
#define carnet_puntos

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using dni = string;
using puntos = int;

class carnet {

private:
	unordered_map<dni, pair<puntos, list<dni>::iterator>> mapa;
	vector<list<dni>> pu;
	vector<int> v;

public:

	carnet() : v(16), pu(16) {};

	void nuevo(dni d) {
		auto it = mapa.find(d);

		if (it == mapa.end()) {
			//inserto en el mapa el dni, su puntuacion y su posicion en la lista correspondiente a 15 puntos
			mapa.insert({ d, {15, pu[15].insert(pu[15].begin(), d)}});

			//hay una persona mas con 15 puntos
			v[15]++;
		}

		else
			throw domain_error("ERROR: Conductor duplicado");
	}

	void quitar(dni d, puntos p) {
		auto it = mapa.find(d);

		if (it == mapa.end())
			throw domain_error("ERROR: Conductor inexistente");

		//hay una persona menos con los puntos anteriores
		v[it->second.first]--;

		bool cambio = false;
		//lo eliminamos de la lista de sus puntos anteriores
		if (it->second.first > 0 && p > 0) {
			pu[it->second.first].erase(it->second.second);
			cambio = true;
		}

		//actualizamos sus puntos
		it->second.first = max(it->second.first - p, 0);

		//actualizamos su posicion en la lista con su nueva puntuacion insertando por el principio
		if(cambio)
			it->second.second = pu[it->second.first].insert(pu[it->second.first].begin(), d);

		//hay una persona mas con esa nueva puntuacion
		v[it->second.first]++;
	}

	void recuperar(dni d, puntos p) {
		auto it = mapa.find(d);

		if (it == mapa.end())
			throw domain_error("ERROR: Conductor inexistente");

		//hay una persona menos con los puntos anteriores
		v[it->second.first]--;

		bool cambio = false;
		//lo eliminamos de la lista de sus puntos anteriores
		if (it->second.first < 15 && p > 0) {
			pu[it->second.first].erase(it->second.second);
			cambio = true;
		}

		//actualizamos sus puntos
		it->second.first = min(it->second.first + p, 15);

		//actualizamos su posicion en la lista con su nueva puntuacion insertando por el principio
		if(cambio)
			it->second.second = pu[it->second.first].insert(pu[it->second.first].begin(), d);

		//hay una persona mas con esa nueva puntuacion
		v[it->second.first]++;
	}

	int consultar(dni d) {
		auto it = mapa.find(d);

		if (it == mapa.end())
			throw domain_error("ERROR: Conductor inexistente");

		return it->second.first;
	}

	int cuantos_con_puntos(puntos p) {
		if (p < 0 || p > 15)
			throw domain_error("ERROR: Puntos no validos");

		return v[p];
	}

	list<dni> lista_por_puntos(puntos p) {
		if (p < 0 || p > 15)
			throw domain_error("ERROR: Puntos no validos");

		return pu[p];
	}
};
#endif // !carnet_puntos.h
