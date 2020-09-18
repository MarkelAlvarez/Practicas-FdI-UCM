/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 114 Último dígito del Factorial.

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
   ACEPTA EL RETO. 114 Último dígito del Factorial.

   Realizar un algoritmo iterativo o recursivo para calcular el factorial
   y después obtener el último dígito con %10 sería una tarea muy costosa.
   Es fácil fijarse en que cualquier factorial por encima de 4 estará 
   multiplicado por 2 y 5, por lo tanto siempre acaba en 0. Un switch
   es una solución razonable.
*/