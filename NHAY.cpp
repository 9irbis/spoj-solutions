#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m;
    string needle, haystack;
    while (cin >> m >> needle >> haystack)
    {
        size_t curr = 0;
        while (true)
        {
            size_t temp = haystack.find(needle, curr);
            if (temp != string::npos)
                cout << temp << "\n";
            else
                break;
            curr = temp+1;
        }
        cout << "\n";
    }
    return 0;
}
