#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int reqd, numfrds;
        vector<int> frds;
        cin >> reqd >> numfrds;
        for(int j=0; j<numfrds; j++)
        {
            int x;
            cin >> x;
            frds.push_back(x);
        }
        sort(frds.begin(), frds.end());
        printf("Scenario #%d:\n", i);
        int count = 0;
        for(auto it=frds.rbegin(); it!=frds.rend(); it++)
        {
            reqd -= *it;
            count++;
            if (reqd <= 0)
                break;
        }
        if (reqd <= 0)
            printf("%d\n\n", count);
        else
            printf("impossible\n\n");
    }

    return 0;
}
