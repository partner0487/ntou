#include "iostream"
using namespace std;

int max(int a, int b, int c){
    if(a > b && a > c) return a;
    if(b > a && b > c) return b;
    return c; 
}

int n;
string s;
int A[10000][10000], AT[10000][10000], ans[10000][10000];

int main(){
    cin >> n;
    int maxx = -1;
    for(int i = 0, x, y, v; i < n; i++){
        cin >> s;
        for(int j = 0, cnt = 0; j < s.length(); j++){
            if(s[j] >= '0' && s[j] <= '9'){
                if(cnt == 0) x = s[j] - '0';
                else if(cnt == 1) y = s[j] - '0';
                else v = s[j] - '0';
                cnt++;
            }
        }
        maxx = max(x, y, maxx);
        A[x - 1][y - 1] = v;
        AT[y - 1][x - 1] = v;
    }
    /*
    for(int i = 0; i < maxx; i++){
        for(int j = 0; j < maxx; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < maxx; i++){
        for(int j = 0; j < maxx; j++)
            cout << AT[i][j] << " ";
        cout << endl;
    }//*/
    // cout << maxx << endl;
    for(int i = 0; i < maxx; i++){
        for(int j = 0; j < maxx; j++){
            for(int k = 0; k < maxx; k++)
                ans[i][j] += (A[i][k] * AT[k][j]);
        }
    }
    for(int i = 0; i < maxx; i++){
        for(int j = 0; j < maxx; j++)
            cout << ans[i][j] << (j == maxx - 1 ? "" : " ");
        cout << endl;
    }
}