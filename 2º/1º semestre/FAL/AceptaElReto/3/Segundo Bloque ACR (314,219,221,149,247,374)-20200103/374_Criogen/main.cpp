/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 374 Criogenización.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
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
   ACEPTA EL RETO. 374 Criogenización.

   Ejercicio sencillo, si el elemento extraído es MAX y/o MIN le sumamos 1 a
   la cuenta. Si aparece un valor nuevo ALTO o BAJO inicializamos el contador.
   No hacen falta vectores porque no es relevante la colocación.

*/