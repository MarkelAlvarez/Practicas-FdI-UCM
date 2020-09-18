/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 314 Temperaturas Extremas.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
aceptado por el juez.
*/

#include <iostream>
#include <vector>
using namespace std;

void resuelvecaso() {
	int temps, pic, vall, i, lim, aux;
	vector <int> v;

	cin >> temps;
	for (i = 0; i < temps; ++i) {
		cin >> aux;
		v.push_back(aux);
	}
	if (temps < 3) {
		cout << "0 0\n";
	}
	else {
		lim = temps - 1;
		pic = 0;
		vall = 0;
		for (i = 1; i < lim; ++i) {
			if ((v[i] < v[i - 1]) && (v[i] < v[i + 1])) {
				++vall;
			}
			else if ((v[i] > v[i - 1]) && (v[i] > v[i + 1])) {
				++pic;
			}
		}
		cout << pic << " " << vall << "\n";
	}
}

int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		resuelvecaso();
	}
	return 0;
}
/*
   ACEPTA EL RETO. 314 Temperaturas Extremas.

   Es un algoritmo iterativo lineal sin demasiada ciencia. La cualidad
   de pico o valle solo exige conocer 3 valores juntos de forma que se
   podr�a evitar usar un vector trabajando con 3 variables locales. No
   habr�an grandes cambios y como la capacidad de memoria no da fallo, 
   no hay necesidad.
*/