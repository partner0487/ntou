#include "iostream"
#include "algorithm"
using namespace std;

struct DATA{
    int r, c, v;
};

bool cmp(DATA a, DATA b){
    return a.r < b.r || (a.r == b.r && a.c < b.c);
}

int main(){
    int r, c, v;
    cin >> r >> c >> v;
    DATA va[1000];
    for(int i = 0; i < v; i++){
        cin >> va[i].r >> va[i].c >> va[i].v;
        swap(va[i].r, va[i].c);
    }
    sort(va, va + v, cmp);
    cout << c << " " << r << " " << v << endl;
    for(int i = 0; i < v; i++)
        cout << va[i].r << " " << va[i].c << " " << va[i].v << endl;
}