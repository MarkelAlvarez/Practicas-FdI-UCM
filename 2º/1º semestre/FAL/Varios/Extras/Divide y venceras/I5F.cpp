/*#include <iostream>

using namespace std;

bool cxpelos(int *v, int start, int end);

int main() {
	int numcasos, numelem;
	int *v;

	cin >> numcasos;
	for (int t = 0; t < numcasos; t++) {
		cin >> numelem;
		v = new int[numelem];
		for (int i = 0; i < numelem; i++) {
			cin >> v[i];
		}
		if (cxpelos(v,0, numelem - 1)) {
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
		if (cxpelos(v, start, middle) && cxpelos(v, middle + 1, end) && v[middle + 1] - v[middle] <= 1) {
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



}*/