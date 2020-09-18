/*#include <iostream>

using namespace std;

int main() {
	int numfilas, numcolumnas, ancho, colfranjas, numceros;
	int numero, contadorcol, contadorcasos;
	int *ceros;

	while (cin >> numfilas) {
		cin >> numcolumnas;
		cin >> ancho >> colfranjas >> numceros;
		contadorcol = 0;
		contadorcasos = 0;
		ceros = new int[numcolumnas];
		for (int i = 0; i < numcolumnas; i++) {
			ceros[i] = 0;
		}

		for (int i = 0; i < numfilas*numcolumnas; i++) {
			cin >> numero;
			if (numero == 0) {
				ceros[i%numcolumnas]++;
			}
		}

		for (int i = 0; i < numcolumnas - ancho + 1; i++) {
			for (int j = i; j < i + ancho; j++) {
				if (ceros[j] >= numceros) {
					contadorcol++;
				}
			}
			if (contadorcol >= colfranjas) {
				contadorcasos++;
			}
			contadorcol = 0;
		}
		cout << contadorcasos << endl;
	}



	return 0;
}*/