#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int n,arr[30]={};
    while (cin>>n){
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        bool ans=0;
        for (int i=n-1;i>=2;i--){
            for (int j=i-1;j>=1;j--){
                for (int l=j-1;l>=0;l--){
                    if (arr[i]<arr[j]+arr[l]){
                        cout<<arr[l]<<" "<<arr[j]<<" "<<arr[i]<<endl;
                        ans=1;
                        break;
                    }
                }
                if (ans) break;
            }
            if (ans) break;
        }
        if (!ans) cout<<"-1"<<endl;
    }
    
}