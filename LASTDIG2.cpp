#include <iostream>
#include <string>
#include <vector>
#include <map>
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
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string a;
        unsigned long long b;
        cin >> a >> b;
        if (b == 0)
            cout << 1 << "\n";
        else
        {
            int lDig = a[a.size()-1] - '0';
            if (lDig == 0 || lDig == 1 || lDig == 5 || lDig == 6)
                cout << lDig << "\n";
            else  
                cout << m[lDig][(b%4 ? (b%4)-1 : 3)] << "\n";
        }
    }
    return 0;
}
