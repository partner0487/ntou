#include "iostream"
#include "iomanip"
#include "algorithm"
using namespace std;

struct polynomial{
    float coef;
    int expon;
    bool vis;
};
polynomial A[2000], B[2000], C[2000], ans[2000];

int solve(int n, int k){
    int idx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            C[idx].coef = A[i].coef * B[j].coef;
            C[idx++].expon = A[i].expon + B[j].expon;
        }
    }
    int now = 0;
    for(int i = 0; i < idx; i++){
        if(C[i].vis) continue;
        ans[now].expon = C[i].expon;
        ans[now].coef = C[i].coef;
        for(int j = i + 1; j < idx; j++){
            if(C[i].expon == C[j].expon){
                ans[now].coef += C[j].coef;
                C[j].vis = 1;    
            }
        }
        now++;
    }
    return now;
}

bool cmp(polynomial a, polynomial b){
    return a.expon > b.expon;
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
    sort(ans, ans + idx, cmp);

    for(int i = 0; i < idx; i++){
        if(ans[i].coef){
            cout << (i && ans[i].coef > 0 ? "+" : "") << setprecision(2) << fixed << ans[i].coef << (ans[i].expon ? "x" : "") << (ans[i].expon > 1 ? "^" : "");
            if(ans[i].expon > 1) cout << ans[i].expon;
        }
    }
    cout << endl;
}