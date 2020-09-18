/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 346 El hombre con seis dedos.

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
	long int births, periodA, mayor = 1, aux, i, parc_period;
	long int ultimo, rango, a, b, c, fin;
	vector <long int> vec_nac;

	cin >> births;
	if (births == 0) {
		return false;
	}
	else {
		cin >> periodA;
		for ( i = 0; i < births; ++i) {
			cin >> aux;
			vec_nac.push_back(aux);
		}

		rango = vec_nac[births - 1] - vec_nac[0] + 1;
		
		if (periodA >= rango) {
			mayor = births;
		}
		else {
			i = 0;
			fin = vec_nac[births - 1] - periodA + 1;

			while (i < births && (vec_nac[i] < fin)) {
				ultimo = vec_nac[i] + periodA - 1;
				a = i;
				b = births - 1;
				while (a < b) {
					c = (a+b)/2;
					if (vec_nac[c] > ultimo) {
						b = c;
					}
					else {
						a = c + 1;
					}
				}
				parc_period = a - i;
				if (parc_period > mayor) { mayor = parc_period; }
				++i;
			}
			parc_period = births - i;
			if (parc_period > mayor) { mayor = parc_period; }
		}

		cout << mayor << endl;
		return true;
	}
}
int main() {

	while (casoDePrueba()) {
	}

	return 0;
}
/*
   ACEPTA EL RETO. 346 El hombre con seis dedos.

   Este problema es similar al ejercicio ACR 320 "Palmeras en la Nieve", que no es sencillo, 
   pero le añade complicaciones nuevas.

   La complicación de este problema es que la "ventana" de evaluación para los nacimientos
   es de tamaño variable, además los años van dando saltos y también pueden estar repetidos.
   Por ello llevar una cuenta simple de los que entran y salen de la ventana es complicado.

   La cuestión es fijarse en que el vector de entrada es un array monótono creciente, por lo
   que es susceptible de recibir búsquedas binarias.
   Vamos a recorrer el array linealmente (coste O(n)) y en cada paso hacemos una búsqueda binaria
   para ver el final del tramo en función del ancho de años y el valor de la componente en la que estamos.

   El coste del algoritmo es O(nlogn), suficiente para entrar en tiempos y que no se vea influido
   por los anchos variables ni los elementos repetidos.

   ->Nota: la búsqueda binaria la usamos como algoritmo de inserción por lo que devuelve el valor de la
   primera posición que excede al valor buscado.

*/

