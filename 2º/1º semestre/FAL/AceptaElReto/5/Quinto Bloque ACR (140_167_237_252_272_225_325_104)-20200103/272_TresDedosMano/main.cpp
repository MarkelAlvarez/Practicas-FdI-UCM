/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 272 Tres dedos en cada mano

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
#include <string>
using namespace std;

string convierte(long int n) {
	string num_cad = "";

	if (n < 6) { // Caso base, el n�mero es menor que 6.
		num_cad = to_string(n);
	}
	else { //Caso recursivo, todav�a es mayor que 6.
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

   Es muy �til usar string para este ejercicio ya que el operador suma
   est� sobrecargado de forma que podemos concatenar los d�gitos del 
   n�mero en base 6 simplemente haciendo una suma. Como se hace la recursi�n
   y despu�s la suma, los n�meros se van a�adiendo por detr�s. El �ltimo
   d�gito es el coeficiente para 6^(k-1) con k recursiones, que se imprime primero.

   Para poder continuar la recursi�n mantenemos la variable como entera
   y podemos ir haciendo n/6 para despu�s convertirlo a string antes de 
   procesar la salida.

*/