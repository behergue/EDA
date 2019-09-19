//Beatriz Herguedas Pinedo, DG209

#include "queue_eda.h"

#include <algorithm>
#include <assert.h>
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

	// Mezclar los nodos de dos listas ordenadas
	void intercalar(extiendeQueue<int> & colaSecundaria) {
		Nodo* aux = this->prim;
		Nodo* aux2 = colaSecundaria.prim;

		//la primera lista está vacía
		if (!colaSecundaria.empty()) {
			if (this->empty()) {
				this->prim = colaSecundaria.prim;
				this->ult = colaSecundaria.ult;
				this->nelems = colaSecundaria.nelems;
			}

			else {
				while (aux2 != nullptr) {
					//insertar al principio
					if (aux == this->prim && aux->elem >= aux2->elem) {
						Nodo* auxSig = aux2->sig;
						aux2->sig = aux;
						this->prim = aux2;
						aux = aux2;
						aux2 = auxSig;
						this->nelems++;
					}

					//insertar al final
					else if (aux == this->ult && aux->elem <= aux2->elem) {
						Nodo* auxSig = aux2->sig;
						aux2->sig = aux->sig;
						aux->sig = aux2;
						this->ult = aux2;
						aux2 = auxSig;
						aux = aux->sig;
						this->nelems++;
					}

					else if (aux->elem <= aux2->elem && aux->sig->elem >= aux2->elem) {
						Nodo* auxSig = aux2->sig;
						aux2->sig = aux->sig;
						aux->sig = aux2;
						aux2 = auxSig;
						aux = aux->sig;
						this->nelems++;
					}

					else {
						aux = aux->sig;
					}
				}
			}

			//vaciar lista
			colaSecundaria.prim = nullptr;
			colaSecundaria.ult = nullptr;
			colaSecundaria.nelems = 0;
		}
	}

	/*void intercalar(extiendeQueue<int> colaSecundaria) {

		//si la cola principal no esta vacia
		if (!this->empty()) {
			Nodo *aux = this->prim;
			Nodo *aux2 = this->prim->sig;
			Nodo *j = nullptr;

			if (colaSecundaria.prim->elem < aux->elem) {
				Nodo *p = colaSecundaria.prim->sig;
				colaSecundaria.prim->sig = aux;
				this->prim = colaSecundaria.prim;
				colaSecundaria.prim = p;
			}

			//recorro la cola secundaria
			for (Nodo *i = colaSecundaria.prim; i != nullptr; i = j) {

				if (aux2 == nullptr) {
					if (i->elem >= aux->elem) {
						j = nullptr;
						aux->sig = i;
						this->ult = colaSecundaria.ult;
					}
				}

				else if (i->elem < aux2->elem && i->elem >= aux->elem) {
					j = i->sig;
					aux->sig = i;
					i->sig = aux2;
				}

				else {
					j = i;
					if(aux != nullptr)
						aux = aux->sig;
					if(aux != nullptr)
						aux2 = aux->sig;
				}
			}

			this->nelems += colaSecundaria.nelems;
		}

		//si la cola principal esta vacia
		else {
			this->prim = colaSecundaria.prim;
			this->ult = colaSecundaria.ult;
			this->nelems = colaSecundaria.nelems;
		}

		colaSecundaria.nelems = 0;
		colaSecundaria.prim = nullptr;
		colaSecundaria.ult = nullptr;
	}*/

	/*void intercalar(extiendeQueue<int> colaSecundaria) {

		if (!colaSecundaria.empty()) {

			if (this->empty()) {
				this->prim = colaSecundaria.prim;
				this->ult = colaSecundaria.ult;
				this->nelems = colaSecundaria.nelems;
			}

			else if (this->nelems == 1) {

				if (colaSecundaria.nelems == 1) {
					if (this->prim <= colaSecundaria.prim) {
						this->prim->sig = colaSecundaria.prim;
						this->ult = colaSecundaria.prim;
					}
					else {
						colaSecundaria.prim->sig = this->prim;
						this->prim = colaSecundaria.prim;
					}
				}

				else {
					Nodo *aux = colaSecundaria.prim;
					Nodo *aux2 = nullptr;

					if (this->prim->elem < aux->elem) {
						this->prim->sig = aux;
						this->ult = colaSecundaria.ult;
					}

					else {
						bool ok = false;
						bool insertado = false;
						while (!ok && !insertado) {

							if (this->prim->elem >= aux->elem && this->prim->elem < aux->sig->elem) {
								aux2 = aux->sig;
								aux->sig = this->prim;
								this->prim->sig = aux2;
								this->prim = colaSecundaria.prim;
								this->ult = colaSecundaria.ult;
								insertado = true;
							}

							else {
								aux = aux->sig;
								if (aux == colaSecundaria.ult) {
									ok = true;
								}
							}
						}

						if (!insertado) {
							colaSecundaria.ult->sig = this->prim;
							this->prim = colaSecundaria.prim;
							this->ult = colaSecundaria.ult;
						}
					}
				}

				this->nelems += colaSecundaria.nelems;
			}

			else {
				Nodo *auxPrin = this->prim;
				Nodo *auxSec = colaSecundaria.prim;
				Nodo *aux = nullptr;
				Nodo *aux2 = nullptr;

				if (auxSec->elem < auxPrin->elem) {
					aux = auxSec->sig;
					auxSec->sig = auxPrin;
					auxPrin = auxSec;
					this->prim = auxSec;
					auxSec = aux;
				}

				bool terminado = false;
				while (!terminado){

					if (auxSec->elem >= auxPrin->elem && auxSec->elem < auxPrin->sig->elem) {
						aux = auxPrin->sig;
						aux2 = auxSec->sig;
						auxPrin->sig = auxSec;
						auxSec->sig = aux;
						auxPrin = auxSec;
						auxSec = aux2;
					}

					else {
						auxPrin = auxPrin->sig;
					}

					if (auxPrin == this->ult || auxSec == nullptr) {
						terminado = true;
					}

				}

				if (terminado && auxSec != nullptr) {
					auxPrin->sig = auxSec;
				}

				this->nelems += colaSecundaria.nelems;
			}

			colaSecundaria.nelems = 0;
			colaSecundaria.prim = nullptr;
			colaSecundaria.ult = nullptr;
		}
	}*/
};


void resuelveCaso() {
	int valor;
	extiendeQueue<int> colaPrincipal;
	extiendeQueue<int> colaSecundaria;

	cin >> valor;

	while(valor != 0) {
		colaPrincipal.push(valor);
		cin >> valor;
	}

	cin >> valor;

	while (valor != 0) {
		colaSecundaria.push(valor);
		cin >> valor;
	}


	colaPrincipal.intercalar(colaSecundaria);
	colaPrincipal.mostrar();
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