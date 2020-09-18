/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 156 Ascensor.

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