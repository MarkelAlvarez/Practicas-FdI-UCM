/*#include <iostream>
#include <cmath>

using namespace std;

int cercano(int *v, int x, int start, int end);

int main() {
	int numcasos,x,n;
	int *v;
	cin >> numcasos;

	for (int t = 0; t < numcasos; t++) {
		cin >> x;
		cin >> n;
		v = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << cercano(v, x, 0, n - 1) << endl;
	}
	return 0;
}


int cercano(int *v, int x, int start, int end) {
	int middle = (start + end) / 2;
	int r = v[middle];
	if (end - start > 1) {
		if (r == x) {
			return x;
		}
		else if (r > x) {			
			return cercano(v, x, start, middle);	}

		else {			
			return cercano(v, x, middle, end);	}

	}
	else {
		if (x == v[start] || x == v[end]) {
			return x;
		}
		else if ((x - r) <= (v[end] - x)) {
			return r;
		}
		else {
			return v[end];
		}
	}
}*/
