//Beatriz Herguedas Pinedo

#include "queue_eda.h"
#include "horas.h"

#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template<class T>
class extiendeQueue : public queue<T> {

public:

	using Nodo = typename queue<T>::Nodo;

	void mostrar() {
		Nodo *aux = this->prim;

		for (int i = 0; i < this->nelems; i++) {
			cout << aux->elem;
			aux = aux->sig;

			if (i < this->nelems - 1)
				cout << " ";
		}

		cout << '\n';
	}

	void borracada2() {

		if (this->nelems > 1) {
			Nodo *aux = this->prim;
			Nodo *aux2 = nullptr;

			while (aux != nullptr && aux->sig != nullptr) {
				aux2 = aux->sig;
				aux->sig = aux2->sig;
				aux = aux->sig;
				this->nelems--;
			}

			if (aux != nullptr && aux->sig == nullptr)
				this->ult = aux;
		}
	}
};

bool resuelveCaso() {
	int num;
	horas aux;
	extiendeQueue<horas> cola;

	cin >> num;

	if (num == 0)
		return false;

	for (int i = 0; i < num; i++) {
		cin >> aux;
		cola.push(aux);
	}

	cola.borracada2();
	cola.mostrar();

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
