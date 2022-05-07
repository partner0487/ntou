#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int cpr(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

ull check(int n, int arr[], ull v){
    ull total = 0, ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
        cnt++;
        if(total == v){
            ans++;
            total = 0;
            cnt = 0;
        }
        else if(total > v){
            if(cnt == 1) return 999999;
            ans++;
            total = 0;
            cnt = 0;
            i--;
        }
        else if(total < v && i == n - 1){
            ans++;
        }
    }
    return ans;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        int arr[1005], arr1[1005];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            arr1[i] = arr[i];
        }
        qsort(arr1, n, 4, cpr);
        
        if(check(n, arr, arr1[n - 1]) <= m){
            cout << arr[n - 1] << endl;
        }
        
        else{
            ull sum[1005] = {};
            sum[0] = arr1[0];
            for(int i = 1; i < n; i++){
                sum[i] = arr1[i] + sum[i - 1];
            }

            int high = n - 1, low = 0, mid;
            ull ans;
            // cout << check(n, arr, sum[2]) << endl;
            //*
            while(low <= high){
                mid = (low + high) / 2;
                ans = check(n, arr, sum[mid]);
                if(ans == m) break;
                if(ans > m){
                    low = mid + 1;
                }
                else if(ans < m){
                    high = mid - 1;
                }
            }

            if(check(n, arr, sum[mid]) > m){   
                for(ull i = sum[mid]; i <= sum[n - 1]; i++){   
                    ans = check(n, arr, i);   
                    if(ans == m){   
                        printf("%llu\n", i);
                        break;   
                    }   
                }   
            }
            else{
                for(ull i = arr1[n - 1]; i <= sum[mid]; i++){
                    ans = check(n, arr, i);
                    if(ans == m){
                        cout << i << endl;
                        break;
                    }
                }
            }
        }
    }
}