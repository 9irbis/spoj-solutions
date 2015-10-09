#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long int n;
        cin >> n;
        long long int x, mod = 0;
        for(long long int i=0; i<n; i++)
        {
            cin >> x;
            mod += x%n;
            if (mod >= n)
                mod = mod%n;
        }
        if (mod)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
