/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 149 San Fermines.

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

bool casoDePrueba() {
	unsigned int i;
	long unsigned int aux, vel = 0;
	long unsigned int toros;
	cin >> toros;

	if (!cin) {
		return false;
	}
	else {
		for (i = 0; i < toros; ++i) {
			cin >> aux;
			if (aux > vel) { vel = aux; }
		}
		cout << vel << endl;
		return true;
	}
} 
int main() {
	while (casoDePrueba()) {
	}
	return 0;
}
/*
   ACEPTA EL RETO. 149 San Fermines.

   No nos exigen un algoritmo demasiado eficiente, es suficiente con ir tomando
   las velocidades de los toros y quedarse con la más alta. No es suficiente con "int".

   El esquema de entrada por consola es del tipo que acaba simplemente si ya no quedan
   datos. Para ello hay que evaluar si "cin" dio error para salir del programa. De no
   hacerlo el juez devolverá TLE.
*/