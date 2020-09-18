/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 405 Imprimiendo p�ginas sueltas.

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
	long long int pag, pag_ant, cont;
	bool consec;

	cin >> pag_ant;
	if (pag_ant == 0) {
		return false;
	}
	else {
		cont = 0;
		do {
			cin >> pag;
			consec = (pag == (pag_ant + 1 + cont));
			if (consec) {
				++cont;
			}
			else if (pag!=0) {
				if (cont == 0) {
					cout << pag_ant << ",";
				}
				else {
					cout << pag_ant << "-" << pag_ant + cont << ",";
				}
				cont = 0;
				pag_ant = pag;
			}else{
				if (cont == 0) {
					cout << pag_ant;
				}
				else {
					cout << pag_ant << "-" << pag_ant + cont;
				}
			}
			
		} while (pag != 0);

		cout << endl;
		return true;
	}
}

int main() {

	while(casoDePrueba()) {
	}

	return 0;
}
/*
   ACEPTA EL RETO. 405 Imprimiendo p�ginas sueltas.

   Es un problema con poca chica, apenas hay que comprobar si existen tramos
   consecutivos para escribir guiones o comas y poco m�s.

*/