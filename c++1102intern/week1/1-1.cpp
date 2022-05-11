#include "iostream"

void funwhile(int n, int h){
    int cnt = 0;
    while(h--){
        int f = 1;
        while(f <= n){
            printf("*");
            ++f; ++cnt;
        }
        printf("\n");
        n++;
    }
    printf("*總個數有%d個", cnt);
}

int main(){
    int n, h;
    printf("輸入第一行的個數:");
    scanf("%d", &n);
    printf("輸入梯形的高度:");
    scanf("%d", &h);
    funwhile(n, h);
}