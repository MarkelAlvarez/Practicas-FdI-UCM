/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 140 Suma de Dígitos

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


int suma_digit(long long int n) {
	int r, digit;

	if (n < 10) {// Caso Base, cuando solo hay una cifra.
		cout << n;
		return n;
	}
	else { // Caso recursivo, hay más de una cifra.
		digit = n % 10;
		r = digit + suma_digit(n / 10);
		cout << " + " << digit;
		return r;
	}

}


bool resuelveCaso() {
	int suma;
	long long int num;
	cin >> num;

	if (num>=0) {
		suma = suma_digit(num);
		cout << " = " << suma << "\n";
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
   ACEPTA EL RETO. 140 Suma de Dígitos

   Como primer ejercicio de recursión, simplemente se pretende que entendamos
   la forma de hacer llamadas recursivas. Al tener la impresión COUT después
   de la llamada recursiva se mostrará por pantalla en orden inverso a la 
   entrada de recursión, es decir, se imprime primero el dígito de más peso
   que fue el último en llegar, después de realizar sucesivos n/10.

   Para realizar los ejercicios de recursión siempre usaremos una función
   intermedia resuelveCaso () para evitar tener que liberar memoria después
   de cada caso de prueba en caso de usar vectores. Se hace de forma automática.


*/