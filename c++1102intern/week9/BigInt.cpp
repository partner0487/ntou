/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 07
//*/
#include "iostream"
#include "string.h"
#include "malloc.h"
#include "bigint.h"
#include "string"
using namespace std;

void ans(int digit[], int &numdigit, int num[], int &n){
    int ans[100];
    memset(ans, 0, sizeof(ans));
    int carry = 0, i = 0;
    for(; i < numdigit && i < n; ++i){
        ans[i] = (digit[i] + num[i] + carry);
        ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
    }
    while(i < numdigit){
        ans[i] = (digit[i] + carry);
        ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
        ++i; 
    }
    while(i < n){
        ans[i] = (num[i] + carry);
        ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
        ++i;
    }
    if(carry) ans[i++] += 1;
    numdigit = i;
    for(int j = 0; j < i; j++) digit[j] = ans[j];
}

bigint::~bigint(){
    if(digit) free(digit);
    digit = 0;
    cap = numdigit = 0;
}
bigint::bigint(){
    cap = 100;
    digit = (int *) malloc(cap * sizeof(int));
    zero();
}
bigint::bigint(int v, int size = 100){
    digit = 0; cap = numdigit = 0;

    int temp = v, sz = 0;
    while(temp){
        temp /= 10;
        sz++;
    }
    if(sz > size) return;
    cap = size;
    digit = (int *) malloc(cap * sizeof(int));
    zero();
    numdigit = sz; int n = 0;
    while(v){
        digit[n] = v % 10;
        v /= 10; n++;
    }
}
bigint::bigint(const char * const s, const int size = 100){
    digit = 0;
    cap = numdigit = 0;
    
    int sz = strlen(s);
    if(sz > size) return;

    cap = size;
    digit = (int *) malloc(cap * sizeof(int));
    zero();
    numdigit = sz;
    for(int i = 0, k = sz - 1; i < sz; i++, k--){
        if(s[i] < '0' || s[i] > '9') break;
        digit[k] = s[i] - 48;
    }
}

void bigint::zero(){
    memset(digit, 0, sizeof(digit));
    numdigit = 0;
}

void bigint::add(int v){
    int num[100], n = 0;
    while(v){
        num[n] = v % 10;
        v /= 10; n++;
    }
    ans(digit, numdigit, num, n);
}
void bigint::add(const char * const s){
    int num[100], n, sz = strlen(s);
    for(n = 0; s[n]; n++) num[n] = s[sz - n - 1] - 48;
    ans(digit, numdigit, num, n);
}

void bigint::printvalue(){
    if(!numdigit) cout << 0;
    else
        for(int i = numdigit - 1; i >= 0; i--) cout << digit[i];
    cout << endl;
}

int main(){
    bigint x("99900");
    x.add("100");
    x.printvalue();
    bigint y("99900");
    y.add(100);
    y.printvalue();
    bigint z(99900);
    z.printvalue();
}