/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 376 Site picos.

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

bool casoDePrueba() {
	unsigned int numalturas, aux, picos = 0;
	vector <unsigned int> alturas;

	cin >> numalturas;

	if ( numalturas == 0) {
		return false;
	}
	else {

		for (int i = 0; i < numalturas; ++i) {
			cin >> aux;
			alturas.push_back(aux);
		}

		if (numalturas > 2) {
			for (int i = 1; i < numalturas - 1; ++i) {
				if ((alturas[i - 1] < alturas[i]) && (alturas[i] > alturas[i + 1])) {
					++picos;
					++i;
				}

			}
		
			if ( (alturas[0] > alturas[numalturas - 1]) && (alturas[0] > alturas[1])) {
				++picos;
			}
			else if ((alturas[0] < alturas[numalturas - 1]) && (alturas[numalturas - 1] > alturas[numalturas - 2])) {
				++picos;
			}
		}
		else {
			if (alturas[0] != alturas[1]) {
				++picos;
			}
		}
		cout << picos << endl;
		return true;
	}

}

int main() {

	while (casoDePrueba()) {
	}
	return 0;
}
/*
	ACEPTA EL RETO. 376 Site picos.

	Ejercicio sencillito, no hay unos l�mites exigentes respecto a la memoria o a los tiempos.
	Simplemente tener en cuenta que si solo hay dos alturas y son diferentes lo toma como pico.

	Adem�s he a�adido un ++i al for en caso de encontrar pico puesto que dos posiciones consecutivas
	no pueden ser pico. Nos ahorramos una iteraci�n.

*/
