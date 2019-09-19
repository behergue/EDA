#ifndef set_h
#define set_h

#include <algorithm>
#include <assert.h>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class set {

public:

	set(size_t tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e);
	bool contains(T e, int &pos) const;
	void erase(T e);
	bool empty() const;
	size_t size() const;
	T consultaMenor() const;
	void eliminarMenor();
	T* getDatos();

private:

	const static size_t TAM_INICIAL = 8;
	size_t contador;
	size_t capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
};

template <class T>
T* set<T>::getDatos() {
	return datos;
}

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
	libera();
}

template <class T>
void set<T>::libera() {
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
	int pos = 0;
	if (!contains(e, pos)) {
		if (contador == capacidad)
			amplia();

		for (int i = contador; i > pos; i--) {
			datos[i] = datos[i - 1];
		}

		datos[pos] = e;
		contador++;
	}
}

template <class T>
bool set<T>::contains(T e, int &pos) const {
	size_t i = 0;
	int ini = 0, fin = contador - 1;
	bool encontrado = false;

	while (!encontrado && ini <= fin) {
		int mitad = (ini + fin) / 2;

		if (datos[mitad] == e) {
			pos = mitad;
			encontrado = true;
		}

		else if (datos[mitad] < e)
			ini = mitad + 1;

		else
			fin = mitad - 1;
	}

	if (!encontrado)
		pos = ini;

	return encontrado;
}

template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;

	datos[i] = datos[contador - 1];
	--contador;
}


template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
size_t set<T>::size() const {
	return contador;
}

template <class T>
T set<T>::consultaMenor() const {
	return datos[0];
}

template <class T>
void set<T>::eliminarMenor() {

	if (contador > 0) {
		for (int i = 0; i < contador; i++) {
			datos[i] = datos[i + 1];
		}
		contador--;
	}
}

template <class T>
inline ostream & operator <<(ostream & out, set<T> conjunto) {
	T* dat = conjunto.getDatos();
	for (int i = 0; i < conjunto.size(); ++i) {
		out << dat[i];
		if (i < conjunto.size() - 1)
			out << " ";
	}
	out << '\n';
	return out;
}

#endif