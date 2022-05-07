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

void ans(int digit[], int &numdigit, int cap, int num[], int &n){
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
    if(i > cap){
        cout << "Over Flow!" << endl;
        return;
    }
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
    digit = (int *)malloc(size * sizeof(int));
    cap = size, numdigit = 0;

    int temp = v, sz = 0;
    while(temp){
        temp /= 10;
        sz++;
    }
    if(sz > size){
        cout << "Over Flow!" << endl;
        return;
    }
    zero();
    numdigit = sz; int n = 0;
    while(v){
        digit[n] = v % 10;
        v /= 10; n++;
    }
}
bigint::bigint(const char * const s, const int size = 100){
    digit = (int *) malloc(size * sizeof(int));
    cap = size, numdigit = 0;
    
    int sz = strlen(s);
    if(sz > size){
        cout << "Over Flow!" << endl;
        return;
    }

    zero();
    numdigit = sz;
    for(int i = 0, k = sz - 1; i < sz; i++, k--){
        if(s[i] < '0' || s[i] > '9') break;
        digit[k] = s[i] - 48;
    }
}
bigint::bigint(const bigint &x){
    cap = x.cap; numdigit = x.numdigit;
    digit = (int *)malloc(cap * sizeof(digit));
    for(int i = 0; i < cap; i++) digit[i] = x.digit[i];
}

void bigint::zero(){
    memset(digit, 0, sizeof(digit));
    numdigit = 0;
}
void bigint::add(bigint &x){
    ans(digit, numdigit, cap, x.digit, x.numdigit);
}
void bigint::add(int v){
    int num[100], n = 0;
    while(v){
        num[n] = v % 10;
        v /= 10; n++;
    }
    ans(digit, numdigit, cap, num, n);
}
void bigint::add(const char * const s){
    int num[100], n, sz = strlen(s);
    for(n = 0; s[n]; n++) num[n] = s[sz - n - 1] - 48;
    ans(digit, numdigit, cap, num, n);
}
void bigint::printvalue(){
    while(digit[numdigit - 1] == 0) numdigit--;
    if(!numdigit) cout << 0;
    else
        for(int i = numdigit - 1; i >= 0; i--) cout << digit[i];
    cout << endl;
    return;
}

int main(){
    bigint x, y("1234"), z("000009876054321");
	x.printvalue();
	y.printvalue();
	z.printvalue();
    y.add(z);
    y.printvalue();
	bigint i(444, 2);
	i.printvalue();
	bigint j(i);
	j.printvalue();
	i.add(78);
	i.printvalue();
	i.add("98765");
	i.printvalue();
	i.add(j);
	i.printvalue();
}