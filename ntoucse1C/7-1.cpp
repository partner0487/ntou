#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n)==1){
        int arr[200], sum[20000]={0};
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum[k]=arr[i]+arr[j];
                k++;
            }
        }
        // printf("%d\n", k);
        int tmp;
        for(int i=k-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(sum[j]>sum[j+1]){  
                    tmp=sum[j];  
                    sum[j]=sum[j+1];  
                    sum[j+1]=tmp;
                }
            }
        }
        int ans;
        for(int i=0;i<k;i++){
            if(sum[i]==sum[i+1]){
                ans=0;
                break;
            }
            else{
                ans=1;
            }
        }
        if(ans==0){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
}