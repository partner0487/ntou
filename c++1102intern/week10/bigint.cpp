/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 15
//*/
#include "iostream"
#include "bigint.h"
#include "malloc.h"
#include "string.h"
#include "algorithm"
using namespace std;

void ans(char digit[], int &numdigit, int cap, int &sign1, char num[], int &n, int &sign2) {
	int *ans;
    ans = new int[max(numdigit, n) + 10];
	for (int i = 0; i < max(numdigit, n) + 10; i++) ans[i] = 0;

    if(sign1 == sign2){
	    int carry = 0, i = 0;
	    for (; i < numdigit && i < n; ++i) {
	    	ans[i] = (digit[i] + num[i] + carry) - 96;
	    	ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
	    }
	    while (i < numdigit) {
	    	ans[i] = (digit[i] + carry) - 48;
	    	ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
	    	++i;
	    }
	    while (i < n) {
	    	ans[i] = (num[i] + carry) - 48;
	    	ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
	    	++i;
	    }
	    if (carry) ans[i++] += 1;
	    numdigit = i;
	    for (int j = 0; j < i; j++) digit[j] = ans[j] + 48;
    }
    else{
        char *num1, *num2;
        num1 = new char[max(cap, n)]; num2 = new char[max(cap, n)];
        while(digit[numdigit - 1] == '0') numdigit--;
        while(num[n - 1] == '0') n--;

        for(int i = 0; i < numdigit; i++) num1[i] = digit[i];
        for(int i = 0; i < n; i++) num2[i] = num[i];
        
        if(numdigit < n){
            swap(num1, num2);
            swap(numdigit, n);
            swap(sign1, sign2);
        }
        else if(numdigit == n){
            for(int i = numdigit - 1; i >= 0; i--){
                if(num1[i] < num2[i]){
                    swap(num1, num2);
                    swap(sign1, sign2);
                    break;
                }
            }
        }
        sign1 = sign1 < 0 ? -1 : 1;
        int i = 0, borrow = 0;
        for(; i < n; i++){
            ans[i] = num1[i] - num2[i] - borrow;
            ans[i] < 0 ? ans[i] += 10, borrow = 1 : borrow = 0;
        }
        while(borrow){
            ans[i] = num1[i] - borrow - 48;
            ans[i] < 0 ? ans[i] += 10, borrow = 1 : borrow = 0;
            i++;
        }
        while(i < numdigit){
            ans[i] = num1[i] - '0';
            i++;
        }
        for(int j = 0; j < i; j++){
            digit[j] = ans[j] + 48;
        }
    }
}

bigint::bigint(){
    cap = 100;
    digit = new char[cap];
    zero();
}
bigint::bigint(int v, int size = 100){
    digit = 0; cap = numdigit = 0;

    int temp = v, sz = 0;
    while(temp){
        temp /= 10;
        sz++;
    }
    if(sz > size) size = sz;
    cap = size;
    digit = new char[cap];
    zero();

    v < 0 ? sign = -1, v = -v : sign = 1;

    numdigit = sz; int n = 0;
    while(v){
        digit[n] = v % 10 + 48;
        v /= 10; n++;
    }
}
bigint::bigint(const char * const s, int size = 100){
    digit = 0; cap = numdigit = 0;

    int sz = strlen(s), i;
    sz = s[0] == '-' ? sz - 1 : sz;
    sz = s[0] == '+' ? sz - 1 : sz;
    if(sz > size) size = sz;
    cap = size;
    digit = new char[cap];
    zero();

    if(s[0] == '+' || s[0] == '-')
        i = 1, sign = (s[0] == '+' ? 1 : -1);
    else i = 0;

    numdigit = sz;
    for(int k = sz - 1; i <= sz; i++, k--){
        if(s[i] < '0' || s[i] > '9') continue;
        digit[k] = s[i];
    }
}
bigint::bigint(bigint &x){
    cap = x.cap; numdigit = x.numdigit; sign = x.sign;
    digit = new char[cap];
    for(int i = 0; i < cap; i++) digit[i] = x.digit[i];
}
bigint::~bigint(){
    if(cap){
        if(cap == 1) delete digit;
        else         delete[] digit;
    }
}
bigint::bigint(char *n, int x, int y, int z){
    numdigit = x, cap = y, sign = z;
    digit = new char[cap];
    for(int i = 0; i < numdigit; i++) digit[i] = n[i];
}

void bigint::zero(){
    if(cap){
        numdigit = 1;
        digit[0] = '0';
        sign = 1;
    }
}
void bigint::printvalue(){
    while(digit[numdigit - 1] == '0') numdigit--;
    if(!numdigit) cout << 0;
    else{
        cout << (sign == -1 ? "-" : "");
        for(int i = numdigit - 1; i >= 0; i--) cout << digit[i];
    }
    return;
}
void bigint::update(int v){
    sign = v < 0 ? -1 : 1;
    v = abs(v);
    int n = 0;
    while(v){
        digit[n] = v % 10 + 48;
        v /= 10; n++;
    }
    numdigit = n;
}
void bigint::update(bigint x){
    cap = x.cap; numdigit = x.numdigit; sign = x.sign;
    digit = new char[cap];
    for(int i = 0; i < cap; i++) digit[i] = x.digit[i];
}

ostream &operator << (ostream &io, bigint &x){
    x.printvalue();
    return io;
}
bigint bigint::operator = (int v){
    update(v);
    return bigint(digit, numdigit, cap, sign);
}
bigint bigint::operator = (bigint x){
    update(x);
    return bigint(digit, numdigit, cap, sign);
}
bigint bigint::operator += (bigint x){
    ans(digit, numdigit, cap, sign, x.digit, x.numdigit, x.sign);
    return bigint(digit, numdigit, cap, sign);
}
bigint bigint::operator += (int x){
    bigint a(x);
    ans(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
    return bigint(digit, numdigit, cap, sign);
}
bigint bigint::operator + (bigint x){
    ans(digit, numdigit, cap, sign, x.digit, numdigit, x.sign);
    return bigint(digit, numdigit, cap, sign);
}
bigint bigint::operator + (int x){
    bigint a(x);
    ans(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
    return bigint(digit, numdigit, cap, sign);
}
bigint bigint::operator ++ (){
    bigint a(1);
    ans(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
    return bigint(digit, numdigit, cap, sign);
}
bigint bigint::operator ++ (int x){
    bigint a(*this);
    bigint b(1);
    ans(digit, numdigit, cap, sign, b.digit, b.numdigit, b.sign);
    return a;
}

int main(){
    bigint x, y("-1234"), z("+00000987654321");
    
    bigint a = -1234;
    bigint b = 456;

    a += b; cout << a << endl;
	
	cout << x << " " << y << " " << z << endl;

    x = y;
    z = y;
	cout << x << ' ' << y << ' ' << z << endl;

	x = -123, y = -123; z = 123;
	cout << x << ' ' << y << ' ' << z << endl;

	x = 123; y = -123; z = -99;
	x += z; y += z;
	cout << x << ' ' << y << ' ' << z << endl;

	x = 123; y = -123; z = 99;
	x += z; y += z;
	cout << x << ' ' << y << ' ' << z << endl;

	x = 99;
	y = ++x; z = x++;
	cout << x << ' ' << y << ' ' << z << endl;  //101 100 100
    
    x = -99;
    y = ++x; z = x++;
    cout << x << " " << y << " " << z << endl;

	x = -100;
	y = ++x; z = x++;
	cout << x << ' ' << y << ' ' << z << endl;	//-98 -99 -99
}