#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInt{
private:
    vector<int> v;
public:
    BigInt(string s = "")
    {
        for(auto i=s.rbegin(); i!=s.rend(); i++)
            v.push_back((*i)-48);
    }

    BigInt(const BigInt& b2)
    {
        for(int i=0; i<b2.v.size(); i++)
            v.push_back(b2.v[i]);
    }

    void print()
    {
        for(auto i=v.rbegin(); i!=v.rend(); i++)
            printf("%d", *i);
        printf("\n");
    }

    BigInt operator+(BigInt& b2)
    {
        BigInt b;
        if (v.size() >= b2.v.size())
        {
            int carry = 0, i = 0;
            while( i<b2.v.size())
            {
                int dig = carry + v[i] + b2.v[i];
                b.v.push_back(dig%10);
                carry = dig/10;
                i++;
            }
            while(i<v.size())
            {
                int dig = carry + v[i];
                b.v.push_back(dig%10);
                carry = dig/10;
                i++;
            }
            if (carry)
                b.v.push_back(carry);
            return b;
        }
        else
        {
            int carry = 0, i = 0;
            while( i<v.size())
            {
                int dig = carry + v[i] + b2.v[i];
                b.v.push_back(dig%10);
                carry = dig/10;
                i++;
            }
            while(i<b2.v.size())
            {
                int dig = carry + b2.v[i];
                b.v.push_back(dig%10);
                carry = dig/10;
                i++;
            }
            if (carry)
                b.v.push_back(carry);
            return b;

        }
    }

    BigInt operator-(BigInt& b2)
    {
        BigInt b;
        int i=0, carry=0;
        while(i<b2.v.size())
        {
            int dig = v[i];
            if (carry)
            {
                carry = 0;
                dig = dig - 1;  
            }
            if(dig < b2.v[i])
            {
                dig += 10;
                carry = 1;
            }
            b.v.push_back(dig - b2.v[i]); 
            i++;
        }

        while (i < v.size())
        {
            int dig = v[i];
            if (carry)
            {
                if (dig < carry)
                {
                    dig += 10;
                    b.v.push_back(dig-carry);
                    carry = 1;
                }
                else
                {
                    b.v.push_back(dig-carry);
                    carry = 0;
                }
            }
            else
            {
                b.v.push_back(dig);
            }
            i++;
        }
        int k = b.v.size()-1;
        while(k>0 && b.v[k] == 0)
        {
            b.v.pop_back();
            k--;
        }
        return b;
    }

    void divideByTwo()
    {
        int i=v.size()-1;
        vector<int> ans;
        bool remainderOne = false;
        while(i>=0)
        {
            if (v[i] == 0)
            {
                ans.push_back(0);
                i--;
            }
            else if (v[i] >= 2)
            {
                ans.push_back(v[i]/2);
                v[i] = v[i]%2;
                if (v[i] == 0)
                    i--;
                else
                    remainderOne = true;
            }
            else if (v[i] == 1 && remainderOne == false)
            {
                ans.push_back(0);
                remainderOne = true;
            }
            else if (v[i] == 1 && remainderOne == true)
            {
                int dividend = v[i]*10 + v[i-1];
                ans.push_back(dividend/2);
                if (dividend%2 == 0)
                {
                    v[i] = v[i-1] = 0;
                    i -= 2;
                    remainderOne = false;
                }
                else
                {
                    v[i] = 0;
                    v[i-1] = 1;
                    i--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        int k = ans.size()-1;
        while (ans[k] == 0 && k>0)
        {
            ans.pop_back();
            k--;
        }
        v = ans;
    }

    bool isEven()
    {
        if (v[0] % 2 == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    int tc = 10;
    string total, diff;
    while (tc--)
    {
        cin >> total >> diff;
        BigInt t(total);
        BigInt d(diff);
        BigInt o("1");
        if (t.isEven())
        {
            t.divideByTwo();
            d.divideByTwo();
            BigInt klaudia = t+d;
            BigInt natalia = t-d;
            klaudia.print();
            natalia.print();
        }
        else
        {
            t = t-o;
            d = d-o;
            t.divideByTwo();
            d.divideByTwo();
            BigInt klaudia = t+o+d;
            BigInt natalia = t-d;
            klaudia.print();
            natalia.print();
        }
    }
    return 0;
}
