#include <stdio.h>
int main(){
    int l,w,s;
    scanf("%d %d",&l,&w);
    scanf("%d",&s);
    int k,h;
    k=l/s;
    h=w/s;
    printf("%d\n",k*h);
}