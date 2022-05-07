#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
int main()
{
    int n, str;
    scanf("%d", &n);
    while (n--)
    {
        int arr[100] = {0};
        int sum = 0, ans = INT_MAX;
        scanf("%d", &str);
        for (int i = 0; i < str; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < 100; i++)
        {
            sum=0;
            for (int j = 0; j < 100; j++)
            {
                if(arr[j]!=0)
                    sum += abs(i - arr[j]);
            }
            if (ans > sum)
                ans = sum;
        }
        printf("%d\n", ans);
    }
}