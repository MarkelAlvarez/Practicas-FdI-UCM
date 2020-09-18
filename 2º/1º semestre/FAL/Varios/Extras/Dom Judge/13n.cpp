/*#include <iostream>

using namespace std;
void algorithm(int* v, int &n);

int main() {
	int n;
	int* v;

	while (cin >> n && n != -1) {
		v = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		algorithm(v, n);

		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		delete[]v;
	}


	return 0;
}


void algorithm(int *v, int &n) {
	int counter = 0;

	while(counter  < n) {
		if (v[counter] % 2 == 1) {
			for (int j = counter; j < n - 1; j++) {
				v[j] = v[j + 1];
				
			}
			n--;
		}
		else {
			counter++;
		}
	}


}*/