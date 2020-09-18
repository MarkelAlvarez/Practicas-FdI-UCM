/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 116 ¡Hola Mundo!

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
   ACEPTA EL RETO. 116 ¡Hola Mundo!

   Este ejercicio no reviste ninguna dificultad, sirve para familiarizarse
   con la estructura de entrada por consola del juez de Acepta El Reto. En 
   éste se detalla el número de casos de prueba al principio.
  
*/