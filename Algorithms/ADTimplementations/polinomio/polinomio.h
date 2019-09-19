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

struct monomio {
	int exponente, coeficiente;
};

#ifndef polinomio_h
#define polinomio_h

class polinomio {

private:

	vector<monomio> p;

public:

	polinomio() {};

	void anademonomio(monomio m) {
		if (m.coeficiente != 0) {

			if (this->p.size() == 0) {
				p.push_back(m);
			}

			else {

				int i = 0;
				bool encontrado = false;

				while (!encontrado && i < this->p.size()) {
					if (this->p[i].exponente == m.exponente) {
						encontrado = true;
						this->p[i].coeficiente += m.coeficiente;
					}

					else if (this->p[i].exponente > m.exponente) {
						this->p.insert(this->p.begin() + i, 1, m);
						encontrado = true;
					}
					i++;
				}

				if (!encontrado) {
					this->p.push_back(m);
				}
			}
		}
	}

	int evaluar(int n) {
		int aux = 0;
		for (int i = 0; i < this->p.size(); i++) {
			aux += this->p[i].coeficiente * pow(n, this->p[i].exponente);
		}
		return aux;
	}
};

#endif