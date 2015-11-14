#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int b, n;
int ans[101][501];

void maxVal(int b, int n, const vector<int>& c, const vector<int>& v)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if (i == 0 || j == 0)
                ans[i][j] = 0;
            else if (c[i-1] > j)
                ans[i][j] = ans[i-1][j];
            else
                ans[i][j] = max(v[i-1] + ans[i-1][j-c[i-1]], ans[i-1][j]);
        }
    }
}

int main()
{
    scanf("%d%d", &b, &n);
    while (b && n)
    {
        vector<int> cost, val;
        for(int i=0; i<n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            cost.push_back(x);
            val.push_back(y);
        }
        fill_n(*ans, sizeof(ans)/sizeof(**ans), 0);
        maxVal(b, n, cost, val);
        int minCost, maxFun;
        maxFun = ans[n][b];
        for(int col=0; col<=b; col++)
        {
            if (ans[n][col] == maxFun)
            {
                minCost = col;
                break;
            }
        }
        printf("%d %d\n", minCost, maxFun);
        scanf("%d%d", &b, &n);
    }
    return 0;
}

