/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 132 Las Cartas del Abuelo.

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
	vector <int> igus;

	char c, auxchar;
	int numinterv, a,b,d;
	int i, j, aux1, aux2, pos;
	bool continu = true;
	cin.get(c);
	aux1 = 0;
	i = 0;
	j = 1;
	  // Clasificaci�n de la cadena en frecuencias. Vector IGUS
	while (continu) {
		cin.get(auxchar);
		if (auxchar != '\n') {
			if (c == auxchar) {
				++j;
			}
			else {
				igus.push_back(j+aux1);
				aux1 = igus[i];
				j = 1;
				++i;
			}
			c = auxchar;
		}
		else {
			igus.push_back(j + aux1);
			continu = false;
		}
	}

	cin >> numinterv;
	if (numinterv == 0) {
		return false;
	}
	else {
		  // Lectura y ejecuci�n de cada intervalo
		for (int k = 0; k < numinterv; ++k) {
			cin >> aux1;
			cin >> aux2;
			if (aux1 >= aux2) {
				j = aux1;
				i = aux2;
			}
			else {
				i = aux1;
				j = aux2;
			}
			
			b = igus.size()-1;
			a = 0;
			pos = -1; 
			bool encontrado = false; 
			           //B�squeda binaria mejorada
			while ((a <= b) && !encontrado) {
				d = (a + b) / 2; 
				if(i == igus[d]) {encontrado = true;}
				else if (i < igus[d]) {b = d -1;}
				else{a = d + 1;}
			}
			if (encontrado) {
				pos = d+1;
			}
			else {
				pos = a;
			}
		
			if (j==i) {
				cout << "SI\n"; // Siempre SI
			}
			else if (j < igus[pos]) {
				cout << "SI\n";  // Si est� dentro del intervalo de repetici�n
			}
			else {
				cout << "NO\n";
			}

		}

		cout << "\n";
		cin.ignore(1);
		return true;
	}
} 
int main() {

	while (casoDePrueba()) {
	}
	return 0;
}

/*
   ACEPTA EL RETO. 132 Las Cartas del Abuelo.

   La complejidad de este ejercicio es considerable, aunque parece de una dificultad
   similar a otros, nos exigen implementar un algoritmo mucho m�s eficiente.

   El primer problema es que antes de saber la cantidad de intervalos y su longitud
   debemos adquirir completa la cadena de caracteres del abuelo, es imposible ir
   procesando cada elemento por separado.

   Cuando tenemos la cadena (con un getline por ejemplo) e intentamos comparar los 
   elementos en [i,j] se nos va de tiempo. El problema es que si hay "m" intervalos
   de longitud "n" la complejidad se nos dispara O(m*n)~O(n^2).

   Para poder disminuir el coste de la b�squeda dentro de un intervalo hay que evitar
   tanta comparaci�n (los saltos generados por un While->IF-ELSE son inadmisibles aqu�).

   La soluci�n propuesta consiste en proporcionar un vector de frecuencias acumuladas a partir
   de la cadena de entrada, ejemplo:

   cadena abuelo-> aaabbfghjjjjjdd
   igus={3,5,6,7,8,13,15}

   Con esto tenemos un vector considerablemente m�s peque�o que la cadena y adem�s ordenado.
   As� se pueden usar algoritmos de b�squeda eficientes (como la b�squeda binaria). Haciendo 
   una comparativa con la b�squeda de "i" en el vector "igus" y despu�s con el valor de "j" 
   es f�cil detectar si los intervalos son correctos en tiempo O(logn). De esta manera 
   tenemos O(m�logn) que aporta tiempos mejores y suficientes para superar el reto.

   El coste de generar el vector "igus" es inevitable, pero no es muy elevado. El resto es logar�tmico.
*/