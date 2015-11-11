#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll invMerge(vector<int>& v1, vector<int>& v2, vector<int>& v)
{
    int mid = v1.size();
    int i = 0, j = 0;
    ll count = 0;
    while(i<v1.size() && j<v2.size())
    {
        if (v1[i] <= v2[j])
            v.push_back(v1[i++]);
        else
        {
            v.push_back(v2[j++]);
            count += mid-i;
        }
    }
    while(i<v1.size())
        v.push_back(v1[i++]);
    while(j<v2.size())
        v.push_back(v2[j++]);
    return count;
}

ll invCount(vector<int>& v)
{
    ll count = 0;
    if (v.size() == 1)
        return count;
    vector<int> v1, v2;
    int mid = v.size()/2;
    for(int i=0; i<mid; i++)
        v1.push_back(v[i]);
    for(int i=mid; i<v.size(); i++)
        v2.push_back(v[i]);
    v.clear();
    count = invCount(v1);
    count += invCount(v2);
    count += invMerge(v1, v2, v);
    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, x;
        scanf("%d", &n);
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x);
            v.push_back(x);
        }
        printf("%lld\n", invCount(v));
    }
    return 0;
}
