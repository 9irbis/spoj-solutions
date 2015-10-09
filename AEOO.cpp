#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=int(sqrt(i)); j++)
            if (i%j == 0)
                ans++;
    }
    cout << ans << endl;
    return 0;
}
