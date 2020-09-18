/*#include <iostream>

using namespace std;

long long int algorithm(int n);

int main() {
	long long int n;

	while (cin >> n && n != -1) {
		cout << algorithm(n) << endl;
	}

	return 0;
}

long long int algorithm(int n) {
	long long int resultado, fib1 = 0, fib2 = 1;

	if (n == 0 || n == 1) {
		resultado = n;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			resultado = fib1 + fib2;
			fib1 = fib2;
			fib2 = resultado;
		}
	}

	return resultado;
}*/
