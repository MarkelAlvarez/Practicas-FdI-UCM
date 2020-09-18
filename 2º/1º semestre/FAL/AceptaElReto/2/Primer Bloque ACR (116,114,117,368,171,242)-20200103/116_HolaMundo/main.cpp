/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 116 �Hola Mundo!

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


void resuelveCaso() {
	cout << "Hola mundo.\n";
}

int main() {

	unsigned int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	return 0;
}

/*
   ACEPTA EL RETO. 116 �Hola Mundo!

   Este ejercicio no reviste ninguna dificultad, sirve para familiarizarse
   con la estructura de entrada por consola del juez de Acepta El Reto. En 
   �ste se detalla el n�mero de casos de prueba al principio.
  
*/