#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
            cout << 2 << endl;
        else
        {
            unsigned long long ans = 2;
            int adder = 5;
            for(int i=2; i<=n; i++)
            {
                ans += adder;
                adder += 3;
            }
            cout << ans%1000007 << endl;
        }
    }
    return 0;
}
