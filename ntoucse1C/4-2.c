#include "stdio.h"
#include "math.h"
int main()
{
    double a, b, c, d, ep, x1, x2;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    scanf("%lf", &ep);
    scanf("%lf %lf", &x1, &x2);
    double x3 = (x1 + x2) / 2;
    double f1 = a * x1 * x1 + b * x1 + c - cos(d * x1), f3 = a * x3 * x3 + b * x3 + c - cos(d * x3);
    while (!((f3 == 0) || abs(x2 - x1) < ep))
    {
        if (f1 * f3 < 0)
            x2 = x3;
        else
            x1 = x3;
        x3 = (x1 + x2) / 2;
        f1 = a * x1 * x1 + b * x1 + c - cos(d * x1), f3 = a * x3 * x3 + b * x3 + c - cos(d * x3);
    }
    printf("%.5lf\n", x3);
}