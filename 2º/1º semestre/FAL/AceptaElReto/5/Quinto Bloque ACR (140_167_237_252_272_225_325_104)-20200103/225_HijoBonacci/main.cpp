/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 225 El otro hijo de Bonacci

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

struct pack {
	long long int r;
	long long int ant;
};
const long long int TOP = 1000000007;

pack fibob(int n, long long int x, long long int y) {
	pack mi_p;
	long long int aux;

	if (n == 0) {  // Caso base CERO. 
		mi_p.r = x%TOP;
		mi_p.ant = 0;
	}
	else if (n == 1) { // Caso base UNO.
		mi_p.r = y % TOP;
		mi_p.ant = x % TOP;
	}
	else { //Caso recursivo donde tenemos que sumar los dos anteriores.
		mi_p= fibob(n - 1, x, y);
		aux = mi_p.r;
		mi_p.r= (mi_p.r + mi_p.ant)%TOP; //Suma de r y ant.
		mi_p.ant = aux%TOP;
	}

	return mi_p;
}

bool resuelveCaso() {

	int n;
	long long int x, y;
	cin >> n;
	if (cin) {
		cin >> x;
		cin >> y;
		cout << fibob(n, x, y).r <<"\n";

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
   ACEPTA EL RETO. 225 El otro hijo de Bonacci

   Este ejercicio tiene la complicación de que no podemos usar la recursión doble.
   Una sucesión de Fibonacci se puede hacer con f(n)=f(n-1)+f(n-2), pero esto supone un coste
   exponencial.

   Para solventar esto usamos un valor de devuelta "más complejo" donde devolvemos mi resultado
   de la sucesión y además del término anterior. Todo ello en un pequeño struct. Con esto podemos
   realizar el cálculo recursivo en tiempo O(n). También se pueden usar parámetros por referencia
   o variables globales, pero se debe tener cuidado con ello.

*/