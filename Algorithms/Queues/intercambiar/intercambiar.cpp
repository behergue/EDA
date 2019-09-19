//Beatriz Herguedas Pinedo, DG209

#include "queue_eda.h"

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

	void intercambia() {

		if (this->nelems > 1) {

			Nodo *aux = this->prim;
			Nodo *aux2 = nullptr;
			Nodo *ant = nullptr;

			this->prim = aux->sig;

			while (aux != nullptr && aux->sig != nullptr) {
				aux2 = aux->sig;
				aux->sig = aux2->sig;
				aux2->sig = aux;
				if (ant != nullptr)
					ant->sig = aux2;
				ant = aux;
				if (aux->sig == nullptr)
					this->ult = aux;
				aux = aux->sig;
			}
		}
	}
};

bool resuelveCaso() {
	int N, valor;
	extiendeQueue<int> cola;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		cola.push(valor);
	}

	cola.intercambia();
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