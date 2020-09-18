/*#include <iostream>
#include <cmath>

using namespace std;

int complementario(int numero, int &contador);
void inverso(int numero, int* v, int contador);

int main() {
	int numcasos, numero, contador, x; 
	int* v;
	cin >> numcasos;
	for (int i = 0; i < numcasos; i++) {
		cin >> numero;
		contador = 1;
		x = complementario(numero, contador);
		cout << x << " ";
		v = new int[contador];
		inverso(x, v, 0);
		for (int j = 0; j < contador; j++) {
			cout << v[j];
		}
		cout << endl;
	}



	return 0;
}

int complementario(int numero, int &contador) {
	if (numero > pow(10, contador)) {
		contador += 1;
		return complementario(numero, contador);
	}
	else {
		return pow(10, contador) - 1 - numero;
	}
}


void inverso(int numero, int* v,int contador) {
	v[contador] = numero % 10;
	if (numero / 10 != 0) {
		return inverso(numero / 10, v, contador + 1);
	}
}*/