#include <iostream>
using namespace std;

int main()
{
    int L;
    scanf("%d", &L);
    while (L)
    {
        double PI = 3.1415926;
        double area = (L*L)/(2*PI);
        printf("%.2f\n", area);
        scanf("%d", &L);
    }
    return 0;
}   
