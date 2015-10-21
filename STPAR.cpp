#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while(n)
    {
        vector<int> trucks;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            trucks.push_back(x);
        }
        stack<int> S;
        int i = 1, j = 0;
        while (i <= n && j < n)
        {
            if (trucks[j] == i)
            {
                j++;
                i++;
            }
            else if (!S.empty() && S.top() == i)
            {
                S.pop();
                i++;
            }
            else
            {
                S.push(trucks[j]);
                j++;
            }
        }
        while(i <= n)
        {
            if (!S.empty() && S.top() == i)
            {
                S.pop();
                i++;
            }
            else
                break;
        }
        if (S.empty())
            printf("yes\n");
        else
            printf("no\n");
        scanf("%d", &n);
    }
    return 0;
}
