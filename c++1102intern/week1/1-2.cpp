#include "iostream"

void funFor(int n, int h){
    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int f = 0; f < n; f++){
            printf("*");
            ++cnt;
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
    funFor(n, h);
}