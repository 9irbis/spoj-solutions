#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,x;
    cin >> n;
    while (n != -1)
    {
        vector<int> v;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            cin >> x;
            sum += x;
            v.push_back(x);
        }
        if (sum % n != 0)
            cout << -1 << "\n";
        else
        {
            sort(v.begin(), v.end());
            int ans = 0;
            int avg = sum/n;
            for(auto a : v)
            {
                if (a >= avg )
                    break;
                ans += avg - a;
            }
            cout << ans << "\n";
        }
        cin >> n;
    }
    return 0;
}
