/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 295 El�vame

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

const long long int MAX = 31543;

long long int eleva(long long int x, long long int n) {
	long long int res, r1, r2;

	if (n == 0) { // Caso Base potencia 0.
		res = 1;
	}
	else if (n == 1) { // Caso Base potencia 1.
		res = x % MAX;
	}
	else {// Caso Recursivo. Aplicamos Divide y Vencer�s.

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
	ACEPTA EL RETO. 295 El�vame.

	Lo resolvemos mediante la t�cnica Divide y Vencer�s. Una potencia entera siempre puede descomponerse
	en dos subpotencias.

	x^n = (x^n/2)*(x^n/2)     Si n par
	x^n = (x^n/2)*(x^n/2)*x   Si n impar

	En este ejercicio tenemos la ventaja de que las dos ramas creadas por el D&V son id�nticas, por lo tanto
	el coste del algoritmo ser� mucho menor si en vez de generar dos porciones con x^n/2 usamos una recursi�n simple
	con una sola llamada a x^n/2. 
	Al retornar multiplicamos a la "segunda" rama por X si era impar.
	El resultado se debe expresar en "M�dulo MAX".
*/