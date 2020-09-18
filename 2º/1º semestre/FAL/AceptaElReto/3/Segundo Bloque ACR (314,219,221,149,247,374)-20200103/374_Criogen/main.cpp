/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 374 Criogenizaci�n.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
using namespace std;
void resuelvecaso() {
	unsigned int itmin = 1, itmax = 1;
	long long unsigned int min, max, aux;
	cin >> aux;
	min = aux;
	max = aux;
	cin >> aux;
	while (aux!=0) {
		if (max == aux) {
			++itmax;
		}
		if (min == aux) {
			++itmin;
		}
		if (aux > max) {
			max = aux;
			itmax = 1;
		}
		else if (aux < min) {
			min = aux;
			itmin = 1;
		}
		cin >> aux;
	}
	cout << min << " " << itmin << " " << max << " " << itmax << endl;
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
   ACEPTA EL RETO. 374 Criogenizaci�n.

   Ejercicio sencillo, si el elemento extra�do es MAX y/o MIN le sumamos 1 a
   la cuenta. Si aparece un valor nuevo ALTO o BAJO inicializamos el contador.
   No hacen falta vectores porque no es relevante la colocaci�n.

*/