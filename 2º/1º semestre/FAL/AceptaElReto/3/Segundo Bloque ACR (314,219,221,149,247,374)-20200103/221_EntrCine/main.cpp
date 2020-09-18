/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 221 Entrando al Cine.

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
	int espectadores, i, asientos, aux;
	bool impar = false , abrir = true;

	cin >> espectadores;

	i = 0;
	asientos = espectadores;
	while (i < espectadores && abrir) {
		cin >> aux;
		if ((aux & 1) == 1) { 
			impar = true; 
			--asientos;
		}
		else if (impar) { 
			abrir = false;
			cin.ignore(65536, '\n');
		}
		++i;
	}
	if (abrir) {
		cout << "SI " << asientos << endl;
	}
	else {
		cout << "NO"<< endl;
	}

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
   ACEPTA EL RETO. 221 Entrando al Cine.

   En este caso no necesitamos vectores porque no se evalúan diferentes
   componentes por separado. Es suficiente con mirar uno por uno según entran.
   Para evaluar la paridad es rápido usar la AND lógica con 1.

   Si la evaluación de abrir termina antes de acabar el vector es necesario
   eliminar lo que queda de él con "ignore" o un "getline".
   El cin.ignore() no usa memoria.
*/