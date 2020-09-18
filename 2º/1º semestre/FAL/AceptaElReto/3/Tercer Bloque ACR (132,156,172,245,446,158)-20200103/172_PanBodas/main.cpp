/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 172 El pan en las bodas.

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

   Es fácil darse cuenta de que si algún comensal ha comenzado a comer
   en una dirección y otro en la otra, es imposible que coman todos.
   Por lo tanto consiste en encontrar alguna D y alguna I. Si solo
   se encuentra de un tipo (o de ninguno), todos comen.

   Si los casos de prueba fuesen muy largos quizá no se podría usar
   While->IF-ELSE y habría que buscar otra manera, pero no es el caso.
*/