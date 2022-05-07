#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main(){
    int n, a, b, c, d, sum, sum1;
    scanf("%d", &n);
    srand(n);
    int ncount;
    scanf("%d", &ncount);
    int occur[11] = {0}, occur1[11] = {0};
    for (int i=0;i<ncount;i++){
        a=rand()%6+1;
        b=rand()%6+1;
        sum=a+b;
        occur[sum-2]+=1;
        
    }
    printf("方法一\n");
    for (int i=0;i<11;i++){
        printf("%d 出現過 %d 次\n", i+2, occur[i]);
    }
    for (int i=0;i<ncount;i++){
        c=(int)((double)rand()/(RAND_MAX+1.0)*6.0) + 1;
        d=(int)((double)rand()/(RAND_MAX+1.0)*6.0) + 1;
        sum1=c+d;
        occur1[sum1-2]+=1;
    }
    printf("方法二\n");
    for (int i=0;i<11;i++){
        printf("%d 出現過 %d 次\n", i+2, occur1[i]);
    }
}