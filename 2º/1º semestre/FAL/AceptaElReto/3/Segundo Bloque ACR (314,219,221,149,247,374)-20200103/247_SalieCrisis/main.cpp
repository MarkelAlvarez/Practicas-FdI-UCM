/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 247 Saliendo de la Crisis.

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
   La �nica precauci�n que hay que tener es eliminar el array si quedaste
   a medias de la evaluaci�n con un "ignore".

   Las cantidades pueden ser grandes as� que usamos "long".
*/