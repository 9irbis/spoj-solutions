#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> v;
        bool possible = true;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for(int i=n-1; i>0; i--)
        {
            if (v[i] == 0)
                continue;
            int mn = min(v[i], v[i-1]);
            v[i] -= mn;
            v[i-1] -= mn;
            if (v[i] > v[i-1])
            {
                possible = false;
                break;
            }
        }
        if (v[0] != 0)
            possible = false;
        if(possible && n>1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
