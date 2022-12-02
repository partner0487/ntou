#include "iostream"
using namespace std;

int Heap[10000];

void check(int idx){
    if(Heap[idx] < Heap[idx / 2]){
        swap(Heap[idx], Heap[idx / 2]);
        check(idx / 2);
    }
    return;
}

void insert(int n, int idx){
    Heap[idx] = n;
    check(idx);
}
void print(int cnt){
    for(int i = 1; i <= cnt; i++)
        cout << "[" << i << "]" << Heap[i] << (i == cnt ? "" : " ");
    cout << endl;
}

int main(){
    int n;
    int cnt = 1;
    while(cin >> n){
        insert(n, cnt);
        print(cnt++);
    }
}