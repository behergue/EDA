
// Beatriz Herguedas Pinedo

/*
	La solucion consiste en almacenar en un mapa no ordenado los elementos y su posicion
	en el vector ordenado, y en dicho vector almacenar el elemento y su numero de 
	apariciones. Por tanto, debemos recorrer una vez la entrada con coste lineal en N (ya que
	el acceso a un mapa no ordenado es constante, y la insercion por el final en un vector
	tambien), y luego para mostrar la salida debemos recorrer el vector otra vez, con coste
	lineal en el numero de elementos. Por tanto, el coste final es lineal en N, siendo N
	la cantidad de numeros de la entrada.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

bool resuelveCaso() {
	// mapa de cada elemento a su posicion en lel vector ordenado
	unordered_map<int, int> mapa;
	// vector de los elementos y su numero de apariciones, ordenado segun aparecen
	vector<pair<int, int>> v;
	int N, valor;
	cin >> N;
	if (!cin)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;

		auto it = mapa.find(valor);

		if (it == mapa.end()) {
			v.push_back({ valor, 1 });
			mapa.insert({ valor, v.size() - 1});
		}

		else
			v[it->second].second++;
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << '\n';

	cout << "---\n";
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
