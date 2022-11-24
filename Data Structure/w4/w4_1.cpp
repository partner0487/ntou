#include "iostream"
#include "iomanip"
using namespace std;

struct polynomial{
    float coef;
    int expon;
};
polynomial A[2000], B[2000], ans[2000];

int solve(int n, int k){
    int sta = n, stb = k;
    int nowa = 0, nowb = 0, nowAns = 0;
    while(nowa < n && nowb < k){
        if(A[nowa].expon == B[nowb].expon){
            ans[nowAns].coef = A[nowa].coef + B[nowb].coef;
            ans[nowAns++].expon = A[nowa].expon;
            ++nowa, ++nowb;
        }
        else if(A[nowa].expon < B[nowb].expon){
            ans[nowAns].coef = B[nowb].coef;
            ans[nowAns++].expon = B[nowb].expon;
            ++nowb;
        }
        else{
            ans[nowAns].coef = A[nowa].coef;
            ans[nowAns++].expon = A[nowa].expon;
            ++nowa;
        }
    }
    for(; nowa < n; nowa++){
        ans[nowAns].expon = A[nowa].expon;
        ans[nowAns++].coef = A[nowa].coef;
    }
    for(; nowb < k; nowb++){
        ans[nowAns].expon = B[nowb].expon;
        ans[nowAns++].coef = B[nowb].coef;
    }
    return nowAns;
}

int main(){
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i].coef >> A[i].expon;
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> B[i].coef >> B[i].expon;
    int idx = solve(n, k);

    for(int i = 0; i < n; i++){
        if(A[i].coef){
            cout << (i && A[i].coef > 0 ? "+" : "") << setprecision(2) << fixed << A[i].coef << (A[i].expon ? "x" : "") << (A[i].expon > 1 ? "^" : "");
            if(A[i].expon > 1) cout << A[i].expon;
        }
    }
    cout << endl;
    for(int i = 0; i < k; i++){
        if(B[i].coef){
            cout << (i && B[i].coef > 0 ? "+" : "") << setprecision(2) << fixed << B[i].coef << (B[i].expon ? "x" : "") << (B[i].expon > 1 ? "^" : "");
            if(B[i].expon > 1) cout << B[i].expon;
        }
    }
    cout << endl;
    for(int i = 0; i < idx; i++){
        if(ans[i].coef){
            cout << (i && ans[i].coef > 0 ? "+" : "") << setprecision(2) << fixed << ans[i].coef << (ans[i].expon ? "x" : "") << (ans[i].expon > 1 ? "^" : "");
            if(ans[i].expon > 1) cout << ans[i].expon;
        }
    }
    cout << endl;
}