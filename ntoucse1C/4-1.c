#include "stdio.h"
void nextc(int *x, int *y, int dir)
{
    switch (dir)
    {
    case 0:
        *y = *y + 1;
        break;
    case 1:
        *x = *x - 1;
        break;
    case 2:
        *y = *y - 1;
        break;
    case 3:
        *x = *x + 1;
        break;
    }
}
int main()
{
    /*y=(t-1)/5+1
    x=(t-1)%5+1 */
    int n, s, ta;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &s, &ta);
        int count = 0, plc = 2, step = 0, dir = 0, x, y;
        x = y = s / 2 + 1;
        //printf("%d %d\n",x,y);
        while (++count < ta)
        {
            nextc(&x, &y, dir);
            if (++step == plc / 2)
            {
                dir = (dir + 1) % 4;
                plc++, step = 0;
            }
        }
        printf("(%d,%d)\n", x, y);
    }
}
