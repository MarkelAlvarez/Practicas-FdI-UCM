/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 167 Pintando Fractales

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


int pint_fract(int n) {
	int r;
	
	if (n == 1) { // Caso Base. Llegamos a longitud de lado del cuadrado 1.
		return 4;
	}
	else { // Caso Recursivo. Longitud > 1
 
		r = 4*n + 4*pint_fract(n >> 1); //División entera entre 2, haciendo un shift right de 1.
		return r;
	}
}


bool resuelveCaso() {

	int suma, num;
	cin >> num;

	if (cin) {
		suma = pint_fract(num);
		cout << suma << "\n";

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
   ACEPTA EL RETO. 167 Pintando Fractales

   Aprovechamos la recursividad del concepto de fractal. Cada vez que bajamos un nivel
   el tamaño del lado del cuadrado multiplicamos por 4 lo que nos devuelve la llamada,
   puesto que tenemos que repetirlo por cada esquina. No solo un cuadrado sino todo el 
   fractal que venía dibujado desde antes.

*/
