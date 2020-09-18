/*#include <iostream>

using namespace std;
void algorithm(int* v, int numed, int &comienzo, int &final, int altura);

int main() {
	int numcasos, numed, altura, comienzo = 1, final= 0;
	int*v;
	cin >> numcasos;
	for (int i = 0; i < numcasos; i++) {
		cin >> numed;
		cin >> altura;
		v = new int[numed];
		for (int j = 0; j < numed; j++) {
			cin >> v[j];
		}

		algorithm(v, numed, comienzo, final, altura);

		cout << comienzo << " " << final << endl;
		comienzo = 1; final = 0;

	}




	return 0;
}

void algorithm(int* v, int numed, int &comienzo, int &final, int altura) {
	int capacidad = 0;

	for (int i = 0; i < numed; i++) {
		if (v[i] > altura) {
			capacidad++;
		}
		else {
			if (capacidad != 0 && final - comienzo + 1 < capacidad) {
				comienzo = i - capacidad;
				final = i - 1;
				capacidad = 0;
			}
		}
	}
	




}*/