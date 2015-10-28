#include <iostream>
#include <string>
using namespace std;

int breakDownValue(int n)
{
    int ans = 0;
    while(n)
    {
        int r = n%10;
        ans += r*r;
        n /= 10;
    }
    return ans;
}

bool areEqual(int a, int b)
{
    return breakDownValue(a) == breakDownValue(b);
}

int main()
{
    int N, start, count = 1;
    cin >> N;
    start = breakDownValue(N);
    while (start > 9)
    {
        start = breakDownValue(start);
        count++;
    }
    if(start == 1 || start == 7)
        cout << count;
    else
        cout << -1;
    cout << endl;
    return 0;
}
