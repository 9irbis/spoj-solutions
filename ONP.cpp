#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int t;
    string line;
    cin >> t;
    while(t--)
    {
        stack<char> ops;
        string ans = "";
        cin >> line;
        for(char c : line)
        {
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
                ops.push(c);
            else if (c >= 'a' && c <= 'z')
                ans.push_back(c);
            else if (c == ')')
            {
                ans.push_back(ops.top());
                ops.pop();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
