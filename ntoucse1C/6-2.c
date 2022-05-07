#include "stdio.h"

unsigned long long int arr[70][70]={0};
unsigned long long int c(int n,int k){
    if(arr[n][k]!=0) return arr[n][k];
    arr[n][k]=c(n-1,k)+c(n-1,k-1);
    return arr[n][k];

}
int main(){
    unsigned long long int n,k,u=1,d=1;
    for(int i=0;i<70;i++){
        arr[i][0]=1;
        arr[i][1]=i;
        arr[i][i]=1;
    }
    while(scanf("%d %d",&n,&k)==2){
        if(k>n){
            printf("error\n");
            continue;
        }
        printf("%llu\n", c(n,k));
    }

}
