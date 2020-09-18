/*#include <iostream>

using namespace std;

void algorithm(char* v, int nchars);

int main() {
	int ncasos, nchars;
	char* v;

	cin >> ncasos;
	for (int i = 0; i < ncasos; i++) {
		cin >> nchars;
		v = new char[nchars];
		for (int t = 0; t < nchars; t++) {
			cin >> v[t];
		}
		algorithm(v, nchars);

		for (int t = 0; t < nchars; t++) {
			cout << v[t] << " ";
		}
		cout << endl;
	}



	return 0;
}

void algorithm(char* v, int nchars) {
	char x;
	
	for (int i = 1; i < nchars; i++) {
		
		int j = i;
		
		while (j > 0) {
			x = v[j];
			if (x == 'r' && v[j - 1] != x) {
				v[j] = v[j - 1];
				v[j - 1] = x;				
			}
			else if (x == 'w' && v[j-1] == 'b') {
				v[i] = v[j];
				v[j] = x;				
			}
			j--;
		}
	}

}*/