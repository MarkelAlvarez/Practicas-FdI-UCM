/*#include <iostream>

using namespace std;

int algorithm(int* p, int numeropersonas);

int main() {
	int numerocasos, numeropersonas;
	int* p;

	cin >> numerocasos;
	for (int i = 0; i < numerocasos; i++) {
		cin >> numeropersonas;
		p = new int[numeropersonas];

		for (int j = 0; j < numeropersonas; j++) {
			cin >> p[j];			
		}

		cout << algorithm(p,numeropersonas) << endl;		
	}

	return 0;
}


int algorithm(int* p, int numeropersonas) {
	int counter = 0;
	for (int j = 0; j < numeropersonas; j++) {
		if (j > 0 && p[j - 1] > p[j]) {
			counter++;
		}
	}
	return counter;
}
*/


