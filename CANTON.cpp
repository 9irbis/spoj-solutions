#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int i = 1, ntr = 1, dtr = 1;
        while (i<n)
        {
            dtr++; i++;
            if(i == n) break;
            while(dtr > 1)
            {
                ntr++; dtr--; i++;
                if(i == n) break;
            }
            if(i == n) break;
            ntr++; i++;
            if(i == n) break;
            while(ntr > 1)
            {
                ntr--; dtr++; i++;
                if(i == n) break;
            }
        }
        printf("TERM %d IS %d/%d\n", n, ntr, dtr);
    }
    return 0;
}
