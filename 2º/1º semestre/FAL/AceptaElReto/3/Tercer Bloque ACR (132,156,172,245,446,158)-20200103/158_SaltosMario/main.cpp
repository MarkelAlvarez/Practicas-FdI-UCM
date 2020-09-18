/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 158 Los Saltos de Mario.

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

   La idea aquí es hacer las comparativas con operaciones poco conocidas
   como son "operaciones a nivel de BIT". Éstas son bastante rápidas y si 
   sabemos que los enteros se almacenan en Complemento a 2 lo tenemos hecho
   (aunque sean long ó long long).

   Un "long long int" es un entero de 64 bits en Complemento a 2. Por ello
   con quedarme solo con el signo de la operación del escalón y sumárselo
   al conteo de los saltos obtengo el número de saltos de cada tipo.

   A & B es la AND lógica bit a bit de A y B.
   A = A << 63; Hace Shift left de 63 ceros.
   A = A >> 63; Hace Shif right de 63 ceros. Sin embargo al hacer esto sobre negativos desplaza con '1'.

   El resultado de (((primero - sig) & signo) >> 63) es siempre (-1) ó (0).
   El resultado de (((sig - primero) & signo) >> 63) es siempre (-1) ó (0).

*/