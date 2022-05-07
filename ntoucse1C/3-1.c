#include "stdio.h"
int main()
{
    int n, h, t, o;
    scanf("%d", &n);
    //for (int i = 0; i < 1000; i++)
    //{
    h = n / 100, t = (n % 100) / 10, o = n % 10;
    const char *arr[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
    if (n == 0)
        printf("%s", arr[0]);
    if (h > 0)
    {
        if (h == 2)
            printf("兩百");
        else
            printf("%s百", arr[h]);
        if (t == 0 && o > 0)
            printf("零");
        if (t > 0)
            printf("%s十", arr[t]);
        if (o > 0)
            printf("%s", arr[o]);
        printf("\n");
    }
    if (h == 0)
    {
        if (t == 1)
            printf("十");
        if (t > 0 && t != 1)
            printf("%s十", arr[t]);
        if (o > 0)
            printf("%s", arr[o]);
        printf("\n");
    }
    //}
}