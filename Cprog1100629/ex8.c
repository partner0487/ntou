#include <stdio.h>
#include <math.h>
int main()
{
    int y, m, d;
    int nm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ndc;
    scanf("%d %d %d", &y, &m, &d);
    for (int i = 1; i < y && y != 1; i++)
    {
        if (((y - i) % 4 == 0) && ((y - i) % 100 != 0) || ((y - i) % 400 == 0))
        {
            ndc += 366;
        }
        else
        {
            ndc += 365;
        }
    }
    for (int i = 0; i < m-1; i++)
    {
        if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
        {
            nm[1] = 29;
        }
        ndc += nm[i];
    }
    ndc += d;
    int k;
    k = ndc % 7;
    if (ndc % 7 == 0)
    {
        k = 7;
    }
    printf("%d\n", k);
}