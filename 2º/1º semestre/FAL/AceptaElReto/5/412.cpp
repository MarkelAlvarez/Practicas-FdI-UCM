#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
bool visited[50][50];
int sheep[50][50];
int height,width;

void BFS()
{
	int cx,cy,i,a,b;

	queue<ii> qp;
	qp.push(make_pair(0,0));
	visited[0][0] = true;

	while(!qp.empty())
	{
		cx = qp.front().first;
		cy = qp.front().second;
		qp.pop();

		for(i = 0;i<4;++i)
		{
			a = cx+x[i];
			b = cy+y[i];

			if(a> = 0 && b> = 0 && a<height && b<width && sheep[a][b] && !visited[a][b])
			{
				qp.push(make_pair(a,b));
				visited[a][b] = true;
			}
		}
	}
}

int main()
{
	int i,j;
	char c;
	bool out;
	
	while(cin >> width >> height)
	{
		for(i = 0;i<height;++i)
		{
			for(j = 0;j<width;++j)
			{
				cin>>c;
				if(c =  = '.')
				{
					sheep[i][j] = 1;
				}
				else
				{
					sheep[i][j] = 0;
				}
				visited[i][j] = 0;
			}
		}

		BFS();
		out = false;

		for(i = 0;i<height && !out;++i)
		{
			for(j = 0;j<width && !out;++j)
			{
				if(!visited[i][j] && sheep[i][j])
				{
					out = true;
				}
			}
		}
		if(out)
		{
			cout << "SI\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}