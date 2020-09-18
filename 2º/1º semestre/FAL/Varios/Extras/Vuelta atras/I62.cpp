/*#include <iostream>

using namespace std;

void backtracking(int r, int q);
void resolver(int r, int q, int &nsol, bool **&marcas, int pos, int *sol);
bool isValid(int r, int q, int *sol);
bool isSolution(int r, int q, int pos);

int main() {
	int r, q;

	while (cin >> r && cin >> q && !(r == 0 && q == 0)) {
		backtracking(r, q);
	}



	return 0;
}

void backtracking(int r, int q) {
	bool **marcas;
	int *sol;
	int nsol = 0;
	marcas = new bool*[q + r];
	sol = new int[2];
	sol[0] = 0;
	sol[1] = 0;
	for (int i = 0; i < q + r; i++) {
		marcas[i] = new bool[r + q];		
		for (int j = 0; j < r + q; j++) {
			marcas[i][j] = true;			
		}
	}

	resolver(r, q, nsol, marcas, 0, sol);
	cout << nsol << endl;

}

void resolver(int r, int q, int &nsol, bool **&marcas, int pos, int *sol) {
	int i = 0;// i = 0 queens, else rooks

	while (i < 2 && pos < r + q) {
		int m = 0;
		while (m < r + q) {
			sol[i] += 1;
			if (isValid(r, q, sol) && marcas[m][pos]) {
				if (isSolution(r, q, pos)) {
					nsol += 1;
				}
				else {
					
					for (int t = 0; t < q + r; t++) {//este hace horizontal y vertical
						marcas[t][pos] = false;
						marcas[m][t] = false;
					}
					for (int t = m; t >= 0; t--) {//este hace horizontal y vertical
						marcas[t][pos] = false;
						marcas[m][t] = false;
					}
					if (i == 0) {
						int x = pos;
						for (int t = m; t < r + q; t++) {
							marcas[t][x] = false;
							x++;
						}
						x = pos;
						for (int t = m; t >= 0; t--) {
							marcas[t][x] = false;
							x++;
						}
					}
					resolver(r, q, nsol, marcas, pos + 1, sol);
					for (int t = 0; t < q + r; t++) {//este hace horizontal y vertical
						marcas[t][pos] = true;
						marcas[m][t] = true;
					}
					for (int t = m; t >= 0; t--) {//este hace horizontal y vertical
						marcas[t][pos] = true;
						marcas[m][t] = true;
					}
					if (i == 0) {
						int x = pos;
						for (int t = m; t < r + q; t++) {
							marcas[t][x] = true;
							x++;
						}
						x = pos;
						for (int t = m; t >= 0; t--) {
							marcas[t][x] = true;
							x++;
						}
					}
				}
			}
			sol[i] -= 1;
			m++;
		}
		i++;
	}
}

bool isValid(int r, int q, int *sol) {
	if (sol[0] > q) {
		return false;
	}
	else if (sol[1] > r) {
		return false;
	}
	else return true;
}

bool isSolution( int r, int q, int pos) {
	if (pos == r + q - 1) {
		return true;
	}

	else {
		return false;
	}
}*/