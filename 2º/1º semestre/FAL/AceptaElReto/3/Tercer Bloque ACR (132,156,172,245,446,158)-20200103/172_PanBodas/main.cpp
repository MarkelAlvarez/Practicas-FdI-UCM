/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 172 El pan en las bodas.

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
	int sillas;
	char c;
	bool todos_comen = true, der=false, izq=false;
	int i;
	cin >> sillas;
	if (sillas == 0)
		return false;
	else if (sillas == 1 || sillas == 2) {
		cout << "TODOS COMEN" << endl;
		cin.ignore(10, '\n');
	}
	else {

		i = 0;
		while (todos_comen && i < sillas) {
			cin >> c;
			if (c == 'D') {
				der = true;
			}
			else if (c == 'I') {
				izq = true;
			}
			if (izq && der) {
				todos_comen = false;
				cin.ignore(65536, '\n');
			}
			++i;
		}
		if (todos_comen) {
			cout << "TODOS COMEN" << endl;
		}
		else {
			cout << "ALGUNO NO COME" << endl;
		}
		return true;
	}
}
int main() {
	while (casoDePrueba()) {
	}
	return 0;
}
/*
   ACEPTA EL RETO. 172 El pan en las bodas.

   Es f�cil darse cuenta de que si alg�n comensal ha comenzado a comer
   en una direcci�n y otro en la otra, es imposible que coman todos.
   Por lo tanto consiste en encontrar alguna D y alguna I. Si solo
   se encuentra de un tipo (o de ninguno), todos comen.

   Si los casos de prueba fuesen muy largos quiz� no se podr�a usar
   While->IF-ELSE y habr�a que buscar otra manera, pero no es el caso.
*/