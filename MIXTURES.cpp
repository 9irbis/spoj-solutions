#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int s[101][101];

int sumRange(const vector<int>& v, int s, int e)
{
    int sum = 0;
    for(int i=s; i<=e; i++)
        sum += v[i];
    return sum;
}

int minSmoke(const vector<int>& v, int n)
{
    for (int b=1; b<=n-1; b++)
    {
        for(int i=0; i<=n-b-1; i++)
        {
            int j = i+b;
            s[i][j] = INF;
            for(int k=i; k<j; k++)
            {
                s[i][j] = min(s[i][j], s[i][k] + s[k+1][j] + (sumRange(v, i,
                k)%100)*(sumRange(v, k+1, j)%100));
            }
        }
    }
    return s[0][n-1];
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        fill_n(*s, sizeof(s)/sizeof(**s), 0);
        cout << minSmoke(v, n) << endl;
    }
    return 0;
}
