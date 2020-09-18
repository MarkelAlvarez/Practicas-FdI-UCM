/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 219 La loter�a de la pe�a Atl�tica.

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
	int totalnum, i, boletos = 0, aux;

	cin >> totalnum;
	for (i = 0; i < totalnum; ++i) {
		cin >> aux;
		if ((aux % 2) == 0) { ++boletos; }
	}
	cout << boletos << endl;
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
   ACEPTA EL RETO. 219 La loter�a de la pe�a Atl�tica.

   Solo hay que evaluar la paridad de cada boleto por separado.
   No nos exigen demasiado con los tiempos, pero si hubiera que
   acelerar el c�lculo de la paridad lo podr�amos hacer sabiendo
   que los enteros se almacenan en Complemento a 2.

   Prueba a cambiar la condici�n con una "AND" l�gica:

   if ((aux & 1) == 0) { ++boletos; }
*/