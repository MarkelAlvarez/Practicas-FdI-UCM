#include <iostream>
using namespace std;

struct cosa{
	int weight;
	int modificado;
	int inicial;
	bool operator<(const cosa &other)const{ return weight < other.weight; }
};

int main()
{
	int part = 0,inst = 0,numer,casos;

	while(cin >> part)
	{
		priority_queue<cosa> pq;
		
		cin>>inst;
		
		for(int i=0;i<inst;i++)
		{
			cin>>numer;

			pq.push(cosa{numer,2,numer});
		}
		
		casos = part - inst;
		
		while(casos--)
		{
			cosa t1 = pq.top();
			
			if((t1.inicial%t1.modificado)==0)
			{
				t1.weight=t1.inicial/t1.modificado;
				t1.modificado++;
			}
			else
			{
				t1.weight=t1.inicial/t1.modificado+1;
				t1.modificado++;
			}

			pq.pop();
			pq.push(t1);
		}
		 
		cosa t2 = pq.top();

		cout<<t2.weight<<"\n";
	}
	return 0;
}