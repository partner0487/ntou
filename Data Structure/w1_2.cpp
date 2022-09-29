#include "stdio.h"

int pri[5000000];

int main(){
    int n;
    scanf("%d", &n);

    int now = 2;
    int temp = n;
    while(temp > 1){
        if(temp % now) now++;
        else{
            pri[now]++;
            temp /= now;
        }
    }
    for(int i = 2, j = 0; i <= n; i++){
        if(pri[i]){
            if(j) printf(" * ");
            printf("%d", i);
            if(pri[i] > 1) printf("^%d", pri[i]);
            j++;
        }
    }
    printf("\n");
}