#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int ng, nb;
    cin >> ng >> nb;
    while (ng != -1 && nb != -1)
    {
        int greater = max(ng, nb);
        int smaller = min(ng, nb);
        cout << greater/(smaller+1) + (greater%(smaller+1)>0) << "\n";
        cin >> ng >> nb;
    }
    return 0;
}
