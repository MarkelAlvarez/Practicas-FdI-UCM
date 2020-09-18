/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 117 La Fiesta Aburrida.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/

#include <iostream>
#include <string>
using namespace std;

void resuelveCaso() {
	string cadena;
	getline(cin, cadena);
	cadena.erase(0, 4);
	cout << "Hola, " << cadena << ".\n";
} 

int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	getchar();
	for (i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	return 0;
}

/*
   ACEPTA EL RETO. 117 La Fiesta Aburrida.

   La obtención del nombre se puede realizar con 2 "cin" consecutivos
   o bien con un "getline" y un "erase" sabiendo que siempre son 4 caracteres
   los que se tienen que eliminar del comienzo de la cadena, "Soy ".
   El resultado es igual. Si se usa getline es necesario poner un getchar()
   para que se elimine del buffer el '\n' dejado por el número de casos.

*/