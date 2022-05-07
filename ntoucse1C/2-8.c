#include "stdio.h"
#include "math.h"
#include "cmath"
int main()
{
    long long int s, ans;
    while (scanf("%lld", &s))
    {
        if (s == 0)
            break;
        double n = ceil((-1 + sqrt(1 + 8 * s)) / 2);
        //if (!((n * n - n) / 2 <= s) && !(s < (n * n + n) / 2))
        //    n = n + 1;
        ans = (n * n + n) / 2;
        if(ans-s<1){
            n=n+1;
            ans = (n * n + n) / 2;
        }
        printf("%lld %.0f\n", ans - s, n);
    }
}