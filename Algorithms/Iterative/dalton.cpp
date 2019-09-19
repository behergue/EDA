//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

bool Dalton(vector<int> const & alturas) {

	bool dalton;

	if (alturas[0] > alturas[1]) {
		int i = 0;
		dalton = true;
		while (i < alturas.size() - 1 && dalton) {
			if (alturas[i] <= alturas[i + 1])
				dalton = false;
			i++;
		}
	}

	else if (alturas[0] < alturas[1]) {
		int i = 0;
		dalton = true;
		while (i < alturas.size() - 1 && dalton) {
			if (alturas[i] >= alturas[i + 1])
				dalton = false;
			i++;
		}
	}

	else {
		dalton = false;
	}

	return dalton;
}

bool resuelveCaso() {
	int N, valor;
	vector<int> alturas;
	
	cin >> N;

	if (N == 0) 
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		alturas.push_back(valor);
	}

	if (Dalton(alturas))
		cout << "DALTON\n";

	else
		cout << "DESCONOCIDOS\n";

	return true;
}

int main() {
	while (resuelveCaso()); 
	return 0; 
}
