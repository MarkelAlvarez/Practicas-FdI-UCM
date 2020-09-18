/*#include <iostream>

using namespace std;

int algorithm(int * v, int elems, int numvag, int &ganancias);

int main() {
	int numcasos,elems,numvag, ganancias ;
	int * v;

	cin >> numcasos;
	for (int i = 0; i < numcasos; i++) {
		ganancias = 0;
		cin >> elems;
		cin >> numvag;
		v = new int[elems];
		for (int j = 0; j < elems; j++) {
			cin >> v[j];
		}
		cout << algorithm(v, elems, numvag, ganancias) << " ";
		cout << ganancias << endl;
	}


	return 0;
}

int algorithm(int * v, int elems, int numvag, int &ganancias) {
	int numvagon = 0;
	int temp ;

	for (int i = 0; i < elems - numvag + 1; i++) {
		temp = 0;
		for (int j = i; j < i + numvag; j++) {
			temp += v[j];
		}
		if (temp >= ganancias) {
			ganancias = temp;
			numvagon = i;
		}
	}



	return numvagon;
}*/
