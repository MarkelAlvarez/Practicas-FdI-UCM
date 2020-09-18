/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 156 Ascensor.

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
	int pisoini, pisovec, pisodest;
	int recorr;
	cin >> pisoini;
	if (pisoini < 0)
		return false;
	else {
		cin >> pisovec;
		recorr = 0;
		while (pisovec >= 0) {
			cin >> pisodest;
			recorr = recorr + abs(pisoini - pisovec);
			recorr = recorr + abs(pisovec - pisodest);
			pisoini = pisodest;
			cin >> pisovec;
		}
		cout << recorr << endl;
		return true;
	}
} 
int main() {
	while (casoDePrueba()) {
	}
	return 0;
}

/*
   ACEPTA EL RETO. 156 Ascensor.

   Los casos de prueba no nos exprimen para pensar un algoritmo complicado,
   de tal manera que con llevar la cuenta del recorrido del ascensor desde su
   comienzo, al vecino, al destino lo podemos resolver.
*/