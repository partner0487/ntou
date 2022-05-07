#include <stdio.h>

int main(){
    int arr[2][3][5][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<5;k++){
                scanf("%d, %d, %d", &arr[i][j][k][0], &arr[i][j][k][1], &arr[i][j][k][2]);
            }
        }
    }

    for(int j=0;j<2;j++){
        for(int k=0;k<3;k++){
            float sum=0;
            float average;
            for(int a=0;a<5;a++){
                sum+=arr[j][k][a][0];
            }
            average=sum/5;
            printf("%d年%d班學生國文成績平均為 %.2f\n", j+1, k+1, average);
        }
    }
    for(int j=0;j<2;j++){
        for(int k=0;k<3;k++){
            float sum=0;
            float average;
            for(int a=0;a<5;a++){
                sum+=arr[j][k][a][1];
            }
            average=sum/5;
            printf("%d年%d班學生英文成績平均為 %.2f\n", j+1, k+1, average);
        }
    }
    for(int j=0;j<2;j++){
        for(int k=0;k<3;k++){
            float sum=0;
            float average;
            for(int a=0;a<5;a++){
                sum+=arr[j][k][a][2];
            }
            average=sum/5;
            printf("%d年%d班學生數學成績平均為 %.2f\n", j+1, k+1, average);
        }
    }
}