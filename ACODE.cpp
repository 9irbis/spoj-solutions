#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define  LL unsigned long long 

int main()
{
    string s;
    cin >> s;
    while (s != "0")
    {
        int sz = s.size();
        vector<int> dp(sz+1);
        dp[0] = 1;
        for(int i=1; i<=sz; i++)
        {
            if (s[i-1] != '0')
            {
                dp[i] = dp[i-1];
            }
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
            {
                dp[i] += dp[i-2];
            }
        }
        cout << dp[sz] << "\n";
        cin >> s;
    }
    return 0;
}
