//Beatriz Herguedas Pinedo

#include "deque_eda.h"

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
class extiendeDeque : public deque<T> {

public:

	using Nodo = typename deque<T>::Nodo;

	void mostrar() {
		Nodo *aux = this->fantasma->sig;

		for (int i = 0; i < this->nelems; i++) {
			cout << aux->elem;
			aux = aux->sig;

			if (i < this->nelems - 1)
				cout << " ";
		}

		cout << '\n';
	}

	void elimina() {
		this->nelems = 0;
		this->fantasma->sig = this->fantasma;
		this->fantasma->ant = this->fantasma;
	}

	void engorda(extiendeDeque<int> const &cola2) {

		Nodo *prim = this->fantasma->sig;
		Nodo *ult = this->fantasma->ant;
		Nodo *aux2 = nullptr;

		int i = 1;
		for (Nodo * aux = cola2.fantasma->sig; aux != cola2.fantasma; aux = aux2) {

			aux2 = aux->sig;
		
			if (i % 2 == 0) {
				aux->sig = this->fantasma;
				this->fantasma->ant = aux;
				aux->ant = ult;
				ult->sig = aux;
				this->nelems++;
			}

			else {
				this->fantasma->sig = aux;
				aux->ant = this->fantasma;
				aux->sig = prim;
				prim->ant = aux;
				this->nelems++;
			}

			prim = this->fantasma->sig;
			ult = this->fantasma->ant;

			i++;
		}
	}
};

void resuelveCaso() {
	int N, M, valor;
	extiendeDeque<int> cola1, cola2;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		cola1.push_back(valor);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> valor;
		cola2.push_back(valor);
	}

	cola1.engorda(cola2);
	cola2.elimina();
	cola1.mostrar();
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
