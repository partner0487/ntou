#include <stdio.h>
int main()
{
    int q, a, n, data[100], tmp, ncount, nch;
    scanf("%d", &q);
    for (a = 0; a < q; a++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data[i]);
        }
        ncount = 0;
        nch = 0;
        int ncheck = 1;
        for (int i = 0; i < n - 1 && ncheck > 0; i++)
        {
            ncheck = 0;
            for (int j = n - 2; j >= i; j--)
            {
                ncount++;
                if (data[j] > data[j + 1])
                {
                    nch++;
                    ncheck++;
                    tmp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = tmp;
                    for (int k = 0; k < n - 1; k++)
                    {
                        printf("%d ", data[k]);
                    }
                    printf("%d\n", data[n - 1]);
                }
            }
        }
        printf("%d %d\n", ncount, nch);
    }
}
