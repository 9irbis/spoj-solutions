#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stalls[100001];
int n, c;

int isPossible(int dist)
{
    int cowsPlaced = 1;
    int lastPos = stalls[0];
    for(int i=1; i<n; i++)
    {
        if (stalls[i] - lastPos >= dist)
        {
            cowsPlaced++;
            if (cowsPlaced == c)
                return 1;
            lastPos = stalls[i];
        }
    }
    return 0;
}

int binSearch()
{
    int start = 0, end = stalls[n-1];
    while (start < end)
    {
        int mid = (start+end)/2;
        if (isPossible(mid) == 1)
            start = mid+1;
        else
            end = mid;
    }
    return start-1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &c);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &stalls[i]);
        }
        sort(stalls, stalls + n);
        printf("%d\n", binSearch());
    }
    return 0;
}
