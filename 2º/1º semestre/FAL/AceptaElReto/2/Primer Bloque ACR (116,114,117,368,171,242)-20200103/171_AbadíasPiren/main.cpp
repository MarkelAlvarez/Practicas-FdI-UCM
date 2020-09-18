/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 171 Abad�as pirenaicas.

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
	int nummont;
	int ab = 0, max = 0, i, aux;
	vector <int> v;

	cin >> nummont;
	for (i = 0; i < nummont; ++i) {
		cin >> aux;
		v.push_back(aux);
	}

	if (nummont == 0){
		return false;
	}
	else {
		for (i = nummont - 1; i >= 0; --i) {
			if (max < v[i]) {
				max = v[i];
				++ab;
			}
		}
		cout << ab << endl;
		return true;
	}
} 
int main() {

	while (casoDePrueba()) {
	}
	return 0;
}

/*
   ACEPTA EL RETO. 171 Abad�as pirenaicas.

   Cuando se quiere realizar un ejercicio con un array de valores
   a veces es posible trabajar sin vectores, sin embargo en este caso
   lo necesario es ir evaluando la pared del pico m�s alto de derecha
   a izquierda y as� obtener un algoritmo de coste lineal.
   Para poder examinar una cadena de derecha a izquierda necesitamos
   almacenar previamente todos los valores en un vector.

   La clase especial "vector" es una buena opci�n ya que puede
   cambiar de tama�o din�micamente con "push.back()" y no necesitamos
   saber de antemano la cantidad de memoria necesaria a reservar.

*/