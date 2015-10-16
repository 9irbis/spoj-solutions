#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    string a, op1, b, op2, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> op1 >> b >> op2 >> c;
        if (c.find("machula") != -1)
        {
            printf("%s + %s = %d\n", a.c_str(), b.c_str(), stoi(a)+stoi(b));
        }
        else if (a.find("machula") != -1)
        {
            printf("%d + %s = %s\n", stoi(c)-stoi(b), b.c_str(), c.c_str());
        }
        else if (b.find("machula") != -1)
        {
            printf("%s + %d = %s\n", a.c_str(), stoi(c)-stoi(a), c.c_str());
        }
    }
    return 0;
}
