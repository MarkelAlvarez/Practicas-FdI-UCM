/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 114 �ltimo d�gito del Factorial.

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
	unsigned int n,f;

	cin >> n;

	switch (n) {
	case 0: f = 1;
		break;
	case 1: f = 1;
		break;
	case 2: f = 2;
		break;
	case 3: f = 6;
		break;
	case 4: f = 4;
		break;
	default: f = 0;
		}
	
	cout << f << "\n";

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
   ACEPTA EL RETO. 114 �ltimo d�gito del Factorial.

   Realizar un algoritmo iterativo o recursivo para calcular el factorial
   y despu�s obtener el �ltimo d�gito con %10 ser�a una tarea muy costosa.
   Es f�cil fijarse en que cualquier factorial por encima de 4 estar� 
   multiplicado por 2 y 5, por lo tanto siempre acaba en 0. Un switch
   es una soluci�n razonable.
*/