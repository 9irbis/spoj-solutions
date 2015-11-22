#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int h, tw, d;
        cin >> h >> tw >> d;
        vector<int> v(h);
        for(int i=0; i<h; i++)
            cin >> v[i];
        bool survive;
        for(int i=0; i<tw; i++)
        {
            survive = false;
            for(int j=0; j<h; j++)
            {
                if (v[j] > d)
                {
                    v[j] -= d;
                    survive = true;
                    break;
                }
            }
            if (!survive)
                break;
        }
        if (survive)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

