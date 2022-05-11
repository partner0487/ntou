#include "iostream"

void funFor(int n, int h, int d){
    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int j = d * i; j > 0 ; j--) printf(" ");
        for(int j = 0; j < n + 2 * (-d) * i; j++){
            printf("*");
            ++cnt;
        }
        printf("\n");
    }
    printf("*總個數有%d個", cnt);
}

int main(){

    int n, h, d;
    printf("輸入第一行的個數:");
    scanf("%d", &n);
    printf("輸入梯形的高度:");
    scanf("%d", &h);
    printf("每行的差異(正整數):");
    scanf("%d", &d);
    funFor(n, h, d);
}
