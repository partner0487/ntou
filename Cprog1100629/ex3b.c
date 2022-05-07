#include <math.h>
#include <stdio.h>
int main()
{
    int i, n;
    scanf("%d", &n);
    double a[n], b[n], c[n];
    double x1[n], x2[n], d[n], k[n];

    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf", &a[i], &b[i], &c[i]);
        d[i] = b[i] * b[i] - 4 * a[i] * c[i];
        k[i] = sqrt(d[i]);
        
    }
    for (int i = 0;i<n;i++){
        if (d[i] < 0)
        {
            printf("沒有實根\n");
        }
        else if ((int)a[i] == 0)
        {
            printf("不是拋物線\n");
        }
        else
        {
            x1[i] = (-b[i] + k[i]) / (2 * a[i]);
            x2[i] = (-b[i] - k[i]) / (2 * a[i]);
            printf("%.3f, %.3f\n", x1[i], x2[i]);
        }
        
    }
}