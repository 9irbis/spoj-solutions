#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int maximum(int a, int b, int c)
{
    int ans = max(a, b);
    return max(ans, c);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int h, w;
        cin >> h >> w;
        int floor[h][w];
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                scanf("%d", &floor[i][j]);
        for(int i=1; i<h; i++)
            for(int j=0; j<w; j++)
            {
                if (j > 0 && j < w-1)
                    floor[i][j] = maximum(floor[i][j]+floor[i-1][j],
                    floor[i][j]+floor[i-1][j-1], floor[i][j]+floor[i-1][j+1]);
                else if (j == 0)
                    floor[i][j] = max(floor[i][j]+floor[i-1][j],
                    floor[i][j]+floor[i-1][j+1]);
                else if (j == w-1)
                    floor[i][j] = max(floor[i][j]+floor[i-1][j],
                    floor[i][j]+floor[i-1][j-1]);
            }
        int mx = -1;
        for(int j=0; j<w; j++)
            mx = max(mx, floor[h-1][j]);
        cout << mx << endl;
   }

    return 0;
}
