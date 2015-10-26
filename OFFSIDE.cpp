#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int A, D, x;
    cin >> A >> D;
    while (A != 0 && D != 0)
    {
        vector<int> aDist, dDist;
        for(int i=0; i<A; i++)
        {
            cin >> x;
            aDist.push_back(x);
        }
        for(int i=0; i<D; i++)
        {
            cin >> x;
            dDist.push_back(x);
        }
        sort(aDist.begin(), aDist.end());
        sort(dDist.begin(), dDist.end());
        if (aDist[0] >= dDist[1])
            cout << "N\n";
        else
            cout << "Y\n";
        cin >> A >> D;
    }
    return 0;
}
