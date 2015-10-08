#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while(t--) 
    {
        cin >> n;
        vector<int> m, w;
        int x, ans = 0;
        for(int i=0; i<n; i++)
        {
            cin >> x;
            m.push_back(x);
        }
        for(int i=0; i<n; i++)
        {
            cin >> x;
            w.push_back(x);
        }
        sort(m.begin(), m.end());
        sort(w.begin(), w.end());
        for(int i=0; i<n; i++)
            ans += m[i]*w[i];
        cout << ans << "\n";
    }
    return 0;
}
