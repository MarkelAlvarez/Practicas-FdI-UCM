#include <iostream>
using namespace std;

int main()
{
    int t, n; 

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (n == 0)
        {
            cout << 1 << endl;
        }
        else if (n == 3)
        {
             cout << 6 << endl;
        }
        else if (n < 5)
        {
             cout << n << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}