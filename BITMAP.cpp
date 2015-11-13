#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int bmap[183][183];
int ans[183][183];
bool visited[183][183];
int n, m;

struct Pixel{
    int r, c, d;
    Pixel(int x, int y, int z): r(x), c(y), d(z) {}
};

void bfs(int i, int j)
{
    memset(visited, 0, sizeof(visited));
    queue<Pixel> Q;
    visited[i][j] = true;
    Q.push(Pixel(i, j, 0));
    while (!Q.empty()) 
    {
        Pixel p = Q.front();
        int row = p.r;
        int col = p.c;
        int dist = p.d;
        Q.pop();
        ans[row][col] = min(ans[row][col], dist);
        if (row-1 >= 0 && bmap[row-1][col] == 0 && !visited[row-1][col])
        {
            visited[row-1][col] = true;
            Q.push(Pixel(row-1, col, dist+1));
        }
        if (row+1 < n && bmap[row+1][col] == 0 && !visited[row+1][col])
        {
            visited[row+1][col] = true;
            Q.push(Pixel(row+1, col, dist+1));
        }
        if (col-1 >= 0 && bmap[row][col-1] == 0 && !visited[row][col-1])
        {
            visited[row][col-1] = true;
            Q.push(Pixel(row, col-1, dist+1));
        }
        if (col+1 < m && bmap[row][col+1] == 0 && !visited[row][col+1])
        {
            visited[row][col+1] = true;
            Q.push(Pixel(row, col+1, dist+1));
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; i++)
        {
            char word[m+1];
            scanf("%s", word);
            for(int j=0; j<m; j++)
                bmap[i][j] = word[j]- '0';
        }
        fill_n(*ans, sizeof(ans)/sizeof(**ans), 1000);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                if (bmap[i][j] == 1)
                    bfs(i, j);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}

