/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 472 Caminando Voy

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
	long int desnivel, cotas, i, aux, sub_parc, desn_parc = 0;
	vector <long int> v;
	bool apto = true;

	cin >> desnivel;
	if (!cin)
		return false;
	else {
		cin >> cotas;
		for (i = 0; i < cotas; ++i) {
			cin >> aux;
			v.push_back(aux);
		}
		i = 1;

		while (apto && (i < cotas)) {
			sub_parc = v[i] - v[i - 1];
			if (sub_parc > 0) {
				desn_parc = desn_parc + sub_parc;
				if (desn_parc > desnivel) {
					apto = false;
				}
			}
			else {
				desn_parc = 0;
			}
			++i;
		}

		if (apto) {
			cout << "APTA" << endl;
		}
		else {
			cout << "NO APTA" << endl;
		}

		return true;
	}
} 

int main() {

	while (casoDePrueba()) {
	}

	return 0;
}
/*
   ACEPTA EL RETO. 472 Caminando Voy.

   A falta de un algoritmo m�s eficiente, simplemente evaluamos las subidas
   consecutivas para comprobar si exceden los requisitos del paseo.

   Coste lineal, no se pasa de memoria, entra en tiempo... suficiente.

*/