//Beatriz Herguedas Pinedo

#include "complejo.h"

bool mandelbrot(complejo c, int numit) {

	complejo z = complejo(0, 0);

	int i = 0;
	bool ok = true;
	while(ok && i < numit) {
		z = z * z + c;

		if (z.modulo() > 2)
			ok = false;

		i++;
	}

	return ok;
}


void resuelveCaso() {
	float r, i;
	int numit;

	cin >> r >> i >> numit;

	complejo c = complejo(r, i);

	if (mandelbrot(c, numit))
		cout << "SI\n";

	else
		cout << "NO\n";
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}