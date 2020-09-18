/*#include <iostream>

using namespace std;
int algorithm(int* v, int numero);

int main() {
	int casosprueba, numero;
	int *v;

	cin >> casosprueba;
	for (int i = 0; i < casosprueba; i++) {
		cin >> numero;
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
	int posicion = -1, counter = 0;

	while (counter < numero && posicion == -1) {
		if (counter % 2 == 1 && v[counter] != v[counter - 1]) {
			posicion = counter - 1;
		}
		else if (counter % 2 == 0 && counter == numero - 1) {
			posicion = counter;
		}
		counter++;
	}


	return posicion;
}*/