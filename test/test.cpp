#include "bits/stdc++.h"
using namespace std;

void ans(char *n, int &num, int cap, char *n2, int &num2){
    int ans[100];
    memset(ans, 0, sizeof(ans));
    int carry = 0, i = 0;
    for(; i < num && i < num2; ++i){
        ans[i] = (n[i] + n2[i] + carry) - 96;
        ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
    }
    while(i < num){
        ans[i] = (n[i] + carry) + 48;
        ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
        ++i; 
    }
    while(i < num2){
        ans[i] = (n2[i] + carry) + 48;
        ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
        ++i;
    }
    if(carry) ans[i++] += 1;
    /*
    if(i > cap){
        cout << "Over Flow!" << endl;
        return;
    }//*/
    num = i;
    for(int j = 0; j < i; j++) n[j] = ans[j] + 48;
}

class Int{
    public:
        char n[10];
        int cap, num, sign;
        Int();
        Int(char *, int, int, int);
        void print();
        Int operator + (Int);
};

Int::Int(){
    cap = num = 0; sign = 1;
}

Int::Int(char *x, int y, int z, int w){
    for(int i = 0; i < z; i++) n[i] = x[i];
    cap = y, num = z, sign = w;
}

void Int::print(){
    while(n[num - 1] == 0) num--;
    if(!num) cout << 0;
    else
        for(int i = num - 1; i >= 0; i--) cout << n[i];
    cout << endl;
    return;
}

Int Int::operator+(Int x){
    ans(n, num, cap, x.n, x.num);
    return Int(n, cap, num, sign);
}

int main(){
    Int x;
    for(int i = 0, idx = 4; i < 5; i++, idx--){
        x.n[idx] = i + 49;
    }
    x.cap = 5, x.num = 5, x.sign = 1;

    Int y;
    for(int i = 5, idx = 4; i < 10; i++, idx--){
        y.n[idx] = i + 48;
    }
    y.cap = 5, y.num = 5, y.sign = 1;
    x = x + y;
    x.print();
}
/*
12345
56789
//*/
