/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 368 Cociendo Huevos.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
using namespace std;

bool casoDePrueba() {
	unsigned int t = 0;
	int h, c;
	cin >> h;
	cin >> c;

	if (h==0&&c==0)
		return false;
	else {
		while (h > 0) {
			t += 10;
			h = h - c;
		}
		cout << t << endl;
		return true;
	}
} 
int main() {

	while (casoDePrueba()) {
	}
	return 0;
}

/*
   ACEPTA EL RETO. 368 Cociendo Huevos.

   Es intuitivo aplicar la operación de división h/c para atajar este problema
   y después multiplicar por 10 en vez de utilizar un bucle de sumas. 
   Sin embargo hay que distinguir el caso en que ambas cantidades sean 
   iguales ó h ligeramente mayor. Eso exigiría usar una comparación siempre
   con (h%c != 0) lo que lo haría más lento que el bucle, aunque no demasiado.

   else {
	   t=(h/c)*10;
	   if(h%c!=0){
		 t=t+10;
	   }
		cout << t << endl;
		return true;
	}
*/