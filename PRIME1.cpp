#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 31623;

bool nonPrimes[MAX];

void build_sieve()
{
    nonPrimes[0] = nonPrimes[1] = true;
    int p = 2;
    while (pow(p, 2) < MAX)
    {
        for(int i=pow(p, 2); i<MAX; i+=p)
        {
            nonPrimes[i] = true;
        }
        int j = p+1;
        while (j < MAX)
        {
            if (!nonPrimes[j])
                break;
            j++;
        }
        p = j;
    }
}

int main()
{
    build_sieve();
    int tc, a, b;
    cin >> tc;
    while (tc--)
    {
        cin >> a >> b;
        for(int i=max(2, a); i<=b; i++)
        {
            bool isPrime = true;
            int ub = floor(sqrt(i));
            for(int j=2; j<=ub; j++)
            {
                if (!nonPrimes[j])
                {
                    if (i % j == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
            }
            if (isPrime)
                cout << i << "\n";
        }
        cout << "\n";
    }
    return 0;
}
