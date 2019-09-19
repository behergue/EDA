//Beatriz Herguedas Pinedo, DG209

#include "queue_eda.h"

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template<class T>
class extiendeQueue: public queue<T>{

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

	void insertar(extiendeQueue<int> colaSecundaria, int pos) {

		if (pos == 0) {
			colaSecundaria.ult->sig = this->prim;
			this->prim = colaSecundaria.prim;
		}

		else if (pos == this->nelems) {
			this->ult->sig = colaSecundaria.prim;
			this->ult = colaSecundaria.ult;
		}

		else {
			Nodo *aux = this->prim;

			for (int i = 0; i < pos - 1; i++) {
				aux = aux->sig;
			}

			Nodo *aux2 = aux->sig;

			aux->sig = colaSecundaria.prim;
			colaSecundaria.ult->sig = aux2;

		}

		this->nelems += colaSecundaria.nelems;

		colaSecundaria.nelems = 0;
		colaSecundaria.prim = nullptr;
		colaSecundaria.ult = nullptr;
	}
};


bool resuelveCaso() {
	int N, valor;
	extiendeQueue<int> colaPrincipal;

	cin >> N;

	if (!std::cin)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		colaPrincipal.push(valor);
	}

	int M, P;
	extiendeQueue<int> colaSecundaria;

	cin >> M >> P;

	for (int i = 0; i < M; i++) {
		cin >> valor;
		colaSecundaria.push(valor);
	}

	colaPrincipal.insertar(colaSecundaria, P);
	colaPrincipal.mostrar();

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