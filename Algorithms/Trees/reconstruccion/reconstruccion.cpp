//Beatriz Herguedas Pinedo, DG209

#include "bintree_eda.h"

int busqueda(int num, vector<int> const &v) {
	int i = 0;
	int sol = 0;
	bool encontrado = false;

	while (!encontrado && i < v.size()) {

		if (v[i] == num) {
			sol = i;
			encontrado = true;
		}

		i++;
	}

	return sol;
}

bintree<int> reconstruccion(queue<int> &cola, vector<int> const& v) {

	if (v.empty()) {
		return {};
	}

	else {
		int aux = cola.front();
		cola.pop();

		int pos = busqueda(aux, v);

		vector<int> v1(v.begin(), v.begin() + pos);
		vector<int> v2(v.begin() + pos + 1, v.end());

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
	stringstream ss1(linea);
	int valor;

	while (ss1 >> valor) {
		cola.push(valor);
	}

	getline(cin, linea);
	stringstream ss2(linea);

	while (ss2 >> valor) {
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