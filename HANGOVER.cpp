#include <iostream>
using namespace std;

int main()
{
    double overhang;
    cin >> overhang;
    while (overhang)
    {
        int n = 2;
        double l = 1.0/n;
        while (l < overhang)
        {
            n++;
            l += 1.0/n;
        }
        cout << n-1 << " card(s)" << endl;
        cin >> overhang;
    }
    return 0;
}
