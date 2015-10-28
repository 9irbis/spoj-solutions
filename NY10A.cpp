#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int P, n;
    string seq;
    cin >> P;
    vector<string> insertionOrder = {"TTT", "TTH", "THT", "THH", "HTT", "HTH",
    "HHT", "HHH"};
    for(int i=0; i<P; i++)
    {
        cin >> n >> seq;
        map<string, int> m;
        m["TTT"] = 0;
        m["TTH"] = 0;
        m["THT"] = 0;
        m["THH"] = 0;
        m["HTT"] = 0;
        m["HTH"] = 0;
        m["HHT"] = 0;
        m["HHH"] = 0;
        for(int i=0; i<38; i++) 
            m[seq.substr(i, 3)]++;
        cout << n << " ";
        for(int i=0; i<8; i++)
        {
            if (i == 0)
                cout << m[insertionOrder[i]];
            else
                cout << " " << m[insertionOrder[i]];
        }
        cout << endl;
    }
    return 0;
}
