//Beatriz Herguedas Pinedo

#include "bintree_eda.h"

int busqueda(int num, vector<int> const &v) {
	int i = 0;

	while (i < v.size() && v[i] <= num) {
		i++;
	}

	return i;
}

bintree<int> reconstruccion(queue<int> &cola, vector<int> const &v) {

	if (v.empty()) {
		return {};
	}

	else {
		int aux = cola.front();
		cola.pop();

		int pos = busqueda(aux, v);

		auto first = v.begin() + 1;
		auto mitad1 = v.begin() + pos;
		auto mitad2 = v.begin() + pos;
		auto fin = v.end();

		if (pos == 0) {
			first = v.begin();
			mitad2 = v.end();
		}

		vector<int> v1(first, mitad1);
		vector<int> v2(mitad2 , fin);

		bintree<int> izq = reconstruccion(cola, v1);
		bintree<int> dcha = reconstruccion(cola, v2);

		return{ izq, aux, dcha };
	}
}

bool resuelveCaso() {
	queue<int> cola;
	vector<int> v;
	string linea;

	getline(cin, linea);
	stringstream ss(linea);
	int valor;

	while (ss >> valor) {
		cola.push(valor);
		v.push_back(valor);
	}

	if (!std::cin)
		return false;

	bintree<int> arbol = reconstruccion(cola, v);

	vector<int> post = arbol.postorder();

	for (int i = 0; i < post.size(); i++) {

		cout << post[i];

		if (i < post.size() - 1)
			cout << ' ';
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
