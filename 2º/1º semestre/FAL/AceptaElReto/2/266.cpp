#include <iostream>
using namespace std;

int main()
{
	int N, M, n, i, j;
	char matrix[505][505];
	char C, C1;

	while((scanf("%d%d", &N, &M)==2) && (N != 0 || M != 0))
	{
		cin.ignore();
		map<char,char> MAP;

		for(i = 0; i < N;i++) 
		{
			for(j = 0; j < M;j++)
			{
				scanf("%c",&matrix[i][j]);
				MAP[matrix[i][j]]=matrix[i][j];
			}
			cin.ignore();
		}
		
		scanf("%d", &n);
		cin.ignore();

		for(i = 0; i < n;i++)
		{
			scanf("%c %c", &C, &C1); cin.ignore();
			for(auto m:MAP)
			{
				if(m.second == C)
				{
					MAP[m.first]=C1;
				}
			}
		}
		
		for(i = 0; i < N;i++)
		{
			for(j = 0; j < M;j++)
			{
				printf("%c",MAP[matrix[i][j]]);
			}
			printf("\n");
		}
	}
	return 0;
}