#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, nH, nQ, ntQ, nPizzas;
    nH = nQ = ntQ = 0;
    nPizzas = 1;
    scanf("%d", &n);
    vector<string> v;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "1/4")
            nQ++;
        else if (s == "1/2")
            nH++;
        else if (s == "3/4")
            ntQ++;
    }
    nPizzas += ntQ;
    nPizzas += (nH+1)/2;
    int leftQ = (nH%2)*2 + ntQ;
    if (nQ > leftQ)
        nPizzas += ((nQ-leftQ)/4)+((nQ-leftQ)%4>0);
    cout << nPizzas << endl;
    return 0;
}

