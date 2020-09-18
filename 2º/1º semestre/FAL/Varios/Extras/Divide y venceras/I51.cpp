/*#include <iostream>

using namespace std;



typedef struct {
	int a;
	int b;
	int c;
	int d;
}tMatrix;

tMatrix prod(tMatrix m1, tMatrix m2);
tMatrix empty();
tMatrix identidad();
tMatrix divideandconquer(int n, tMatrix matrix);

int main() {
	int n;
	tMatrix sol, ini;
	ini = empty();
	ini.b = 1;
	ini.c = 1;
	ini.d = 1;

	while (cin >> n && n != 0) {
		if (n == 1) {
			cout << ini.b << endl;
		}
		else if (n == 2) {
			cout << ini.d << endl;
		}
		else {
			sol = divideandconquer(n - 1, ini);
			cout << sol.d << endl;
		}
	}
	return 0;
}

tMatrix divideandconquer(int n, tMatrix matrix) {
	tMatrix m;

	if (n / 2 == 1) {
		return prod(matrix, matrix);
	}
	else {
		m = prod(matrix, matrix);
		if (n % 2 == 0) {			
			return divideandconquer(n / 2, m);
		}
		else {
			return prod(divideandconquer(n / 2, m), matrix);
		}
	}
}

tMatrix prod(tMatrix m1, tMatrix m2) {
	tMatrix p;

	p.a = (m1.a * m2.a + m1.b * m2.c) % 46337;
	p.b = (m1.a * m2.b + m1.b * m2.d) % 46337;
	p.c = (m1.c * m2.a + m1.d * m2.c) % 46337;
	p.d = (m1.c * m2.b + m1.d * m2.d) % 46337;

	return p;
}

tMatrix empty() {
	tMatrix matrix;
	matrix.a = 0;
	matrix.b = 0;
	matrix.c = 0;
	matrix.d = 0;
	return matrix;
}

tMatrix identidad() {
	tMatrix matrix;
	matrix = empty();
	matrix.a = 1;
	matrix.d = 1;
	return matrix;
}*/