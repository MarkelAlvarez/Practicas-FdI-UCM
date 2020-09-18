/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 149 San Fermines.

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
   las velocidades de los toros y quedarse con la m�s alta. No es suficiente con "int".

   El esquema de entrada por consola es del tipo que acaba simplemente si ya no quedan
   datos. Para ello hay que evaluar si "cin" dio error para salir del programa. De no
   hacerlo el juez devolver� TLE.
*/