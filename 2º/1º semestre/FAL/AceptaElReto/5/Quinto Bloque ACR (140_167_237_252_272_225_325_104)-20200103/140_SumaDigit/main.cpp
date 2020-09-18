/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 140 Suma de D�gitos

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


int suma_digit(long long int n) {
	int r, digit;

	if (n < 10) {// Caso Base, cuando solo hay una cifra.
		cout << n;
		return n;
	}
	else { // Caso recursivo, hay m�s de una cifra.
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
   ACEPTA EL RETO. 140 Suma de D�gitos

   Como primer ejercicio de recursi�n, simplemente se pretende que entendamos
   la forma de hacer llamadas recursivas. Al tener la impresi�n COUT despu�s
   de la llamada recursiva se mostrar� por pantalla en orden inverso a la 
   entrada de recursi�n, es decir, se imprime primero el d�gito de m�s peso
   que fue el �ltimo en llegar, despu�s de realizar sucesivos n/10.

   Para realizar los ejercicios de recursi�n siempre usaremos una funci�n
   intermedia resuelveCaso () para evitar tener que liberar memoria despu�s
   de cada caso de prueba en caso de usar vectores. Se hace de forma autom�tica.


*/