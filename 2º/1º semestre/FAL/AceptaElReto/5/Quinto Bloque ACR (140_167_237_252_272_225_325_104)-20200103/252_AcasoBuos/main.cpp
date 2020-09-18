/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2019.

ACEPTA EL RETO. 252 �Acaso hubo b�hos ac�?

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


bool palindromo(const vector <char>& v, int ini, int fin) {
	bool palin = false; 

	if ((fin-ini) < 1) { // Caso base. No quedan letras o queda solo una.
		palin = true;
	}
	else { // Caso recursivo. Quedan letras por procesar
		if (v[ini] == v[fin]) {
			palin = palindromo(v, ini+1, fin-1); //Quitamos los extremos modificando los "punteros"
		} 
	}
	return palin; 
}


bool resuelveCaso() {

	int pos, tam;
	string cad;
	vector <char> v;
	getline(cin, cad);

	if (cad!="XXX") {
		tam = cad.length();
		for (int i = 0; i < tam; ++i) {
			if (cad.at(i) == ' ') {
				cad.erase(i, 1); // Eliminaci�n de espacios.
				--i;
				--tam;
			}
			else {
				v.push_back(tolower(cad.at(i))); //Guardado en vector min�sculas.
			}
		}

		if (palindromo(v, 0, v.size()-1)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
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
   ACEPTA EL RETO. 252 �Acaso hubo b�hos ac�?

   Siempre devuelve false a menos que sean todos las recursiones true, si falla se corta la recursi�n.
   Es una especie de algoritmo de recursi�n final, pero con truncamiento.

   Respecto a la preparaci�n de la cadena de caracteres, vamos eliminando los espacios desde un string
   y despu�s guard�ndolo en un vector de CHAR ya en min�sculas. As� las comparaciones son directas.

*/