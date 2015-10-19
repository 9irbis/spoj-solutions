#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    unsigned long long n;
    while(t--)
    {
        scanf("%llu", &n);
        unsigned long long ans;
        ans = n*(n+2)*(2*n+1)/8;
        printf("%llu\n", ans);
    }
    return 0;
}
