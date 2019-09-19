//Beatriz Herguedas Pinedo

#include "pelicula.h"

bool resuelveCaso() {
	int P;
	vector<pelicula> cine;
	horas ini, dur;
	string tit;

	cin >> P;

	if (P == 0)
		return false;

	try {

		for (int i = 0; i < P; i++) {
			cin >> ini >> dur;
			getline(cin, tit);
			cine.push_back({ ini, dur, tit });
		}

		sort(cine.begin(), cine.end());

		for (int i = 0; i < P; i++) {
			horas h = cine[i].getfin();
			cout << h << " " << cine[i].gettit() << '\n';
		}
	}

	catch (domain_error e) {
		cout << e.what() << '\n';
	}

	cout << "---\n";

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