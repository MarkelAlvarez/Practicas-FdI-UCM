/*#include <iostream>

using namespace std;

void algorithm(int* v, int n, int &suma, int &pos, int &longitud);

int main() {
	int n, suma, pos, longitud;
	int* v;

	while (cin >> n && n != 0) {
		v = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		algorithm(v, n, suma, pos, longitud);
		cout << suma << " " << pos << " " << longitud << endl;
		delete[] v;
	}



	return 0;
}

void algorithm(int* v, int n, int &suma, int &pos, int &longitud) {
	suma = 0;
	pos = 0;
	longitud = 0;
	int sumaparcial, longitudp;

	for (int i = 0; i < n; i++) {
		sumaparcial = v[i];
		longitudp = 1;
		if (sumaparcial > suma) {
			suma = sumaparcial;
			pos = i;
			longitud = longitudp;
		}
		int j = i + 1;
		
		while (sumaparcial > 0 && j < n) {
			sumaparcial += v[j];
			longitudp++;
			j++;
			if (sumaparcial > suma) {
				suma = sumaparcial;
				pos = i;
				longitud = longitudp;
			}
		}		
	}

}*/