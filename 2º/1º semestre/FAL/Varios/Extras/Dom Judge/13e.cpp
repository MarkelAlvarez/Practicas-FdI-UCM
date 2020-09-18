/*#include <iostream>

using namespace std;

bool xxxx(int *v, int n, int p);

int main() {
	int numerocasos,n,p;
	int *v;
	cin >> numerocasos;

	for (int i = 0; i < numerocasos; i++) {
		cin >> n;
		cin >> p;
		v = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		if (xxxx(v, n, p)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

bool xxxx(int *v, int n, int p) {
	bool sort = true;
	int counter1 = 0, counter2 = p+1, numero;

	while (counter1 <= p && sort) {
		numero = v[counter1];
		while (counter2 < n && sort) {
			if (numero >= v[counter2]) {
				sort = false;
			}
			counter2++;
		}
		counter1++;
		counter2 = p + 1;
	}


	return sort;
}*/