#include <iostream>
using namespace std;

int main()
{
    int tc, n, x;
    cin >> tc;
    while (tc--)
    {
        int ans = 0;
        cin >> n;
        x = 5;
        while (x <= n)
        {
            ans += n/x;
            x *= 5;
        }
        cout << ans << "\n";
    }
    return 0;
}
