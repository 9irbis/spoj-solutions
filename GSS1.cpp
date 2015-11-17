#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int lmax, rmax, anymax, sum;
};

Node st[131072];

Node combine(Node l, Node r)
{
    Node tmp;
    tmp.lmax = max(l.lmax, l.sum+r.lmax);
    tmp.rmax = max(r.rmax, r.sum+l.rmax);
    tmp.anymax = max(l.rmax+r.lmax, max(l.anymax, r.anymax));
    tmp.sum = l.sum + r.sum;
    return tmp;
}

Node findMaxSubarray(Node *st, int ss, int se, int qs, int qe, int si)
{
    if (qs == ss && qe == se)
        return st[si];
    int mid = (ss+se)/2;
    if (qe <= mid)
        return findMaxSubarray(st, ss, mid, qs, qe, 2*si+1);
    if (qs > mid)
        return findMaxSubarray(st, mid+1, se, qs, qe, 2*si+2);
    Node l = findMaxSubarray(st, ss, mid, qs, mid, 2*si+1);
    Node r = findMaxSubarray(st, mid+1, se, mid+1, qe, 2*si+2);
    return combine(l, r);
}

Node buildST(const vector<int>& arr, int ss, int se, Node *st, int si)
{
    if (ss == se)
    {
        st[si] = (Node) {arr[ss], arr[ss], arr[ss], arr[ss]};
        return st[si];
    }
    int mid = (ss+se)/2;
    Node l = buildST(arr, ss, mid, st, 2*si+1);
    Node r = buildST(arr, mid+1, se, st, 2*si+2);
    st[si] = combine(l, r);
    return st[si];
}

int main()
{
    int n, x, m;
    scanf("%d", &n);
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        arr.push_back(x);
    }
    buildST(arr, 0, n-1, st, 0);
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        printf("%d\n", findMaxSubarray(st, 0, n-1, xi-1, yi-1, 0).anymax);
    }
    return 0;
}
