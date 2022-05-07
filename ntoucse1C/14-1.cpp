#include <stdio.h>
#include <string.h>
#define xiaoyox
#define ull unsigned long long

ull c[34][34] = {};
int n1, k1, ncount, nccount;
int cc[34][34] = {};

int ccombinate(int n, int k){
    if(n == n1 && k == k1) ++nccount;
    
    int ans;
    if(cc[n][k]) return cc[n][k];
    ans = ccombinate(n - 1, k - 1) + ccombinate(n - 1, k);
    
    return 0;
}

int combinate(int n, int k){
    
    if(n == n1 && k == k1) ++ncount;

    if(c[n][k]){
        return c[n][k];
    }else{
        c[n][k] = combinate(n - 1, k) + combinate(n - 1, k - 1);
    }
    return c[n][k];
}

int main(){
    #ifdef xiaoyo
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int n, k;
    while(scanf("%d %d %d %d", &n, &k, &n1, &k1) == 4){
        memset(c, 0, sizeof(int) * 34 * 34);
        for(int i = 0; i < 34; i++){
            c[i][0] = c[i][i] = 1;
            cc[i][0] = cc[i][i] = 1;
        }
        nccount = ncount = 0;
        if(n < k){
            printf("error\n");
            continue;
        }else{
            combinate(n, k);
            ccombinate(n, k);
        }
        printf("%llu %d %d\n", c[n][k], ncount, nccount);
    }   
}

/*
10 1 3
32 0 0
237336 2 3654
error
10400600 2 92378
//*/