#ifndef libreria_h
#define libreria_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;

using libro = string;
using existencias = int;

class libreria{

private:
	//mapa del libro a sus existencias en el sistema
	unordered_map<libro, existencias> sistema;
	//mapa del libro vendido a un iterador para encontrarlo en la lista
	map<libro, list<libro>::iterator> vendidos;
	//lista de libros vendidos y el numero de ejemplares vendidos
	list<pair<libro, int>> ventas;
public:

	void nuevoLibro(existencias n, libro x) {
		auto it = sistema.find(x);

		if (it == sistema.end())
			sistema.insert({ x, n });
	}

	void comprar(libro x) {
		auto it = sistema.find(x);

		if (it == sistema.end())
			throw invalid_argument("Libro no existente");

		if (it->second == 0)
			throw out_of_range("No hay ejemplares");

		auto it2 = vendidos.find(x);

		if (it2 == vendidos.end())
			vendidos.insert({ x, ventas.insert(ventas.end(), x)});

		else
			it2->second++;

		it->second--;
	}

	bool estaLibro(libro x) {
		auto it = sistema.find(x);

		if (it == sistema.end())
			return false;

		return true;
	}

	void elimLibro(libro x) {
		auto it = sistema.find(x);

		if (it != sistema.end())
			sistema.erase(it);
	}

	int numEjemplares(libro x) {
		auto it = sistema.find(x);

		if (it == sistema.end())
			throw invalid_argument("Libro no existente");

		return it->second;
	}

	list<libro> top10() {
		list<libro> lista;

		auto it = vendidos.begin();
		for (int i = 0; i < 10 && it != vendidos.end(); i++) {
			lista.push_back(it->first);
			it++;
		}
			
		return lista;
	}
};
#endif