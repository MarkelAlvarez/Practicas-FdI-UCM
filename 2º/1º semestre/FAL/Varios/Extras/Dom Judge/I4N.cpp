/*#include <iostream>

using namespace std;

long long int resuelveCaso(long long int numero);

int main() {
	long long int numero;

	while (cin >> numero) {
		cout << resuelveCaso(numero) << endl;
	}


	return 0;
}

long long int resuelveCaso(long long int numero) {
	int modulo = numero % 10;
	int cifra;
	if (modulo % 2 == 0) {
		cifra = 0;
	}
	else {
		cifra = modulo;
	}
	if (numero / 10 != 0) {
		if (cifra == 0) {
			return resuelveCaso(numero / 10);
		}
		else {
			return cifra + 10 * resuelveCaso(numero / 10);
		}
		
	}
	else {
		return cifra;
	}



}*/