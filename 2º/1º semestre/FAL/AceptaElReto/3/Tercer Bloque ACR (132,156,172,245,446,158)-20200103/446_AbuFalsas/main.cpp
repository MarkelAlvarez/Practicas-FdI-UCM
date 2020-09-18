/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 446 Abuelas falsas.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
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
		cin >> cadena; // �ltimo nombre
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

   La estructura del problema es similar a "245 Los Dalton", pero m�s sencillo.
   Necesitamos hacer comparativas sin tomar todos los elementos y evitando 
   realizar demasiados IF.

   Con una variable bool vamos comprobando que todos los nombres son diferentes
   menos el �ltimo, y con �ste que sea igual. Si se ha encontrado antes de tiempo
   (incluso aunque el �ltimo sea correcto) la abuela es falsa.
*/