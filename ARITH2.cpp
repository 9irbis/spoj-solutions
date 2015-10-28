#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> noskipws >> n;
    while(n--)
    {
        char ch;
        bool newToken = true;    // ready for new token
        long long newNum = -1, temp = 0;
        stack<char> ops;
        do{
            cin >> ch;
            if (ch==' ' || ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='=')
            {
                if (newNum > -1)
                {
                    if (ops.empty())
                        temp = newNum;
                    else
                    {
                        char op = ops.top();
                        ops.pop();
                        if (op == '+')
                            temp += newNum;
                        else if (op == '*')
                            temp *= newNum;
                        else if (op == '/')
                            temp /= newNum;
                        else if (op == '-')
                            temp -= newNum;
                    }
                    newNum = -1;
                }
                if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
                    ops.push(ch);
                newToken = true;
            }
            else if (ch <= '9' && ch >= '0')
            {
                if (newToken)
                {
                    newNum = ch-'0';
                    newToken = false;
                }
                else
                    newNum = newNum*10 + (ch-'0');
            }
        }while(ch != '=');
        cout << temp << "\n";
    }
    return 0;
}
