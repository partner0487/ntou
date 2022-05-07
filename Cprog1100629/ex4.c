#include <stdio.h>
int main(){
    int n,max=0,a;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a);
        if (a>max){
            max=a;
        }
    }
    printf("%d\n",max);
}