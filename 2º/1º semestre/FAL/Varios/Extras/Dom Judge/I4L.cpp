/*#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string resuelveCaso();

string algoritmo(int numero, string acumulado);

int main() {
	int numcasos;
	cin >> numcasos;

	for (int i = 0; i < numcasos; i++) {
		cout << resuelveCaso() << endl;
	}


	return 0;
}

string resuelveCaso() {
	int numero;
	cin >> numero;
	string resultado = algoritmo(numero, "");
	return resultado;
}

string algoritmo(int numero, string acumulado) {
	if (numero > 2) {
		if (numero % 2 == 0) {
			acumulado = "0" + acumulado;
		}
		else {
			acumulado = "1" + acumulado;
		}
		return algoritmo(numero / 2, acumulado);
	}
	else {
		if (numero % 2 == 0) {
			acumulado = "0" + acumulado;
		}
		else {
			acumulado = "1" + acumulado;
		}
		if (numero / 2 == 1) {
			acumulado = "1" + acumulado;
		}
		
		return  acumulado;
	}
}*/

