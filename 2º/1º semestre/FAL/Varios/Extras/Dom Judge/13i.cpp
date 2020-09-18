/*#include <iostream>
#include <vector>

using namespace std;

void algorithm(vector<int> v, vector<int> &sol, int suma);

int main() {
	int numero, suma;
	vector<int> v, sol;

	while (cin >> numero && numero != 0) {
		v.push_back(numero);
		suma = numero;
		while (cin >> numero && numero != 0) {
			v.push_back(numero);
			suma += numero;
		}
		algorithm(v, sol, suma);
		for (int i = 0; i < sol.size(); i++) {
			cout << sol[i];
			if (i != sol.size() - 1) {
				cout << " ";
			}
		}
		cout << endl;
		v.erase(v.begin(),v.end());
		sol.erase(sol.begin(), sol.end());
	}


	return 0;
}

void algorithm(vector<int> v, vector<int> &sol, int suma) {
	sol.push_back(suma);
	for (int i = 0; i < v.size() - 1; i++) {
		suma -= v[i];
		sol.push_back(suma);
	}
}*/