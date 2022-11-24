/*寫得真醜 有更好的寫法啦哈哈*/
#include "iostream"
using namespace std;

int n, m;
char arr[20][20];
string target;

int right(int x, int y, int now){
    if(arr[y][x] != target[now]) return 0;
    if(now == target.size() - 1) return 1;
    x = (x + 1) % n;
    return right(x, y, now + 1);
}
int left(int x, int y, int now){
    if(arr[y][x] != target[now]) return 0;
    if(now == target.size() - 1) return 1;
    x = (x + n - 1) % n;
    return left(x, y, now + 1);
}
int top(int x, int y, int now){
    if(arr[y][x] != target[now]) return 0;
    if(now == target.size() - 1) return 1;
    y = (y + n - 1) % n;
    return top(x, y, now + 1);
}
int down(int x, int y, int now){
    if(arr[y][x] != target[now]) return 0;
    if(now == target.size() - 1) return 1;
    y = (y + 1) % n;
    return down(x, y, now + 1);
}

int sur(int x, int y){
    int rx = (x + 1) % n, ty = (y + n - 1) % n;
    int lx = (x + n - 1) % n, dy = (y + 1) % n;
    return right(rx, y, 1) || left(lx, y, 1) || top(x, ty, 1) || down(x, dy, 1);
}

int FindF(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(arr[i][j] == target[0])
                if(sur(j, i)) return 1;
    return 0;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++){
        cin >> target;
        cout << (FindF() ? "Yes" : "No") << endl;;
    }
}