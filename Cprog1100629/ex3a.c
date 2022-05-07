#include <math.h>
#include <stdio.h>
int main()
{
    double a, b, c, x1, x2, k, d;

    scanf("%lf %lf %lf", &a, &b, &c);

    d = b * b - 4 * a * c;
    k = sqrt(d);
    if (d < 0)
    {
        printf("沒有實根\n");
    }
    else if ((int)a == 0)
    {
        printf("不是拋物線\n");
    }
    else
    {
        x1 = (-b + k) / (2 * a);
        x2 = (-b - k) / (2 * a);
        printf("%.3f, %.3f\n", x1, x2);
    }
    
}