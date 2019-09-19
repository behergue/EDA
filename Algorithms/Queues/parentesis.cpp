//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool resuelveCaso() {
	stack<char> pila;
	vector<char> v;
	string frase;

	getline(cin, frase);

	if (!std::cin)
		return false;

	for (auto c : frase) {
		v.push_back(c);
	}

	bool ok = true;
	int i = 0;
	while (ok && i < v.size()) {

		if (v[i] == '(' || v[i] == '[' || v[i] == '{') {
			pila.push(v[i]);
		}

		else if (v[i] == ')') {
			if (pila.empty() || pila.top() != '(')
				ok = false;
			else
				pila.pop();
		}

		else if (v[i] == ']') {
			if (pila.empty() || pila.top() != '[')
				ok = false;
			else
				pila.pop();
		}

		else if (v[i] == '}') {
			if (pila.empty() || pila.top() != '{')
				ok = false;
			else
				pila.pop();
		}

		i++;
	}

	if (!pila.empty())
		ok = false;

	if (ok)
		cout << "SI\n";

	else
		cout << "NO\n";

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
