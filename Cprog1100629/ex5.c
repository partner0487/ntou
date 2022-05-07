#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<i+3&&j<n;j++){
            if ('A'+i+j<'A'+n){
                printf("%c",'A'+j+i);
            }
            else{
                printf("%c",'A'+(i+j)%n);
            }
            
        }
        printf("\n");
    }
}