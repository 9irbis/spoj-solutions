#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int N, start;
        scanf("%d%d", &N, &start);
        if (start == 0)
            cout << "Airborne wins.\n";
        else
            cout << "Pagfloyd wins.\n";
    }
}
