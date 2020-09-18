#include <iostream>
#include <algorithm>
using namespace std;

void solucion(int casos);

int main()
{
	int casos;

	cin >> casos;
	
	solucion(casos);

	return 0;
}

void solucion(int casos)
{
	while (casos--)
	{
		int C, V, A[17] = {}, f = 0;
		char s[17], mm[3] = "CV";

		cin >> C >> V;

		for (int i = C; i < C+V; i++)
		{
			A[i] = 1;
		}

		do {
			for (int i = 0; i < C+V; i++)
			{
				s[i] = mm[A[i]];
			}

			s[C+V] = '\0';

			if (f)
			{
				putchar(' ');
			}
			
			cout << s;

			f = 1;
		} while (next_permutation(A, A+C+V));
		
		puts("");
	}
}