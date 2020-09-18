/*#include <iostream>

using namespace std;

int algorithm(int* v, int n);

int main() {
	int n;
	int *v;

	while (cin >> n) {
		v = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		cout << algorithm(v, n) << endl;


		delete[] v;
	}



	return 0;
}

int algorithm(int* v, int n) {
	int result = 1;
	int min = v[0], pos;
	if (n > 1) {
		for (int i = 0; i < n; i++) {
			if (v[i] <= min) {
				min = v[i];
				pos = i;
			}
		}
		
			for (int i = 0; i < pos - 1; i++) {
				if (v[i] < v[i + 1]) {
					result = 0;
				}
			}
		
		if (result == 1) {
			for (int i = pos; i < n - 1; i++) {
				if (v[i] > v[i + 1]) {
					result = 0;
				}
			}
		}
	}
	return result;
}*/
