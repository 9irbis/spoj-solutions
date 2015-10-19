#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int ng, nm, x;
        cin >> ng >> nm;
        vector<int> vg, vm;
        for(int i=0; i<ng; i++)
        {
            cin >> x;
            vg.push_back(x);
        }
        for(int i=0; i<nm; i++)
        {
            cin >> x;
            vm.push_back(x);
        }
        int maxG = *max_element(vg.begin(), vg.end());
        int maxM = *max_element(vm.begin(), vm.end());
        if (maxM > maxG)
            cout << "MechaGodzilla\n";
        else
            cout << "Godzilla\n";
    }
    return 0;
}
