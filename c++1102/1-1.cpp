#include <iostream>
using namespace std;

void funFor(int f, int h, int d){
    int cnt = 0;
    printf("在螢幕上秀出如下:\n");
    for(int i = 0; i < h; i++){
        if(d >= 0){
            for(int j = 0; j < d * (h - 1 - i); j++) printf(" ");
            for(int j = 0; j < f + d * 2 * i; j++){
                printf("*");
                cnt++;
            }
            printf("\n");
        }
        else{
            for(int j = d * i; j < 0; j++) printf(" ");
            for(int j = 0; j < f + d * 2 * i; j++){
                printf("*");
                cnt++;
            }
            printf("\n");
        }
    }
    printf("*總數目有%d個", cnt);
}
int main(){
    int f, h, d;
    printf("\n輸入第一行*的個數:");
    scanf("%d", &f);
    printf("\n輸入梯形的高度:");
    scanf("%d", &h);
    printf("\n每行的差異:");
    scanf("%d", &d);
    funFor(f, h, d);
}