#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    string s, cp;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cp = s;
        int ln = cp.size();
        bool prependOne = false;
        for(int i=0; i<ln/2; i++)
        {
            cp[ln-1-i] = cp[i];
        }
        if (cp > s)
            cout << cp << "\n";
        else
        {
            if (ln % 2)
            {
                if (cp[ln/2] >= '0' && cp[ln/2] <= '8')
                {
                    cp[ln/2]++;
                    cout << cp << "\n";
                }
                else
                {
                    cp[ln/2] = '0';
                    int i = (ln/2)-1;
                    int j = (ln/2)+1;
                    while(i >= 0 && cp[i] == '9')
                    {
                        cp[i] = '0';
                        i--;
                    }
                    if (i >= 0)
                        cp[i]++;
                    else
                        prependOne = true;
                    while(j < ln && cp[j] == '9')
                    {
                        cp[j] = '0';
                        j++;
                    }
                    if (j < ln)
                        cp[j]++;
                    else
                        cp[ln-1] = '1';
                    if (prependOne)
                        cout << "1";
                    cout << cp << "\n";
                }
            }
            else
            {
                if (cp[ln/2] >= 0 && cp[ln/2] <= '8')
                {
                    cp[ln/2]++;
                    cp[ln/2-1]++;
                    cout << cp << "\n";
                }
                else
                {
                    cp[ln/2] = cp[ln/2-1] = '0';
                    int i = ln/2-2;
                    int j = ln/2+1;
                    while (i >= 0 && cp[i] == '9')
                    {
                        cp[i] = '0';
                        i--;
                    }
                    if (i >= 0)
                        cp[i]++;
                    else
                        prependOne = true;
                    while (j < ln && cp[j] == '9')
                    {
                        cp[j] = '0';
                        j++;
                    }
                    if(j < ln)
                        cp[j]++;
                    else
                        cp[ln-1] = '1';
                    if (prependOne)
                        cout << "1";
                    cout << cp << "\n";
                }
            }
        }
    }
    return 0;
}
