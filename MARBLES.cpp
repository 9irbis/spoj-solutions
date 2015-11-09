#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll C(int n, int k)
{
    if (k > n/2)
        k = n-k;
    ll ans = 1;
    for(int i=1; i<=k; i++)
    {
        ans *= n;
        ans /= i;
        n--;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int r = n-k;
        ll ans = C(k+r-1, r);
        printf("%lld\n", ans);
    }
    return 0;
}   
