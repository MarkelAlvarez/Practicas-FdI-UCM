/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 446 Abuelas falsas.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
#include <string>
using namespace std;

void casoDePrueba() {
	string nieto, cadena;
	int numnom;
	bool verd = true;
	cin >> nieto;
	cin >> numnom;
	if (numnom == 1) {
		cout << "FALSA" << endl;
		cin.ignore(65536, '\n');
	}
	else {
		cin.ignore(1);
		for (int i = 1; i < numnom; ++i) {
			cin >> cadena;
			verd = verd && (cadena != nieto);
		}
		cin >> cadena; // Último nombre
		verd = verd && (cadena == nieto);

		if (verd){
			cout << "VERDADERA" << endl;
		}
		else {
			cout << "FALSA" << endl;
		}
	}

} 
int main() {
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}
	return 0;
}
/*
   ACEPTA EL RETO. 446 Abuelas falsas.

   La estructura del problema es similar a "245 Los Dalton", pero más sencillo.
   Necesitamos hacer comparativas sin tomar todos los elementos y evitando 
   realizar demasiados IF.

   Con una variable bool vamos comprobando que todos los nombres son diferentes
   menos el último, y con éste que sea igual. Si se ha encontrado antes de tiempo
   (incluso aunque el último sea correcto) la abuela es falsa.
*/