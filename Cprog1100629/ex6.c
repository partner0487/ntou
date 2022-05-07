#include <stdio.h>
int main(){
    int n,c[200]={0},h;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&h);
        c[h]+=1;
    }
    
    int max=0,maxh;
    for (int i=0;i<200;i++){
        if (c[i]>max){
            max=c[i];
            maxh=i;
        }
    }
    printf("%d %d\n",maxh,max);
}