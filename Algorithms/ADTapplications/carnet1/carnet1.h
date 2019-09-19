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
	unordered_map<dni, puntos> mapa;
	vector<int> v;

public:

	carnet() : v(16) {};

	void nuevo(dni d) {
		auto it = mapa.find(d);

		if (it == mapa.end()) {
			mapa.insert({ d, 15 });
			v[15]++;
		}

		else
			throw domain_error("ERROR: Conductor duplicado");
	}

	void quitar(dni d, puntos p) {
		auto it = mapa.find(d);

		if (it == mapa.end())
			throw domain_error("ERROR: Conductor inexistente");

		v[it->second]--;

		it->second = max(it->second - p, 0);

		v[it->second]++;
	}

	int consultar(dni d) {
		auto it = mapa.find(d);

		if (it == mapa.end())
			throw domain_error("ERROR: Conductor inexistente");

		return it->second;
	}

	int cuantos_con_puntos(puntos p) {

		if(p < 0 || p > 15)
			throw domain_error("ERROR: Puntos no validos");

		return v[p];
	}
};
#endif // !carnet_puntos.h
