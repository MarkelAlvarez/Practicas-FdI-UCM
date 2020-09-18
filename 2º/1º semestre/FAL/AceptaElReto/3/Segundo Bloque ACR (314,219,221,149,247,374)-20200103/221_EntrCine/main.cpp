/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 221 Entrando al Cine.

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

   En este caso no necesitamos vectores porque no se eval�an diferentes
   componentes por separado. Es suficiente con mirar uno por uno seg�n entran.
   Para evaluar la paridad es r�pido usar la AND l�gica con 1.

   Si la evaluaci�n de abrir termina antes de acabar el vector es necesario
   eliminar lo que queda de �l con "ignore" o un "getline".
   El cin.ignore() no usa memoria.
*/