/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 444 La digestión de las serpientes

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
	long int medidas, i, aux, aguante, huecos, pos1;
	long int ancho = 0, ancho_max = 0, tam;
	vector <long int> v;
	bool es_tramo = false;

	cin >> medidas;

	if (medidas == 0) {
		return false;
	}
	else {
		cin >> aguante;

		for (i = 0; i < medidas; ++i) {
			cin >> aux;
			if (aux) {
				v.push_back(i);
			}
		}
		tam = v.size();
		if (tam > 0) {
			ancho_max = 1;
		}
		i = 0;
		++aguante;
		--tam;
		pos1 = 0;
		while(i<tam) {

			if ((v[i + 1] - v[i]) <= aguante) {
				es_tramo = true;
			}
			else {
				if (es_tramo) {
					ancho = v[i] - v[pos1] + 1;
					if (ancho > ancho_max) { ancho_max = ancho; }
				}
				pos1 = i + 1;
				es_tramo = false;
			}
			++i;
		}
		if (es_tramo) {
			ancho = v[i] - v[pos1] + 1;
			if (ancho > ancho_max) { ancho_max = ancho; }
		}

		cout << ancho_max << endl;
		return true;

	}
}



int main() {

	while (casoDePrueba()) {
	}

	return 0;
}

/*
   ACEPTA EL RETO. 444 La digestión de las serpientes.

   Es un problema de cuenta sobre una ventana. El ancho es variable dependiendo
   de las lecturas no válidas que pueda soportar la serpiente (aguante). 

   Para solucionar esto tomamos nota de las posiciones en las que las temperaturas
   son adecuadas en un vector de enteros en el momento del procesado inicial.
   Posteriormente solo hay que comprobar si las medidas tienen una separación apta o no
   recorriendo el vector de enteros (comparando con el aguante).

*/