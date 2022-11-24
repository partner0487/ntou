#include "iostream"
using namespace std;

int m[10][10];
int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {-1, 0}};
bool vis[10][10];

int dfs(int x, int y){
    if(vis[x][y]) return 0;
    vis[x][y] = 1;
    if(x == 1 && y == 1) return 1;
    for(int i = 0; i < 4; i++){
        int nx = x + d[i][0], ny = y + d[i][1];
        // cout << nx << " " << ny << endl;
        if(m[nx][ny] == 1) continue;
        if(dfs(nx, ny)){
            m[nx][ny] = 2;
            return 1;
        }
        else m[nx][ny] = 3;
    }
    return 0;
}

int main(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            cin >> m[i][j];
    }
    cout << (dfs(8, 8) ?  "YES" : "NO" )<< endl;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i == 1 && j == 1) cout << "X";
            else if(i == 8 && j == 8) cout << "S";
            else if(m[i][j] == 3) cout << "D";
            else if(m[i][j] == 2) cout << "G";
            else cout << m[i][j];
            cout << (j == 9 ? "" : " ");
        }
        cout << endl;
    }
}