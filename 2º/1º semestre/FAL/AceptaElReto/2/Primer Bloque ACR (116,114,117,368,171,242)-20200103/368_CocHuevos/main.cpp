/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 368 Cociendo Huevos.

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

   Es intuitivo aplicar la operaci�n de divisi�n h/c para atajar este problema
   y despu�s multiplicar por 10 en vez de utilizar un bucle de sumas. 
   Sin embargo hay que distinguir el caso en que ambas cantidades sean 
   iguales � h ligeramente mayor. Eso exigir�a usar una comparaci�n siempre
   con (h%c != 0) lo que lo har�a m�s lento que el bucle, aunque no demasiado.

   else {
	   t=(h/c)*10;
	   if(h%c!=0){
		 t=t+10;
	   }
		cout << t << endl;
		return true;
	}
*/