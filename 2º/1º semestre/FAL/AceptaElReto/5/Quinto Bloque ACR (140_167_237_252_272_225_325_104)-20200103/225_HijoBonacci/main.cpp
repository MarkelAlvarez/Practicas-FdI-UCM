/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 225 El otro hijo de Bonacci

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

struct pack {
	long long int r;
	long long int ant;
};
const long long int TOP = 1000000007;

pack fibob(int n, long long int x, long long int y) {
	pack mi_p;
	long long int aux;

	if (n == 0) {  // Caso base CERO. 
		mi_p.r = x%TOP;
		mi_p.ant = 0;
	}
	else if (n == 1) { // Caso base UNO.
		mi_p.r = y % TOP;
		mi_p.ant = x % TOP;
	}
	else { //Caso recursivo donde tenemos que sumar los dos anteriores.
		mi_p= fibob(n - 1, x, y);
		aux = mi_p.r;
		mi_p.r= (mi_p.r + mi_p.ant)%TOP; //Suma de r y ant.
		mi_p.ant = aux%TOP;
	}

	return mi_p;
}

bool resuelveCaso() {

	int n;
	long long int x, y;
	cin >> n;
	if (cin) {
		cin >> x;
		cin >> y;
		cout << fibob(n, x, y).r <<"\n";

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
   ACEPTA EL RETO. 225 El otro hijo de Bonacci

   Este ejercicio tiene la complicaci�n de que no podemos usar la recursi�n doble.
   Una sucesi�n de Fibonacci se puede hacer con f(n)=f(n-1)+f(n-2), pero esto supone un coste
   exponencial.

   Para solventar esto usamos un valor de devuelta "m�s complejo" donde devolvemos mi resultado
   de la sucesi�n y adem�s del t�rmino anterior. Todo ello en un peque�o struct. Con esto podemos
   realizar el c�lculo recursivo en tiempo O(n). Tambi�n se pueden usar par�metros por referencia
   o variables globales, pero se debe tener cuidado con ello.

*/