/*#include <iostream>
#include <cmath>

using namespace std;

bool algorithm(int* v, int inicio, int final, double alturamedia);


int main() {
	int numalturas;
	double alturamedia;
	int* v;

	while (cin >> numalturas) {
		v = new int[numalturas];
		alturamedia = 0;
		for (int i = 0; i < numalturas; i++) {
			cin >> v[i];
			alturamedia += v[i];
		}
		alturamedia /= numalturas;
		if (algorithm(v, 0, numalturas, alturamedia)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


	return 0;
}

bool algorithm(int* v, int inicio, int final, double alturamedia) {
	double sumauno = 0, sumados = 0;
	
	if (final - inicio > 2) {
		for (int i = inicio; i < final; i++) {
			if (v[i] >= alturamedia) {
				if (v[i] - alturamedia > (alturamedia / 2)) {
					return false;
				}
			}
			else {
				if (alturamedia - v[i] > (alturamedia / 2)) {
					return false;
				}
			}
			
			if (i < (inicio + final) / 2) {
				sumauno += v[i];
			}
			else {
				sumados += v[i];
			}
		}
		sumauno /= (final - inicio) / 2;
		sumados /= (final - inicio) / 2;
		if (algorithm(v, inicio, (inicio + final) / 2, sumauno) && algorithm(v, (inicio + final) / 2, final, sumados)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (v[inicio] >= alturamedia) {
			if (v[inicio] - alturamedia > (alturamedia / 2)) {
				return false;
			}
		}
		else {
			if (alturamedia - v[inicio] > (alturamedia / 2)) {
				return false;
			}
		}
		if (v[final - 1] >= alturamedia) {
			if (v[final - 1] - alturamedia > (alturamedia / 2)) {
				return false;
			}
		}
		else {
			if (alturamedia - v[final - 1] > (alturamedia / 2)) {
				return false;
			}
		}
		
			return true;
			
	}
}*/