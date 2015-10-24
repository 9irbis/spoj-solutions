#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != -1)
    {
        int bn = 1, multiplier = 1;
        bool isBeehive = false;
        while (bn <= n)
        {
            if (bn == n)
            {
                isBeehive = true;
                break;
            }
            bn += (multiplier*6);
            multiplier++;
        }
        if (isBeehive)
            cout << "Y\n";
        else
            cout << "N\n";
        cin >> n;
    }
    return 0;
}
