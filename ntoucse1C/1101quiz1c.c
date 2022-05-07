#include <stdio.h>  
  
int main(){  
    int num, n, arr[200], tmp;  
    scanf("%d", &num);  
    while(num--){  
        scanf("%d", &n);  
        for(int i=0;i<n;i++){  
            scanf("%d", &arr[i]);  
        }  
        for(int i=n-1;i>0;i--){  
            for(int j=0;j<i;j++){  
                if(arr[j]>arr[j+1]){  
                    tmp=arr[j];  
                    arr[j]=arr[j+1];  
                    arr[j+1]=tmp;  
                } 
            }  
        }  
        for(int i=0;i<n;i++){  
            printf("%d", arr[i]);  
            if(i!=n-1) printf(" ");  
        }  
        printf("\n");  
    }  
}