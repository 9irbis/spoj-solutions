#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    while (a || b || c)
    {
        if (a == b == c)
            cout << "GP " << c << "\n";
        else if (2*b == a+c)
            cout << "AP " << c+c-b << "\n";
        else if (c/b == b/a)
            cout << "GP " << c*(c/b) << "\n";
        cin >> a >> b >> c;
    }
    
    return 0;
}
