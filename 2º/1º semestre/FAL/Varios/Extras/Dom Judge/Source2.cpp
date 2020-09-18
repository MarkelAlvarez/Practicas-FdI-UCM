//13b
/*#include <iostream>

using namespace std;

int main() {
	int numero, n;
	int *p;
	bool crece;
	int picos, valles;
	bool iguales = false;
	cin >> numero;

	for (int i = 0; i < numero; i++) {
		cin >> n;
		picos = 0;
		valles = 0;
		p = new int[n];

		for (int j = 0; j < n; j++) {
			cin >> p[j];
		}

		for (int j = 1; j < n; j++) {
			if (p[j] == p[j - 1]) {
				iguales = true;
			}
			else {
				iguales = false;
			}
			if (j == 1) {
				if (p[j] < p[j - 1]) {
					crece = false;
				}
				else {
					crece = true;
				}
			}
			else {
				if (p[j] < p[j - 1]  && crece && !iguales) {
					picos++;
					crece = false;
				}
				else if (p[j] > p[j - 1] && !crece && !iguales) {
					valles++;
					crece = true;
				}				
			}			
		}
		cout << picos << " " << valles << endl;
		iguales = false;
	}


	return 0;
}*/