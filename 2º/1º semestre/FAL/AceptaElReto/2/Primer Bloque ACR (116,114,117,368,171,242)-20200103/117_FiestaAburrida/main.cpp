/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 117 La Fiesta Aburrida.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
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

   La obtenci�n del nombre se puede realizar con 2 "cin" consecutivos
   o bien con un "getline" y un "erase" sabiendo que siempre son 4 caracteres
   los que se tienen que eliminar del comienzo de la cadena, "Soy ".
   El resultado es igual. Si se usa getline es necesario poner un getchar()
   para que se elimine del buffer el '\n' dejado por el n�mero de casos.

*/