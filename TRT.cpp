#include <iostream>
#include <algorithm>
using namespace std;

int arr[2001];
int n;
int rev[2001][2001];

long max_revenue(int l, int r)
{
    if (rev[l][r] > 0)
        return rev[l][r];
    if (l == r)
        rev[l][r] = (1+l-0+n-1-r)*arr[l];
    else
        rev[l][r] = max((1+l-0+n-1-r)*arr[l]+max_revenue(l+1, r),
        (1+l-0+n-1-r)*arr[r]+max_revenue(l, r-1));
    return rev[l][r];
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("%ld\n", max_revenue(0, n-1));
    return 0;
}
