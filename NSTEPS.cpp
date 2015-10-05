#include <iostream>
using namespace std;

int main()
{
    int N, x, y;
    cin >> N;
    while (N--)
    {
        cin >> x >> y;
        if (x-y == 0 || x-y == 2)
        {
            if (x%2 == 0)
                cout << x+y << "\n";
            else
                cout << x+y-1 << "\n";
        }
        else
            cout << "No Number\n";
    }
    return 0;
}
