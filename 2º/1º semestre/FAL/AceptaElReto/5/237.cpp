/*SOLUCION ABAJO*/
// ^ significa y
#include <iostream>
using namespace std;

//int numDigitos(int n);
bool esPolidivisible(int n, int nd);

int main(int argc, char const *argv[])
{   
	int n, nd;
	
	while(cin >> n)
	{
		if (n != 0)
		{
			//nd = numDigitos(n);
	
			if (esPolidivisible(n, /*nd*/to_string(n).length()))
			{
				cout << "POLIDIVISIBLE" << endl;
			}
			else
			{
				cout << "NO POLIDIVISIBLE" << endl;
			}
		}
	}

	return 0;
}

/*int numDigitos(int n)
{
	int i = 0;
	
	while(n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;

	return i;
}*/

//Pre: n >= 0 ^ numDigitos de n > 1
bool esPolidivisible(int n, int nd)
{
	/*int aux2;
	bool aux;

	if (n < 10)
	{
		nd = 1;
		return true;
	}

	aux = esPolidivisible(n/10, nd);
	nd = aux2 - 1;

	return ((n % nd == 0) && aux);*/

	if(nd == 1)
	{
		return true;
	}

	return esPolidivisible(n/10, nd-1) && (n%nd == 0);
}

/* Si nos pide que solo devuelva un digito

bool esPolidivisible(int n)
{
	int dummy;

	return	esPolidivisible(n, dummy);
}

*/

#include <iostream>
using namespace std;

bool solve(long long int n, int s)
{
	if(s == 1)
	{
		return true;
	}
  
	return solve(n/10, s-1) && (n%s==0);
}

int main()
{
	long long int n;
  
	while((scanf("%lld", &n) == 1) && (n != 0))
	{
		if(solve(n, to_string(n).length()))
		{
			printf("POLIDIVISIBLE\n");
		}
		else
		{
			printf("NO POLIDIVISIBLE\n");
		}
	}
  
	return 0;
}