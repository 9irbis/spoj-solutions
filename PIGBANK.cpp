#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 2147483247;
int cap, arr[10001];

int minVal(int cap, int n, const vector<int>& val, const vector<int>& wt)
{
    for(int w=1; w<=cap; w++)
    {
        for(int i=0; i<n; i++)
        {
            if (wt[i] == w)
                arr[w] = min(arr[w], val[i]);
            else if (wt[i] < w && arr[w-wt[i]] != INF)
                arr[w] = min(arr[w], val[i] + arr[w-wt[i]]);
        }
    }
    return arr[cap];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ew, fw, n;
        vector<int> val, wt;
        scanf("%d %d", &ew, &fw);
        cap = fw - ew;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            val.push_back(x);
            wt.push_back(y);
        }
        fill_n(arr, sizeof(arr)/sizeof(*arr), INF);
        int ans =  minVal(cap, n, val, wt);
        if (ans == INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",
            ans);
    }
    return 0;
}
