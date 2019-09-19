//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <deque>
#include <functional>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct cancion {
	int duracion;
	int puntuacion;
};

int estimacion(const vector<cancion> &v, int d, int t1, int t2, int k, int val) {
	int r = 2 * d - t1 - t2;
	int i = k + 1;

	while (i < v.size() && v[i].duracion <= r) {
		r -= v[i].duracion;
		val += v[i].puntuacion;
		i++;
	}

	if (i < v.size()) {
		val += (r * v[i].puntuacion) / v[i].duracion;
	}

	return val;
}

void resolver(const vector<cancion> &v, int d, int t1, int t2, int k, int val, int &maximo) {
	maximo = max(maximo, val);
	if (k < v.size()) {

		val += v[k].puntuacion;
		t1 += v[k].duracion;
		if (t1 <= d) {
			resolver(v, d, t1, t2, k + 1, val, maximo);
		}
		t1 -= v[k].duracion;
	
		t2 += v[k].duracion;
		if (t2 <= d) {
			resolver(v, d, t1, t2, k + 1, val, maximo);
		}
		t2 -= v[k].duracion;
		val -= v[k].puntuacion;

		if (estimacion(v, d, t1, t2, k, val) > maximo) {
			resolver(v, d, t1, t2, k + 1, val, maximo);
		}
	}
}

int resolverInicio(vector<cancion> &v, int d) {
	cancion c;
	int maximo = 0;

	sort(v.begin(), v.end(), [](const cancion &c1, const cancion &c2) -> bool {
		return float(c1.puntuacion) / c1.duracion > float(c2.puntuacion) / c2.duracion;
	});
	
	resolver(v, d, 0, 0, 0, 0, maximo);
	return maximo;
}

bool casoDePrueba() {
	int num, dur;

	cin >> num;

	if (num == 0) 
		return false;

	vector<cancion> canciones(num);

	cin >> dur;

	for (cancion &c : canciones) {
		cin >> c.duracion >> c.puntuacion;
	}

	cout << resolverInicio(canciones, dur) << '\n';

	return true;
}

int main() {
	while (casoDePrueba());
	return 0;
}
