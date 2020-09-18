/*#include <iostream>

using namespace std;

int algorithm(int* v, int nnums, int numero);

int main() {
	int numcasos, nnums, numero, x;
	int* v;
	cin >> numcasos;

	for (int i = 0; i < numcasos; i++) {
		cin >> nnums >> numero;
		v = new int[nnums ];
		for (int j = 0; j < nnums; j++) {
			cin >> v[j];
		}
		algorithm(v, nnums, numero) == x;
		if (x == 0) {
			cout << "NO" << endl;
		}
		else {
			cout << x << endl;
		}
	}



	return 0;
}

int algorithm(int* v, int nnums, int numero) {
	int pos;
	for (int i = 0; i < nnums; i++) {
		if (v[i] == numero) {
			pos = i;
		}
		else if (i > 0) {
			if (i < nnums - 1) {

			}
			if (v[i - 1] < numero && numero < v[i]) {

			}
		}
	}






}*/