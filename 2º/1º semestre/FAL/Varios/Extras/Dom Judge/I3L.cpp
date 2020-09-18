/*#include <iostream>


using namespace std;

void algorithm(long long int array[], int counter);


int main() {
	long long int array[10000];
	int n;
	long long int number;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (cin >> number && number != 0) {
			array[j] = number;
			j++;
		}
		algorithm(array, j);
	}

	return 0;
}

void algorithm(long long int array[], int counter) {
	long long int max = array[0], min = array[0];
	int vecesmax = 0, vecesmin = 0;
	for (int i = 0; i < counter; i++) {
		if (array[i] == max) {
			vecesmax++;
		}
		if (array[i] == min) {
			vecesmin++;
		}
		else if (array[i] < min) {
			min = array[i];
			vecesmin = 1;
		}
		else if (array[i] > max) {
			max = array[i];
			vecesmax = 1;
		}
	}

	cout << min << " " << vecesmin << " " << max << " " << vecesmax << endl;

}*/
