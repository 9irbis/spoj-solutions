#include <iostream>
using namespace std;

int main()
{
    int tc;
    long long k;
    cin >> tc;
    while (tc--)
    {
        cin >> k;
        long long ans = 192 + (k-1)*250;
        cout << ans << "\n";
    }
    return 0;
}
