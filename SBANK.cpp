#include <iostream>
#include <map>
#include <string>
#include <limits>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        map<string, int> m; 
        for(int i=0; i<n; i++)
        {
            string line;
            getline(cin, line);
            m[line]++;
        }
        for(auto it=m.begin(); it!=m.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;
    }
    return 0;
}

