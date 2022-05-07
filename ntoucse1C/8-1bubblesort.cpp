#include <stdio.h>

int main()
{
    int count, n, arr[200], tmp;
    int dcount=0, scount=0;
    scanf("%d", &count);
    while (count--)
    {
        dcount=0, scount=0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int check=1;
        for(int i=0;i<n-1 && check>0;i++){
            check=0;
            for(int j=n-2;j>=i;j--){  
                if(arr[j]>arr[j+1]){  
                    scount+=1;
                    tmp=arr[j];  
                    arr[j]=arr[j+1];  
                    arr[j+1]=tmp;  
                    for(int k=0;k<n;k++){
                        printf("%d", arr[k]);
                        if(k!=n-1) printf(" ");
                    }
                    printf("\n");
                    check=1;
                }
                dcount+=1;
            }

        }
        printf("%d %d\n", dcount, scount);
    }
}