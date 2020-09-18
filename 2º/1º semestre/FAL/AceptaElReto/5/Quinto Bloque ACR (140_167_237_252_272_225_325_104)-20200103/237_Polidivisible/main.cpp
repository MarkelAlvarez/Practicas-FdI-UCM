/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 237 N�meros polidivisibles

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


bool polidiv(long long int n, int& divs) {
	bool divisible;

	if (n<10) { // Caso base. Con una sola cifra.
		divisible = true;
		++divs;
	}
	else { // Caso recursivo. M�s de una cifra.
		divisible = polidiv(n/10, divs);
		divisible = divisible && ((n % divs) == 0); // Resto cero, es divisible entre divs.
		++divs;
	}	
	
	return divisible;
}


bool resuelveCaso() {
	long long int n;
	int divs;

	cin >> n;
	if (cin) {
		divs = 1;
		if (polidiv(n, divs)) {
			cout << "POLIDIVISIBLE\n";
		}
		else {
			cout << "NO POLIDIVISIBLE\n";
		}
		return true;
	}
	else {
		return false;
	}
}

int main() {

	while (resuelveCaso()) {

	}

	return 0;
}
/*
   ACEPTA EL RETO. 237 N�meros polidivisibles

   Utilizamos un par�metro por referencia en la recursi�n para dar salida
   al n�mero de divisiones que se han realizado. Como hacemos las llamadas
   recursivas antes de incrementar ++divs, llega en primer t�rmino al d�gito
   final con valor 1 y despu�s va increment�ndose a medida que sale y vamos
   evaluando la polidivisibilidad desde el final (desde el final si miramos
   el dibujo del enunciado).

   En definitiva "divs" nos permite conocer el n�mero de d�gitos que tiene el 
   paso recursivo en cuesti�n, sin tener que pregunt�rselo a la "n".
*/