#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long x, y, s, n, a, d;
        scanf("%lld%lld%lld", &x, &y, &s);
        n = 2*s/(x+y);
        d = (y-x)/(n-5);
        a = x-2*d;
        printf("%lld\n", n);
        for(int i=1; i<=n; i++)
        {
            if(i==1)
                printf("%lld", a+(i-1)*d);
            else
                printf(" %lld", a+(i-1)*d);
        }
        printf("\n");
    }
    return 0;
}
