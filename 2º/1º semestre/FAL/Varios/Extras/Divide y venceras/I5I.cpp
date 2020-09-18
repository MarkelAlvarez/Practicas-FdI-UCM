/*#include <iostream>

using namespace std;

int algoritmo(int *v,int start, int end);

int main() {
	int numelem;
	int *v;

	while (cin >> numelem && numelem != 0) {
		v = new int[numelem];
		for (int i = 0; i < numelem; i++) {
			cin >> v[i];
		}
		cout << algoritmo(v,0, numelem - 1) << endl;
	}




	return 0;
}

int algoritmo(int *v, int start, int end) {
	
	if (end - start > 1) {
		int middle = (start + end) / 2;
		int x = v[middle];
		if (x == v[start] && x == v[end]) {
			return 1;
		}
		else if (x == v[end]) {
			return algoritmo(v, start, middle);
		}
		else if (x == v[start]) {
			return algoritmo(v, middle, end);
		}
		else {
			return algoritmo(v, middle, end) + algoritmo(v, start, middle) - 1;
		}
	}
	else {
		if (v[end] == v[start]) {
			return 1;
		}
		else {
			return 2;
		}
	}

}*/