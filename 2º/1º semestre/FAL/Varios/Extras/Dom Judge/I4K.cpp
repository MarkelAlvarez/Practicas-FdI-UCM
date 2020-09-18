/*#include <iostream>

using namespace std;

int prod(long long int a, long long int b);

int main() {
	int numcasos;
	long long int a, b;

	cin >> numcasos;
	for (int c = 0; c < numcasos; c++) {
		cin >> a >> b;
		cout << prod(a, b) << endl;
	}

	return 0;
}

int prod(long long int a, long long int b) {
	if (b == 0) {
		return 0;
	}
	else if (b == 1) {
		return a;
	}
	else {
		if (b % 2 == 0) {
			return prod(2*a, b / 2);
		}
		else {
			return prod(2*a, b / 2) + a;
		}
	}
}*/