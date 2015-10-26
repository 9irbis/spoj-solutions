#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> BigInt;

BigInt getbigInt(string& s)
{
    BigInt ans;
    for(int i=s.size()-1; i>=0; i--)
        ans.push_back(s[i]-'0');
    return ans;
}

BigInt getbigInt(int i)
{
    BigInt ans;
    while (i)
    {
        ans.push_back(i%10);
        i /= 10;
    }
    return ans;
}

void removeZeros(BigInt& b)
{
    while(b.size() > 1 && b.back() == 0)
        b.pop_back();
}

void print(BigInt& b)
{
    removeZeros(b);
    if (b.size() == 0)
        cout << 0 << endl;
    else
    {
        for(int i=b.size()-1; i>=0; i--)
            cout << b[i];
        cout << endl;
    }
}

BigInt operator+(const BigInt& b1, const BigInt& b2)
{
    BigInt ans;
    int carry = 0;
    for(int i=0; i<=max(b1.size(), b2.size())-1; i++)
    {
        if (i<b1.size()) carry += b1[i];
        if (i<b2.size()) carry += b2[i];
        ans.push_back(carry%10);
        carry = carry/10;
    }
    if (carry)
        ans.push_back(carry);
    return ans;
}

BigInt operator-(const BigInt& b1, const BigInt& b2)
{
    BigInt ans;
    int carry = 0;
    for(int i=0; i<b1.size(); i++)
    {
        carry += b1[i] - (i < b2.size() ? b2[i] : 0);
        if (carry < 0)
        {
            ans.push_back(carry+10);
            carry = -1;
        }
        else
        {
            ans.push_back(carry);
            carry = 0;
        }
    }
    return ans;
}

BigInt operator-(const BigInt& b1, int i)
{
    return b1 - getbigInt(i);
}

int main()
{
    string N;
    while (cin >> N)
    {
        if (N == "1")
            cout << 1 << endl;
        else
        {
            BigInt b = getbigInt(N);
            b = b+b;
            b = b-2;
            print(b);
        }
    }
    return 0;
}
