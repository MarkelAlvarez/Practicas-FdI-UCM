#include <iostream>
using namespace std;

int main()
{
    int n, arr[n], res=1, m = arr[n - 1], i;

    while((scanf("%d",&n) == 1) && (n != 0))
    {
        
        for(i = 0; i < n;i++)
        {
            cin>>arr[i];
        }
        
        for (i = n-2; i >= 0; i--)
        {
            if (arr[i] > m)
            {
                res++;
                m = arr[i];
            }
        }
        cout << res << '\n';
    }
 

    return 0;
}