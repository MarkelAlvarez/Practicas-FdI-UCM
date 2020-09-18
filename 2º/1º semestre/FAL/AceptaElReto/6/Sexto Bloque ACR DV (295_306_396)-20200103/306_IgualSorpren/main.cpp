/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 306 Dos Igualdades Sorprendentes

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

const long long int MAX = 46337;

struct m2p2 {
	long long int fm1; // Elemento A(0,0), es Fib(n-1)
	long long int f_n; // Elemento A(0,1) ó A(1,0), es Fib(n)
	long long int fp1; // Elemento A(1,1), es Fib(n+1)
};

m2p2 fibmatrix(long long int n) {
	m2p2 res, r1, r2;

	if (n == 0) { // Caso Base Fib 0
		res.fm1 = 0;
		res.f_n = 0;
		res.fp1 = 1;
	}
	else if (n == 1) { // Caso Base Fib 1
		res.fm1 = 0;
		res.f_n = 1;
		res.fp1 = 1;
	}
	else {// Caso Recursivo. Aplicamos Divide y Vencerás.

		if ((n & 1) == 0) { //Con n par
			r1 = fibmatrix(n >> 1);
			r2 = r1;
		}
		else {// Con n Impar, solo hay que multiplicar por la matriz fib básica (1) en r2.
			r1 = fibmatrix(n >> 1);
			r2.fm1 = r1.f_n;
			r2.f_n = r1.fp1;
			r2.fp1 = r1.f_n + r1.fp1;
		}
		// Multiplicación matricial resumida.
		res.fm1 = ((r1.fm1 * r2.fm1) + (r1.f_n * r2.f_n)) % MAX;
		res.f_n = ((r1.fm1 * r2.f_n) + (r1.f_n * r2.fp1)) % MAX;
		res.fp1 = ((r1.f_n * r2.f_n) + (r1.fp1 * r2.fp1)) % MAX;
	}

	return res;
}

bool resuleveCaso() {

	long long int n;

	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		cout << fibmatrix(n).f_n << "\n";
	}
	return true;
}
int main() {

	while (resuleveCaso()) {

	}

	return 0;
}
/*
	ACEPTA EL RETO. 306 Dos Igualdades Sorprendentes.

	El problema es muy similar a ACR295 Elévame. La diferencia es que ahora la potencia entera está aplicada
	sobre una matriz 2x2.
	Con un número elevado a una potencia entera siempre podemos hacer:

	x^n = (x^n/2)*(x^n/2)     Si n par
	x^n = (x^n/2)*(x^n/2)*x   Si n impar

	Como ahora X es una matriz 2x2 (que además es simétrica, y por lo tanto sólo tiene 3 números efectivos) lo 
	único que hay que implementar es la multiplicación matricial. Como las dos ramas del D&V son iguales, sólo
	lanzamos una recursión haciendo el algoritmo más rápido ( y si es impar añadimos al r2 un *X).
	
	El resultado se tiene que expresar en "Módulo MAX".
*/