/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 158 Los Saltos de Mario.

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

void casoDePrueba() {
	long long int nmuros, u = 0, d = 0, sig, primero, i;
	long long int signo = 1;
	signo=signo << 63;
	cin >> nmuros;
	cin >> primero;
	i = 1;
	while (i < nmuros) {
		cin >> sig;
		u = u - (((primero - sig) & signo) >> 63);
		d = d - (((sig - primero) & signo) >> 63);
		++i;
		primero = sig;
	}

	cout << u << " " << d << endl;

} 
int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}
	return 0;
}
/*
   ACEPTA EL RETO. 158 Los Saltos de Mario.
   
   Ya hemos comentado en ocasiones que While->IF-ELSE en secuencias
   muy largas nos puede echar por exceso de tiempo.

   La idea aqu� es hacer las comparativas con operaciones poco conocidas
   como son "operaciones a nivel de BIT". �stas son bastante r�pidas y si 
   sabemos que los enteros se almacenan en Complemento a 2 lo tenemos hecho
   (aunque sean long � long long).

   Un "long long int" es un entero de 64 bits en Complemento a 2. Por ello
   con quedarme solo con el signo de la operaci�n del escal�n y sum�rselo
   al conteo de los saltos obtengo el n�mero de saltos de cada tipo.

   A & B es la AND l�gica bit a bit de A y B.
   A = A << 63; Hace Shift left de 63 ceros.
   A = A >> 63; Hace Shif right de 63 ceros. Sin embargo al hacer esto sobre negativos desplaza con '1'.

   El resultado de (((primero - sig) & signo) >> 63) es siempre (-1) � (0).
   El resultado de (((sig - primero) & signo) >> 63) es siempre (-1) � (0).

*/