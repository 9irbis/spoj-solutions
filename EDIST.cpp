#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[3000][3000];

int minOps(const string& A, const string& B)
{
    int m = A.size();
    int n = B.size();
    for(int i=0; i<m+1; i++)
        dp[i][0] = i;
    for(int j=0; j<n+1; j++)
        dp[0][j] = j;
    for(int j=1; j<n+1; j++)
    {
        for(int i=1; i<m+1; i++)
        {
            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
            {
                int temp = min(dp[i-1][j]+1, dp[i][j-1]+1);
                int mn = min(temp, dp[i-1][j-1]+1);
                dp[i][j] = mn;
            }
        }
    }
    return dp[m][n];
}

int main()
{
    int t;
    cin >> t;
    string A, B;
    while(t--)
    {
        cin >> A >> B;
        cout << minOps(A, B) << endl;
    }
    return 0;
}
