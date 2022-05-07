#include <iostream>
using namespace std;

void funFor2(int f, int h, int d){
    int cnt = 0;
    for(int i = 0; i < h; i++){
        if(i <= h / 2){
            for(int j = 0; j < d * ((h / 2 + 1) - 1 - i); j++) printf(" ");
            for(int j = 0; j < f + d * 2 * i; j++){
                printf("*");
                cnt++;
            }
        }
        else{
            for(int j = (-d) * (i - h / 2); j < 0; j++) printf(" ");
            for(int j = 0; j < (f + d * 2 * (h / 2 - 1)) + (-d) * 2 * (i - h / 2 - 1); j++){
                printf("*");
                cnt++;
            }
        }
        printf("\n");
    }
    printf("*總數目為%d", cnt);
}

int main(){
    int f, h, d;
    printf("\n輸入第一行*的個數:");
    scanf("%d", &f);
    printf("\n輸入菱形的高度(奇數):");
    scanf("%d", &h);
    printf("\n每行的差異(正整數):");
    scanf("%d", &d);
    funFor2(f, h, d);
}