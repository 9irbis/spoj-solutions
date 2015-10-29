#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

const int INPUTS[7] = {137, 1315, 73, 136, 255, 1384, 16385};
FILE * pFile = fopen("easy_prob_output.txt", "w");

void expand(int n)
{
    if (n <= 3)
    {
        if (n == 1) fprintf(pFile, "2(0)");
        else if (n == 2) fprintf(pFile, "2");
        else if (n == 3) fprintf(pFile, "2+2(0)");
        return;
    }
    int temp = n, count = 0;
    while (temp)
    {
        count++;
        temp /= 2;
    }
    int a = pow(2, count-1);
    fprintf(pFile, "2(");
    expand(count-1);
    fprintf(pFile, ")");
    if (n-a != 0)
    {
        fprintf(pFile, "+");
        expand(n-a);
    }
}

int main()
{
    for(int i=0; i<7; i++)
    {
        fprintf(pFile, "%d=", INPUTS[i]);
        expand(INPUTS[i]);
        fprintf(pFile, "\n");
    }
    fclose(pFile);
    return 0;
}
