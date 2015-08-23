#include <iostream>
#include <cmath>
using namespace std;

int rn(int x)
{
    while (x % 10 == 0)
        x /= 10;
    int power = -1, cp = x, ans = 0;
    while (cp)
    {
        cp /= 10;
        power++;
    }
    while (x)
    {
        ans += (x % 10) * pow(10, power);
        power--;
        x /= 10;
    }
    return ans;
}

int main()
{
    int tc, a, b, s;
    cin >> tc;
    while (tc--)
    {
        cin >> a >> b;
        s = rn(a) + rn(b);
        cout << rn(s) << "\n";
    }
    return 0;
}
