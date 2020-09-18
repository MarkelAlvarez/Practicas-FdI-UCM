/*#include <iostream>
#include <cmath>

using namespace std;

void algorithm(long long int poli, int digitos);

int main() {
	long long int poli;
	int digitos;

	cin >> poli;
	cin >> digitos;

	algorithm(poli, digitos);



	return 0;
}

void algorithm(long long int poli, int digitos) {
	long long int numero;
	bool polidivisible = true;
	numero = poli;
	cout << numero << endl;
	while (numero < pow(10,digitos)) {
		for (int i = 1; i < digitos; i++) {
			numero = numero + i * (pow(10,digitos - i - 1));
		}
		int j = 2;
		while (polidivisible && j < digitos) {
			long long int x = numero / pow(10, digitos - j - 1);
			if (x % j != 0) {
				polidivisible = false;
			}
			j++;
		}
		if (polidivisible) {
			cout << numero << endl;
		}
		polidivisible = true;
	}
	cout << "---" << endl;

}*/