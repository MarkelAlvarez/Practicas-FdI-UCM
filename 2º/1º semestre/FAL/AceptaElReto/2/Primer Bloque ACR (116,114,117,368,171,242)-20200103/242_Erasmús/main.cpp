/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 242 Erasm�s.

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

bool casoDePrueba() {
	long long int numpais, i, aux1, aux2;
	long long int parej = 0;

	cin >> numpais;
	if (numpais == 0) {
		return false;
	}
	else {
		cin >> aux1;
		for (i = 1; i < numpais; ++i) {
			cin >> aux2;
			parej = parej + aux2*aux1; // Nuevas parejas con el acumulado anterior aux1.
			aux1 = aux1 + aux2; // <- Nuevo acumulado de jugadores.
		}
		cout << parej << endl;
		return true;
	}
} 
int main() {

	while (casoDePrueba()) {
	}
	return 0;
}
/*
   ACEPTA EL RETO. 242 Erasm�s.

   Para resolver la cuenta se tiene que aplicar un poco de combinatoria.
   Como no hay una exigencia de conocer ni el tama�o ni los valores del 
   array completo se puede ir acumulando el resultado sin usar vectores.

   No hay que perder de vista que las cantidades pueden ser muy grandes
   y por tanto hay que declarar "long long int".

*/