#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n)
    {
        vector<int> a;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        bool isAmbiguous = true;
        for(int i=1; i<=n; i++)
        {
            if(a[a[i-1]-1] != i)
            {
                isAmbiguous = false;
                break;
            }
        }
        if (isAmbiguous)
            cout << "ambiguous\n";
        else
            cout << "not ambiguous\n";
        cin >> n;
    }
    return 0;
}
