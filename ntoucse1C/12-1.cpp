#include<stdio.h>
#include<stdbool.h>
#define xiaoyox
#define ll long long

int a[10] = {}, total = 0;
ll ans[10] = {};

bool isValid(int now, int n, int div){

    if(now == 0 && a[now] == 0){
        return false;
    }
    for(int i = 0; i < now; i++){
        if(a[i] == a[now]){
            return false;
        }
    }

    ll x=1;
    int t = n - now - 1;

    while(t--){
        x *= 10;
    }
    if((a[now] * x) % div != 0){
        return false;
    }
    return true;
}

void to_ans(int n){
    ll x = 0;
    for(int i = 0; i < n; i++){
        x = x * 10 + a[i];
    }
    ans[total] = x;
}

void put(int now, int n, int div)
{
    if(now == n){
        if(total < 10){
            to_ans(n);
        }
        total++;
        
        return;
    }
    for(int i = 0; i <= 9; i++){
        // printf("%d\n", now);
        a[now] = i;
        if(isValid(now, n, div)){
            put(now + 1, n, div);
        }
    }
}
int main(){
    #ifdef xiaoyo
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        a[i] = -9;
    }

    put(0, n, m);
    //*
    printf("number of solutions=%d\n", total);
    for(int i = 0; i < total && i < 10; i++){
        printf("%lld\n", ans[i]);
    }//*/
}
/*
6 4
*/