#include "iostream"
using namespace std;

int fib[10000];

int FIB(int n){
    if(n < 2) return n;
    if(fib[n]) return fib[n];
    return fib[n] = FIB(n - 1) + FIB(n - 2);
}

int main(){
    int n; cin >> n;
    cout << FIB(n + 1) << endl;
}