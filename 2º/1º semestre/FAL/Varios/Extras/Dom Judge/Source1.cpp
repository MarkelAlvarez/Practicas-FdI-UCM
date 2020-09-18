/* LOS DALTON 13.a
#include <iostream>

using namespace std;

int main() {
	int numero;
	int *p;
	bool creciendo = true;
	bool desconocidos = false;

	while (cin >> numero && numero > 0) {
		p = new int[numero];
		for (int i = 0; i < numero; i++) {
			cin >> p[i];
		}
		for (int i = 1; i < numero; i++) {
			if (p[i] == p[i - 1]) {
				desconocidos = true;
			}
			if (i > 1) {
				if (p[i] > p[i - 1] && !creciendo) {
					desconocidos = true;
				}
				else if (p[i] < p[i - 1] && creciendo) {
					desconocidos = true;
				}
			}
			else {
				if (p[i] > p[i - 1]) {
					creciendo = true;
				}
				else if (p[i] < p[i - 1]) {
					creciendo = false;
				}
			}
		}
		if (desconocidos) {
			cout << "DESCONOCIDOS" << endl;
		}
		else {
			cout << "DALTON" << endl;
		}
		creciendo = true;
		desconocidos = false;
	}




	return 0;
}*/