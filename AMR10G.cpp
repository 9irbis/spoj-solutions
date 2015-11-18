#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t, n, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        vector<int> heights;
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d", &x);
            heights.push_back(x);
        }
        if (k == 1)
            printf("%d\n", 0);
        else
        {
            int minH = 1000000001;
            sort(heights.begin(), heights.end());
            for(int i=0; i<=n-k; i++)
            {
                if (heights[i+k-1]-heights[i] < minH)
                    minH = heights[i+k-1]-heights[i];
            }
            printf("%d\n", minH);
        }
    }
    return 0;
}

