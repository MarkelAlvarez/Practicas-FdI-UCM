/*#include <iostream>

using namespace std;

void algorithm(int* v, int numtemps, int &picos, int &valles);

int main() {
	int numcasos, numtemps,picos,valles;
	int *v;
	cin >> numcasos;
	for (int t = 0; t < numcasos; t++) {
		cin >> numtemps;
		picos = 0; 
		valles = 0;
		v = new int[numtemps];
		for (int i = 0; i < numtemps; i++) {
			cin >> v[i];
		}
		algorithm(v, numtemps, picos, valles);
		cout << picos << " " << valles << endl;
	}


	return 0;
}

void algorithm(int* v, int numtemps, int &picos, int &valles) {
	for (int i = 1; i < numtemps - 1; i++) {
		if (v[i - 1] < v[i] && v[i + 1] < v[i]) {
			picos += 1;
		}
		if (v[i - 1] > v[i] && v[i + 1] > v[i]) {
			valles += 1;
		}
	}
}*/