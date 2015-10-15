#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, long long> cache;

long long solve(int n)
{
    if (n == 0)
        return 0;
    if (cache[n] != 0)
        return cache[n];
    long long aux = solve(n/2) + solve(n/3) + solve(n/4);
    if (aux > n)
        cache[n] = aux;
    else
        cache[n] = n;
    return cache[n];
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << solve(n) << "\n";
    }
    return 0;
}
