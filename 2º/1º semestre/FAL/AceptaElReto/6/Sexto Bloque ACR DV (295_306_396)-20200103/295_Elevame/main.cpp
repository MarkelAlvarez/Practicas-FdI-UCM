/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 295 Elévame

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

const long long int MAX = 31543;

long long int eleva(long long int x, long long int n) {
	long long int res, r1, r2;

	if (n == 0) { // Caso Base potencia 0.
		res = 1;
	}
	else if (n == 1) { // Caso Base potencia 1.
		res = x % MAX;
	}
	else {// Caso Recursivo. Aplicamos Divide y Vencerás.

		if ((n & 1) == 0) { //Con n par
			r1 = eleva(x, n >> 1) % MAX;
			r2 = r1;
		}
		else {// Con n Impar
			r1 = eleva(x, (n >> 1)) % MAX;
			r2 = (x * r1) % MAX;
		}

		res = (r1 * r2) % MAX;
	}

	return res;
}


bool resuelveCaso() {

	long long int x, n;

	cin >> x >> n;
	if ((x+n)==0) {
		return false;
	}
	else {
		x = eleva(x, n);
		cout << x << "\n";
	}
	return true;
}
int main() {

	while (resuelveCaso()) {

	}

	return 0;
}

/*
	ACEPTA EL RETO. 295 Elévame.

	Lo resolvemos mediante la técnica Divide y Vencerás. Una potencia entera siempre puede descomponerse
	en dos subpotencias.

	x^n = (x^n/2)*(x^n/2)     Si n par
	x^n = (x^n/2)*(x^n/2)*x   Si n impar

	En este ejercicio tenemos la ventaja de que las dos ramas creadas por el D&V son idénticas, por lo tanto
	el coste del algoritmo será mucho menor si en vez de generar dos porciones con x^n/2 usamos una recursión simple
	con una sola llamada a x^n/2. 
	Al retornar multiplicamos a la "segunda" rama por X si era impar.
	El resultado se debe expresar en "Módulo MAX".
*/