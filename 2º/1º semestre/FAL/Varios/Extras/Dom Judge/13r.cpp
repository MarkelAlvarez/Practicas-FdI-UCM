/*#include <iostream>

using namespace std;
int algorithm(int *v, int numero);

int main() {
	int numero;
	int* v;

	while (cin >> numero) {
		v = new int[numero];
		for (int i = 0; i < numero; i++) {
			cin >> v[i];
		}
		cout << algorithm(v, numero) << endl;

		delete[] v;
	}

	return 0;
}

int algorithm(int *v, int numero) {
	bool increasing = false, decreasing = false;
	int posicion = 1, counter = 1;

	while (posicion == 1 && counter < numero) {
		if (v[counter] > v[counter - 1]) {
			increasing = true;
		}
		if (v[counter] < v[counter - 1]) {
 
			decreasing = true;
		}
		


	}


	int posicion;
}*/