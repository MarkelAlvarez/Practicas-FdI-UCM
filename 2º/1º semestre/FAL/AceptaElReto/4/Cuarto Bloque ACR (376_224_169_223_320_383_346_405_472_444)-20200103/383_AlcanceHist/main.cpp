/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 383 El alcance de las historias.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/

#include <iostream>
#include <vector>
using namespace std;

void casoDePrueba() {
	long int pags, alcance, aux, max_alc, pico;
	max_alc = 1;
	max_alc = max_alc << 31;

	cin >> pags;
	--pags;
	cin >> pico;
	for (int i = 0; i < pags; ++i) {	
		cin >> aux;
		alcance = pico - aux;
		if (aux > pico) {
			pico = aux;
		}
		if ( alcance > max_alc) {
			max_alc = alcance;
		}
	}
	cout << max_alc << endl;
}

int main() {
	int numcasos;

	cin >> numcasos;
	for (int i = 0; i < numcasos; ++i) {
		casoDePrueba();
	}

	return 0;
}
/*
   ACEPTA EL RETO. 383 El alcance de las historias.

   El alcance se contabiliza como positivo si hay un retroceso y como negativo
   si simplemente el libro avanza (aunque sea a saltos).

   Como se debe devolver el número mayor, los saltos grandes hacia delante no son
   relevantes (número negativos de valor absoluto grande) por lo que habría que contar
   el salto más pequeño hacia delante o el más grande hacia atrás (que es positivo).

   Para resolverlo no hace falta un array, es suficiente con tomar cada página y ver
   la dirección con una resta del anterior máximo (el pico).
   Es importante tener en cuenta que no es solo cuestión de evaluar un número y su anterior
   sino que se cuenta todo el retroceso incluso a varias lecturas de distancia.
*/