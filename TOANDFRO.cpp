#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int cols;
    string msg;
    cin >> cols;
    while(cols)
    {
        cin >> msg;
        int sz = msg.size();
        int rows = sz/cols;
        vector<string> v;
        bool leftToRight = true;
        for(int i=0; i<sz; i += cols)
        {
            string r;
            if (leftToRight)
            {
                for(int j=0; j<cols; j++)
                {
                    r.push_back(msg[i+j]);
                }
            }
            else
            {
                for(int j=cols-1; j>=0; j--)
                {
                    r.push_back(msg[i+j]);
                }
            }
            leftToRight = !leftToRight;
            v.push_back(r);
        }
        for(int i=0; i<cols; i++)
            for(int j=0; j<rows; j++)
                cout << v[j][i];
        cout << "\n";
        cin >> cols;
    }
    return 0;
}
