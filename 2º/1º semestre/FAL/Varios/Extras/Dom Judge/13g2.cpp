/*#include <iostream>

using namespace std;

int tamSegmentoMaximo(int* v, int n);
bool iguales(int* v, int a, int b);

int main() {
	int n, numero, counter, tamano;
	int *v = new int[100000];

	while (cin >> n && n != -1) {
		v[0] = n;
		counter = 1;
		while (cin >> numero && numero != -1) {
			v[counter] = numero;
			counter++;
		}
		tamano = tamSegmentoMaximo(v, counter);
		if (tamano == 0) {
			cout << "HOY NO COMEN" << endl;
		}
		else {
			cout << tamano << endl;
		}
	}

	return 0;
}

int tamSegmentoMaximo(int* v, int n) {
	int tam = 0, temp;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (j - i > tam) {
				if (iguales(v, i, j)) {
					tam = j - i;
				}
			}
		}
	}
	return tam;
}

bool iguales(int* v, int a, int b) {
	bool iguales = true;
	int numero = v[a];

	for (int i = a + 1; i <= b; i++) {
		if (v[i] != numero) {
			iguales = false;
		}
	}
	return iguales;
}*/