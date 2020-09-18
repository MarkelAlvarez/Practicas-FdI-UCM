/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 396 Las Partituras de la Orquesta

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int orquesta(const vector <int>& v, int partituras, int instrumentos, int ini, int fin, int& res) {
	int mitad, i, max_atril, necesarias, minus;
	int top1, top2;

	if (fin == ini) { // Caso base, tama�o 1 de vector.
		top1 = v[ini];
	}
	else { // Caso Recursivo. DIvide y Vencer�s.
		mitad = (ini + fin) >> 1;
		top1 = orquesta(v, partituras, instrumentos, ini, mitad, res);
		top2 = orquesta(v, partituras, instrumentos, mitad + 1, fin, res);

		if (top1 < top2) { top1 = top2; }

		if ((fin - ini) == (instrumentos - 1)) { // Algoritmo iterativo aplicado s�lo en el retorno total del D&V.
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

	Este ejercicio nos lo piden con Divide y Vencer�s. Se puede ver que en este caso, aplicar D&V no es
	nada intuitivo y no ayuda pr�cticamente nada a alcanzar m�s r�pidamente la soluci�n. El ejercicio
	se puede resolver con bastante solvencia haciendo un algoritmo iterativo (que explico a continuaci�n)
	y en todo caso podemos aprovechar las llamadas de D&V para obtener el atril que tiene el mayor n�mero 
	de m�sicos. Este n�mero lo usaremos para el iterativo que aplicamos en la �ltima instancia del D&V, 
	cuando el vector ya est� reconstruido.

	Adem�s de la complicaci�n que ya hemos comentado, el algoritmo que tenemos que usar para hacer una 
	evaluaci�n eficiente de las partituras que hay que entregar a cada atril de m�sicos no es nada evidente.


	EXPLICACI�N DEL ITERATIVO interno.

	Es una b�squeda "binaria" sobre la cantidad de partituras necesarias para obtener el
	valor de un atril m�ximo en concreto. En vez de ir asignando partituras que ser�a muy lento.
	El bucle "for" calcula si se puede conseguir ese objetivo obteniendo "need". Si se pasa
	de partituras es que no podemos conseguir ese "atril m�ximo" y probamos con otro mayor
	aumentando el minus (como en una b�squeda binaria). Si se puede obtener, disminuimos
	el valor de top.

	Aunque tenemos un c�lculo de coste O(n) con el bucle for, el n�mero de veces que se realiza
	va con el valor (m�ximo del vector)/2, de manera que se obtiene un coste total del algoritmo
	similar a O(nlogK).
*/

