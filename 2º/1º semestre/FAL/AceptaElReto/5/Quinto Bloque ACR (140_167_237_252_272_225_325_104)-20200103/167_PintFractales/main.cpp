/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 167 Pintando Fractales

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


int pint_fract(int n) {
	int r;
	
	if (n == 1) { // Caso Base. Llegamos a longitud de lado del cuadrado 1.
		return 4;
	}
	else { // Caso Recursivo. Longitud > 1
 
		r = 4*n + 4*pint_fract(n >> 1); //Divisi�n entera entre 2, haciendo un shift right de 1.
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
   el tama�o del lado del cuadrado multiplicamos por 4 lo que nos devuelve la llamada,
   puesto que tenemos que repetirlo por cada esquina. No solo un cuadrado sino todo el 
   fractal que ven�a dibujado desde antes.

*/
