/*#include <iostream>

using namespace std;

bool cxpelos(int *v, int start, int end);
bool divertido(int *v, int numelem, int d);

int main() {
	int numcasos, numelem, d;
	int *v;

	cin >> numcasos;
	for (int t = 0; t < numcasos; t++) {
		cin >> d;
		cin >> numelem;
		v = new int[numelem];
		for (int i = 0; i < numelem; i++) {
			cin >> v[i];
		}
		if (cxpelos(v, 0, numelem - 1) && divertido(v,numelem,d)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}




	return 0;
}


bool cxpelos(int *v, int start, int end) {
	int middle = (start + end) / 2;
	if (middle != start) {
		if (cxpelos(v, start, middle) && cxpelos(v, middle + 1, end) && v[middle + 1] - v[middle] <= 1 && v[middle + 1] - v[middle] >0) {
			return true;
		}
		else return false;
	}
	else {
		if (middle == end) {
			return true;
		}
		else {
			if (v[end] - v[middle] <= 1) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool divertido(int *v, int numelem, int d) {
	int numero = v[0];
	int cuenta = 0, cuentatemp = 0;
	for (int i = 0; i < numelem; i++) {
		if (v[i] == numero) {
			cuentatemp++;
		}
		else {
			numero = v[i];
			if (cuentatemp > cuenta) {
				cuenta = cuentatemp;
			}
			cuentatemp = 1;
			
		}
	}
	if (cuenta == d) {
		return true;
	}
	else {
		return false;
	}
}
*/