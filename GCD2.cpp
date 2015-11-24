#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd(b, a%b);
}

int BigIntMod(const string& b, int a)
{
    int num = 0;
    for(int i=0; i<b.size(); i++)
        num = (num*10 + (b[i]-'0'))%a;
    return num;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a;
        string b;
        cin >> a >> b;
        if (a == 0)
            cout << b << "\n";
        else
        {
            int temp = BigIntMod(b, a);
            printf("%d\n", gcd(a, temp));
        }
    }
    return 0;
}

