
/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 224 Los Bocadillos de la Hormiga Reina

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

bool casoDePrueba() {
	vector <long long int> cortezas;
	long long int numcort, pos, i, aux, sum;
	bool bocata = false;


	cin >> numcort;

	if (numcort == 0) {
		return false;
	}
	else if (numcort == 1) {
		cin >> aux; //Eliminamos la corteza del buffer de CIN
		cout << "NO" << endl;
		
		return true;
	}
	else {
		for (i = 0; i < numcort; ++i) {
			cin >> aux;
			cortezas.push_back(aux);
		}

		sum = cortezas[numcort - 1];
		i = numcort - 2;

		while (i >= 0) {
			if (cortezas[i] == sum) {
				bocata = true;
				pos = i + 1;
			}
			sum += cortezas[i];
			--i;
		}

	}
	if (bocata) {
		cout << "SI " << pos << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return true;

}



int main() {

	while (casoDePrueba()) {
	}
	return 0;
}

/*
   ACEPTA EL RETO. 224 Los Bocadillos de la Hormiga Reina

   Es un problema iterativo donde es necesario procesar los datos
   desde el final, por lo tanto estamos obligados a tomar la información
   completa en un vector.
   Comenzando por el final vamos sumando el tamaño de cada corteza hasta
   que coincide con algún elemento y ponemos bocata=TRUE. Sin embargo puede
   darse el caso de que avanzando hacia el inicio aparezca una suma mayor
   de trocitos que nos aporte un bocata más grande. Por lo tanto hay que
   seguir evaluando todas las componentes hasta llegar a la [0].

*/
