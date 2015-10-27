#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<t+1; i++)
    {
        double r, s;
        cin >> r;
        s = 4*r*r + 0.25;
        printf("Case %d: %.2lf\n", i, s);
    }
    return 0;
}
