#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int tc = 1;
    string s;
    cin >> s;
    while (s[0] != '-')
    {
        int ans = 0;
        stack<char> braces;
        for(int i=0; i<s.size(); i++)
        {
            if (s[i] == '{')
                braces.push(s[i]);
            else if (s[i] == '}')
            {
                if (!braces.empty())
                    braces.pop();
                else 
                {
                    ans++;
                    braces.push('{');
                }
            }
        }
        if (!braces.empty())
            ans += braces.size()/2;
        cout << tc << ". " << ans << endl; 
        cin >> s;
        tc++;
    }
    return 0;
}

