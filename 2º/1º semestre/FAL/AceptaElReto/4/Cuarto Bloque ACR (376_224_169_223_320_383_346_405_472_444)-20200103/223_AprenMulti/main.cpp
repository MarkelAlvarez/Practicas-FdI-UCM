/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 223 Aprendiendo a Multiplicar.

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

void casoDePrueba() {
	long int numelements, aux, max_ancho = 0, ini = 0, ancho = 0, ini_max = 0;

	cin >> numelements;

	for (int k = 0; k < numelements; ++k) {
		cin >> aux;
		if (aux!=0) {
			++ancho;
		}
		else {
			if (ancho > max_ancho) {
				max_ancho = ancho;
				ini_max = ini;
			}
			ini = k + 1;
			ancho = 0;
		}
	}
	if (ancho > max_ancho) { 
		max_ancho = ancho;
		ini_max = ini;
	}

	if (max_ancho>0) {
		cout << max_ancho << " -> [" << ini_max << "," << ini_max+max_ancho-1 << "]" << endl;
	}
	else {
		cout << "SIGUE BUSCANDO" << endl;
	}
}

int main() {
	int numcasos;

	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		casoDePrueba();
	}

	return 0;
}
/*
   ACEPTA EL RETO. 223 Aprendiendo a Multiplicar.

   En este problema no necesitamos un array puesto que se puede
   procesar cada elemento según se adquiere. No hay que retroceder
   o buscar en posiciones anteriores por ninguna razón.

   No tiene mucha exigencia, solo tenemos que ir anotando el punto
   de comienzo del intervalo cuando se encuentre un cero y la cantidad 
   de elementos que acaba de superar a la anterior.

   Cuidado al escribir el formato de la salida.

*/