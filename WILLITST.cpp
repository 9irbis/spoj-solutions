#include <iostream>
using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    if (n == 1)
        printf("TAK\n");
    else
    {
        bool willStop = false;
        long long i = 2;
        while (i <= n)
        {
            if (i == n)
            {
                willStop = true;
                break;
            }
            i *= 2;
        }
        if (willStop)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}
