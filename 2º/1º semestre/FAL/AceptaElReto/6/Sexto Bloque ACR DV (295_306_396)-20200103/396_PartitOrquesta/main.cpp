/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 396 Las Partituras de la Orquesta

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int orquesta(const vector <int>& v, int partituras, int instrumentos, int ini, int fin, int& res) {
	int mitad, i, max_atril, necesarias, minus;
	int top1, top2;

	if (fin == ini) { // Caso base, tamaño 1 de vector.
		top1 = v[ini];
	}
	else { // Caso Recursivo. DIvide y Vencerás.
		mitad = (ini + fin) >> 1;
		top1 = orquesta(v, partituras, instrumentos, ini, mitad, res);
		top2 = orquesta(v, partituras, instrumentos, mitad + 1, fin, res);

		if (top1 < top2) { top1 = top2; }

		if ((fin - ini) == (instrumentos - 1)) { // Algoritmo iterativo aplicado sólo en el retorno total del D&V.
			res = top1;
			minus = 1;
			while (minus <= top1) {
				max_atril = (top1 + minus) >> 1;
				necesarias = 0;
				for (i = 0; i < instrumentos; ++i) {
					necesarias += (v[i] + max_atril - 1) / max_atril;
				}
				if (necesarias <= partituras) {
					top1 = max_atril - 1;
					res = max_atril;
				}
				else {
					minus = max_atril + 1;
				}

			}
		}

	}

	return top1;
}

bool resuelveCaso() {
	int instrumentos, partituras, i;
	vector <int> v;
	int res = 1;

	cin >> partituras;

	if (cin) {
		cin >> instrumentos;
		v.resize(instrumentos);
		if (instrumentos == partituras) {
			for (i = 0; i < instrumentos; ++i) {
				cin >> v[i];
				res = max(res, v[i]);
			}
		}
		else {
			for (i = 0; i < instrumentos; ++i) {
				cin >> v[i];
			}
			if (instrumentos == 1) {
				res = (v[0] + partituras - 1) / partituras;
			}
			else {
				orquesta(v, partituras, instrumentos, 0, v.size() - 1, res);
			}
			
		}

		cout << res << "\n";

		return true;
	}
	else {
		return false;
	}
}

int main() {

	while (resuelveCaso()) {

	}
	return 0;
}


/*   
	ACEPTA EL RETO. 396 Las Partituras de la Orquesta

	Este ejercicio nos lo piden con Divide y Vencerás. Se puede ver que en este caso, aplicar D&V no es
	nada intuitivo y no ayuda prácticamente nada a alcanzar más rápidamente la solución. El ejercicio
	se puede resolver con bastante solvencia haciendo un algoritmo iterativo (que explico a continuación)
	y en todo caso podemos aprovechar las llamadas de D&V para obtener el atril que tiene el mayor número 
	de músicos. Este número lo usaremos para el iterativo que aplicamos en la última instancia del D&V, 
	cuando el vector ya está reconstruido.

	Además de la complicación que ya hemos comentado, el algoritmo que tenemos que usar para hacer una 
	evaluación eficiente de las partituras que hay que entregar a cada atril de músicos no es nada evidente.


	EXPLICACIÓN DEL ITERATIVO interno.

	Es una búsqueda "binaria" sobre la cantidad de partituras necesarias para obtener el
	valor de un atril máximo en concreto. En vez de ir asignando partituras que sería muy lento.
	El bucle "for" calcula si se puede conseguir ese objetivo obteniendo "need". Si se pasa
	de partituras es que no podemos conseguir ese "atril máximo" y probamos con otro mayor
	aumentando el minus (como en una búsqueda binaria). Si se puede obtener, disminuimos
	el valor de top.

	Aunque tenemos un cálculo de coste O(n) con el bucle for, el número de veces que se realiza
	va con el valor (máximo del vector)/2, de manera que se obtiene un coste total del algoritmo
	similar a O(nlogK).
*/

