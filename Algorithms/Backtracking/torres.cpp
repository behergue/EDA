//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<string> const &torre) {

	for (int i = 0; i < torre.size(); i++) {

		cout << torre[i];

		if(i < torre.size() - 1)
			cout << ' ';
	}

	cout << '\n';
}

void construccion(int altura, int &a, int &r, int &v, vector<string> &torre, 
	bool &posible, int &acolocadas, int &rcolocadas, int &vcolocadas) {

	if (a > 0 && torre.size() < altura) {

		torre.push_back("azul");
		a--;
		acolocadas++;

		if (rcolocadas > acolocadas + vcolocadas && torre.size() == altura) {
			mostrar(torre);
			posible = true;
		}

		construccion(altura, a, r, v, torre, posible, acolocadas, rcolocadas, vcolocadas);

		torre.pop_back();
		a++;
		acolocadas--;
	}


	if (r > 0 && torre.size() < altura) {

		torre.push_back("rojo");
		r--;
		rcolocadas++;

		if (rcolocadas > acolocadas + vcolocadas && torre.size() == altura) {
			mostrar(torre);
			posible = true;
		}

		construccion(altura, a, r, v, torre, posible, acolocadas, rcolocadas, vcolocadas);

		torre.pop_back();
		r++;
		rcolocadas--;
	}

	if (v > 0 && torre.size() < altura && torre[torre.size() - 1] != "verde"  && vcolocadas < acolocadas) {

		torre.push_back("verde");
		v--;
		vcolocadas++;

		if (rcolocadas > acolocadas + vcolocadas && torre.size() == altura) {
			mostrar(torre);
			posible = true;
		}

		construccion(altura, a, r, v, torre, posible, acolocadas, rcolocadas, vcolocadas);

		torre.pop_back();
		v++;
		vcolocadas--;
	}
}

bool resuelveCaso() {
	int altura, a, r, v;
	vector<string> torre;
	bool posible = false;
	int acolocadas = 0;
	int rcolocadas = 0;
	int vcolocadas = 0;

	cin >> altura >> a >> r >> v;

	if (altura == 0 && a == 0 && r == 0 && v == 0)
		return false;

	if (r > 0) {

		torre.push_back("rojo");
		r--;
		rcolocadas++;

		construccion(altura, a, r, v, torre, posible, acolocadas, rcolocadas, vcolocadas);

		if (!posible)
			cout << "SIN SOLUCION\n";
	}

	else {
		cout << "SIN SOLUCION\n";
	}

	cout << '\n';

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
