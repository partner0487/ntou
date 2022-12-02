#include "iostream"
#include "algorithm"
using namespace std;
#define INF 214'748'364'7

int Heap[10000];
int N[100000];

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
void pull(int idx){
    if(!Heap[2 * idx] && !Heap[2 * idx + 1]){
        Heap[idx] = 0;
        return;
    }
    if(Heap[2 * idx] && Heap[2 * idx + 1]){
        if(Heap[2 * idx] < Heap[2 * idx + 1]){
            Heap[idx] = Heap[2 * idx];
            pull(2 * idx);
        }
        else if(Heap[2 * idx] > Heap[2 * idx + 1]){
            Heap[idx] = Heap[2 * idx + 1];
            pull(2 * idx + 1);
        }
    }
    else{
        Heap[idx] = max(Heap[2 * idx], Heap[2 * idx + 1]);
        pull((Heap[2 * idx] ? 2 * idx : 2 * idx + 1));
    }
    
}
void recheck(int cnt){
    int tmp[10000];
    for(int i = 0; i < 10000; i++)
        tmp[i] = 0;
    int idx = 1;
    for(int i = 1; i < cnt; i++){
        if(Heap[i]){
            tmp[idx++] = Heap[i];
        }
    }
    for(int i = 1; i <= idx; i++){
        Heap[i] = tmp[i];
    }
}
void del(){
    if(Heap[3] < Heap[2]){
        Heap[1] = Heap[3];
        pull(3);
    }
    else{
        Heap[1] = Heap[2];
        pull(2);
    }
}

void print(int idx){
    for(int i = 1; i < idx; i++)
        if(Heap[i])
            cout << "[" << i << "]" << Heap[i] << (Heap[i + 1] ? " " : "");
    cout << endl;
}

int main(){
    int n;
    int cnt = 1;
    while(cin >> n){
        insert(n, cnt++);
        N[cnt - 2] = n;
    }
    print(cnt);
    for(int i = 0; i < cnt - 2; i++){
        del();
        recheck(cnt);
        print(cnt);
    }
}
// 7 8 7 10 12 14