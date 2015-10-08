#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<int, vector<int>> m;
    m[2] = {2, 4, 8, 6};
    m[3] = {3, 9, 7, 1};
    m[4] = {4, 6, 4, 6};
    m[7] = {7, 9, 3, 1};
    m[8] = {8, 4, 2, 6};
    m[9] = {9, 1, 9, 1};
    int t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        a = (a > 9 ? a%10 : a);
        if (b == 0)
            cout << 1 << "\n";
        else if (a == 0 || a == 1 || a == 5 || a == 6)
            cout << a << "\n";
        else
        {
            int ind = (b%4 ? (b%4)-1 : 3);
            cout << m[a][ind] << "\n";
        }
    }
    return 0;
}
