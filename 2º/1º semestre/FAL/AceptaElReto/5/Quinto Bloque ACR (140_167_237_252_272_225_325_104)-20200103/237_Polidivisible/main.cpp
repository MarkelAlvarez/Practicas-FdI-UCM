/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 237 Números polidivisibles

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


bool polidiv(long long int n, int& divs) {
	bool divisible;

	if (n<10) { // Caso base. Con una sola cifra.
		divisible = true;
		++divs;
	}
	else { // Caso recursivo. Más de una cifra.
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
   ACEPTA EL RETO. 237 Números polidivisibles

   Utilizamos un parámetro por referencia en la recursión para dar salida
   al número de divisiones que se han realizado. Como hacemos las llamadas
   recursivas antes de incrementar ++divs, llega en primer término al dígito
   final con valor 1 y después va incrementándose a medida que sale y vamos
   evaluando la polidivisibilidad desde el final (desde el final si miramos
   el dibujo del enunciado).

   En definitiva "divs" nos permite conocer el número de dígitos que tiene el 
   paso recursivo en cuestión, sin tener que preguntárselo a la "n".
*/