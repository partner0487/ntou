#include "iostream"
#include "algorithm"
using namespace std;

int n;
string s;
int A[15][15], AT[15][15], ans[15][15];

int main(){
    cin >> n;
    int maxx = -1;
    char c;
    int x, y, v;
    for(int i = 0; i < n; i++){
        cin >> c >> x >> c >> y >> c >> c >> v;
        maxx = max({x, y, maxx});
        A[x][y] += v;
        AT[y][x] += v;
    }
    for(int i = 1; i <= maxx; i++){
        for(int j = 1; j <= maxx; j++){
            for(int k = 1; k <= maxx; k++)
                ans[i][j] += (A[i][k] * AT[k][j]);
        }
    }
    for(int i = 1; i <= maxx; i++){
        for(int j = 1; j <= maxx; j++)
            cout << ans[i][j] << (j == maxx ? "" : " ");
        cout << endl;
    }
}