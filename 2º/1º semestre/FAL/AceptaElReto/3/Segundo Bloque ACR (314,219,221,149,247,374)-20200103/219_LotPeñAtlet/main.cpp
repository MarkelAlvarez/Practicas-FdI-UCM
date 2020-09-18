/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 219 La lotería de la peña Atlética.

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
	int totalnum, i, boletos = 0, aux;

	cin >> totalnum;
	for (i = 0; i < totalnum; ++i) {
		cin >> aux;
		if ((aux % 2) == 0) { ++boletos; }
	}
	cout << boletos << endl;
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
   ACEPTA EL RETO. 219 La lotería de la peña Atlética.

   Solo hay que evaluar la paridad de cada boleto por separado.
   No nos exigen demasiado con los tiempos, pero si hubiera que
   acelerar el cálculo de la paridad lo podríamos hacer sabiendo
   que los enteros se almacenan en Complemento a 2.

   Prueba a cambiar la condición con una "AND" lógica:

   if ((aux & 1) == 0) { ++boletos; }
*/