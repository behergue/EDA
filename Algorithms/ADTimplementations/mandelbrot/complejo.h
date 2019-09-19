#ifndef complejo_h
#define complejo_h

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


class complejo {

private:

	float real, imaginaria;

public:

	complejo() {};

	complejo(float r, float i) {
		this->real = r;
		this->imaginaria = i;
	}

	complejo operator+(complejo c) {
		complejo aux;
		aux.real = this->real + c.real;
		aux.imaginaria = this->imaginaria +c.imaginaria;
		return aux;
	}

	complejo operator*(complejo c) {
		complejo aux;
		aux.real = c.real * this->real - c.imaginaria * this->imaginaria;
		aux.imaginaria = this->real * c.imaginaria + this->imaginaria * c.real;
		return aux;
	}

	int modulo() {
		return sqrt(this->real * this->real + this->imaginaria * this->imaginaria);
	}

};
#endif // !complejo_h
