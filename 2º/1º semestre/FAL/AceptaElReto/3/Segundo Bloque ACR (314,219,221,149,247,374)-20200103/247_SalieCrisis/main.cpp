/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 247 Saliendo de la Crisis.

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
	long unsigned int aux, max;
	long unsigned int medidas;
	bool crece = true;

	cin >> medidas;
	if (medidas == 0) { return false; }
	else {
		cin >> max;
		i = 1;
		while (crece && i < medidas) {
			cin >> aux;
			if (aux <= max) { 
				crece = false; 
				cin.ignore(65536, '\n');
			}
			else { max = aux; }
			++i;
		}
		if (crece) { cout << "SI\n"; }
		else { cout << "NO\n"; }
		return true;
	}
}
int main() {

	while (casoDePrueba()) {
	}

	return 0;
}
/*
   ACEPTA EL RETO. 247 Saliendo de la Crisis.

   Este ejercicio solo exige que los valores sean estrictamente crecientes.
   La única precaución que hay que tener es eliminar el array si quedaste
   a medias de la evaluación con un "ignore".

   Las cantidades pueden ser grandes así que usamos "long".
*/