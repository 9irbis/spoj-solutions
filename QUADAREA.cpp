#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t; 
    double a, b, c, d;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        double s = (a+b+c+d)/2;
        double area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
        printf("%.2f\n", area);
    }
    return 0;
}
