//Beatriz Herguedas Pinedo

#include <iostream>
#include <fstream>

using namespace std;

#include "queue_eda.h"

template <class T>

class InvierteSegmento : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:
	// imprime la lista enlazada
	void print(std::ostream & o = std::cout) const {

		Nodo *aux = this->prim;

		for (int i = 0; i < this->nelems; i++) {
			cout << aux->elem;
			aux = aux->sig;

			if (i < this->nelems - 1)
				cout << " ";
		}
	}

	// invierte el segmento que comienza en la posición P y tiene longitud L
	void invierte(size_t P, size_t L) {

		Nodo* aux = this->prim;

		if (P > 1) {

			int i = 0;
			for (i = 0; i + 2 < P; ++i) {
				aux = aux->sig;
			}

			Nodo* ant = aux;

			for (int j = i; j + 2 < L + P; ++j) {
				aux = aux->sig;
			}

			Nodo* ult = aux;

			for (int i = 0; i < L - 1; ++i) {
				Nodo* next = ant->sig;
				ant->sig = (ant->sig)->sig;
				next->sig = ult->sig;
				ult->sig = next;
			}
		}

		else if (P == 1) {

			for (int i = 0; i + 1 < L; ++i) {
				aux = aux->sig;
			}

			Nodo* fin = aux;

			for (int i = 0; i < L - 1; ++i) {
				Nodo* next = this->prim->sig;
				this->prim->sig = fin->sig;
				fin->sig = this->prim;
				this->prim = next;
			}
		}
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, InvierteSegmento<T> const& lista) {
	lista.print(o);
	return o;
}

bool resuelveCaso() {
	int N, P, L;
	cin >> N >> P >> L;
	if (!cin)
		return false;

	InvierteSegmento<int> lista;
	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		lista.push(num);
	}

	lista.invierte(P, L);

	cout << lista << '\n';

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