#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> operator+(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> ans;
    int mn = min(v1.size(), v2.size());
    int mx = max(v1.size(), v2.size());
    int carry = 0, ind = 0;
    while (ind < mn)
    {
        int s = v1[ind] + v2[ind] + carry;
        ans.push_back(s%10);
        carry = s/10;
        ind++;
    }
    
    if (mn == mx)
    {
        if (carry)
            ans.push_back(carry);
    }
    else if (v1.size() > v2.size())
    {
        while(ind < v1.size())
        {
            int r = v1[ind] + carry;
            ans.push_back(r%10);
            carry = r/10;
            ind++;
        }
        if(carry)
            ans.push_back(carry);
    }
     else
    {
        while(ind < v2.size())
        {
            int r = v2[ind] + carry;
            ans.push_back(r%10);
            carry = r/10;
            ind++;
        }
        if(carry)
            ans.push_back(carry);
    }
    return ans;
}

vector<int> operator*(const vector<int>& v1, const vector<int> v2)
{
    vector<int> a;
    for(int i=0; i<v2.size(); i++)
    {
        int carry = 0;
        vector<int> a2(i);
        for(int j=0; j<v1.size(); j++)
        {
            int x = v1[j] * v2[i] + carry;
            a2.push_back(x%10);
            carry = x/10;
        }
        if (carry)
            a2.push_back(carry);
        a = a + a2;
    }
    return a;
}

void printFact(int n)
{
    vector<int> v1;
    int x = n;
    while(x)
    {
        v1.push_back(x%10);
        x /= 10;
    }
    for(int i=n-1; i>1; i--)
    {
        vector<int> v2;
        int j = i;
        while(j)
        {
            v2.push_back(j%10);
            j /= 10;
        }
        v1 = v1 * v2;
    }
    for(int i=v1.size()-1; i>=0; i--)
        cout << v1[i];
    cout << "\n";
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        printFact(n);
    }
    return 0;
}
