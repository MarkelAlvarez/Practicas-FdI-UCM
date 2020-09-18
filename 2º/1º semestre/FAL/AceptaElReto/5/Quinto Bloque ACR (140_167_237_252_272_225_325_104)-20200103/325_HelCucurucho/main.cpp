/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 325 Helados de cucurucho

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
#include <vector>
using namespace std;


void cucurucho( int& vaini, int mi_choc ,int mi_vaini, string v ) {
	string print;

	if ((mi_choc + mi_vaini) == 1) { // Caso Base. Solo hay una bola.
		if (mi_choc == 1) {
			print = v + "C";
		}
		else {
			print = v + "V";
		}
		cout << print; // Impresi�n solamente en los casos Base.
		if (!(print.find_last_of("V") == (vaini - 1))) { // Imprimo espacio en todos los casos salvo el �ltimo
			cout << " ";
		}
	}
	else { // Caso Recursivo. Tenemos m�s de una bola.
		if (mi_vaini==0) {
			cucurucho(vaini, mi_choc - 1, 0, v + "C");
			
		}
		else if (mi_choc == 0) {
			cucurucho(vaini, 0, mi_vaini - 1, v + "V");

		}
		else {
			cucurucho(vaini, mi_choc - 1, mi_vaini, v + "C");
			cucurucho(vaini, mi_choc, mi_vaini - 1, v + "V");
		}
	
	}   

}

void resuelveCaso() {

	int choco, vaini;
	vector <char> helado;

	cin >> choco;
	cin >> vaini;
	cucurucho(vaini, choco, vaini, "");
	cout << "\n";

}
int main() {

	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	return 0;
}
/*

   ACEPTA EL RETO. 325 Helados de cucurucho

   Este problema tiene bastante chicha. En un principio parece sencillo. Si por ejemplo tenemos
   Choco=2 y Vaini=2 tenemos que sacar

   CCVV CVCV CVVC VCCV VCVC VVCC

   Al hacer una primera mirada nos damos cuenta de que se puede intentar resolver el problema
   mediente intercambios de componentes como si las "C" fuesen avanzando y las "V" retrocediendo.
   Sin duda esto es posible, pero cuando la cantidad de bolas aumenta necesitamos hacer un enorme
   n�mero de comparaciones y recolocaciones. Ejemplo Choco=8 Vaini=7 en un momento intermedio

   CCCVCCVVCVVVVCC -> CCCVCCVVVCCCVVV   Se tiene que recolocar medio vector.

   Por otro lado nos podemos percatar de que es un juego de permutaciones y hacer una pir�mide de 
   llamadas de la siguiente manera. (Como ejemplo Choco=2 Vaini=2)     PAREJA(C,V)

								(2,2)
				(1,2)							(2,1)
		(0,2)			(1,1)			(1,1)			(2,0)
	(0,1)			(0,1)	(1,0)	(0,1)	(1,0)			(1,0)

   Si nos fijamos en las ramas finales, tenemos 6 (igual que el n�mero de permutaciones que debemos realizar).
   Cada vez que bajo a la izquierda quito una "C" de la pareja, pero la a�ado al STRING. Si lo hago por la 
   derecha quito una "V", pero la a�ado al STRING.
   El camino de la izquierda del todo es entonces CCVV y el de la derecha VVCC justamente como me interesa.
   Dado que damos prioridad a las recursiones de la rama izquierda poniendo delante los casos con "C" se imprimen
   en orden alfab�tico llegando al caso base.

   La funci�n recursiva es VOID y por tanto al retornar no hace absolutamente nada.

*/
