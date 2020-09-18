/*#include <iostream>

using namespace std;

void nQueens(int solution[], int k, int n) {
	for (int i = 0; i < n; i++) {
		solution[k] = i;
		if (isValid(solution, k)) {
			if (k == n - 1)
				treatSolution(k, n);
			else
				nQueens(solution, k + 1, n);
		}
	}
}


bool isValid(int solution[], int k) {
	bool correct = true;
	int i = 0;
	while (i < k && correct) {
		if (solution[i] == solution[k] || abs(solution[k] - solution[i]) == k - i))
		correct = false;
	}
	return correct;
}

void treatSolution(int solution[], int n) {
	cout << "Solution: ";
	for (int i = 0; i < n; i++) cout << solution[i] << " ";
	cout << endl;
}


void nQueens(const int n) {
	int solution[n];
	nQueens(solution, 0, n);
}


int main() {
	int numcasos, reinas;

	cin >> numcasos;
	for (int i = 0; i < numcasos; i++) {
		cin >> reinas;
		nQueens(reinas);
	}


	return 0;
}
*/

