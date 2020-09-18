/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 272 Tres dedos en cada mano

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
#include <string>
using namespace std;

string convierte(long int n) {
	string num_cad = "";

	if (n < 6) { // Caso base, el número es menor que 6.
		num_cad = to_string(n);
	}
	else { //Caso recursivo, todavía es mayor que 6.
		num_cad = convierte(n / 6) + to_string(n % 6);
	}
	return num_cad;
}

void resuelveCaso() {
	long int n;

	cin >> n;
	cout << convierte(n) + "\n";
}

int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	return 0;
}
/*
   ACEPTA EL RETO. 272 Tres dedos en cada mano

   Es muy útil usar string para este ejercicio ya que el operador suma
   está sobrecargado de forma que podemos concatenar los dígitos del 
   número en base 6 simplemente haciendo una suma. Como se hace la recursión
   y después la suma, los números se van añadiendo por detrás. El último
   dígito es el coeficiente para 6^(k-1) con k recursiones, que se imprime primero.

   Para poder continuar la recursión mantenemos la variable como entera
   y podemos ir haciendo n/6 para después convertirlo a string antes de 
   procesar la salida.

*/