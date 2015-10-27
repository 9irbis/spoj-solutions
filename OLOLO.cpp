#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    scanf("%d", &n);
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i+=2)
    {
        if (i == n-1 || v[i] != v[i+1])
        {
            cout << v[i] << endl;
            break;
        }
    }
    return 0;
}
