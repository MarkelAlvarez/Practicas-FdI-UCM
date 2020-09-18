/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 383 El alcance de las historias.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
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

   Como se debe devolver el n�mero mayor, los saltos grandes hacia delante no son
   relevantes (n�mero negativos de valor absoluto grande) por lo que habr�a que contar
   el salto m�s peque�o hacia delante o el m�s grande hacia atr�s (que es positivo).

   Para resolverlo no hace falta un array, es suficiente con tomar cada p�gina y ver
   la direcci�n con una resta del anterior m�ximo (el pico).
   Es importante tener en cuenta que no es solo cuesti�n de evaluar un n�mero y su anterior
   sino que se cuenta todo el retroceso incluso a varias lecturas de distancia.
*/