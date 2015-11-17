#include <iostream>
#include <string>
using namespace std;

enum Language {CPP, JAVA};

bool isUpper(char c)
{
    return (c >= 65 && c <= 90);
}

bool isLower(char c)
{
    return (c >= 97 && c <= 122);
}

bool isValid(string& id)
{
    if (id[0] == '_' || id[id.size()-1] == '_' || isUpper(id[0]))
        return false;
    int i = 1;
    while (isLower(id[i]))
        i++;
    if (i == id.size())
        return true;
    Language lang = (id[i] == '_' ? CPP : JAVA);
    i = 1;
    if (lang == CPP)
    {
        while (i < id.size())
        {
            if (isLower(id[i]))
                i++;
            else if (id[i] == '_')
            {
                if (!isLower(id[i+1]))
                    return false;
                else
                {
                    id.replace(i, 2, string(1, id[i+1]-32));
                    i++;
                }
            }
            else
                return false;
        }
        return true;
    }
    else
    {
        while (i < id.size())
        {
            if (isLower(id[i]))
                i++;
            else if (isUpper(id[i]))
            {
                id[i] += 32;
                id.insert(i, string(1, '_'));
                i += 2;
            }
            else
                return false;
        }
        return true;
    }
}

int main()
{
    string id;
    while (cin >> id)
    {
        if (isValid(id))
            cout << id << "\n";
        else
            cout << "Error!\n";
    }
    return 0;
}
