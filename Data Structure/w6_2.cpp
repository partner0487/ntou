#include "iostream"
#include "queue"
using namespace std;

int main(){
    int S; cin >> S;
    queue<int> q;
    
    int op, n, cnt = 0;
    while(cin >> op){
        if(op == 1){
            cin >> n;
            if(cnt != (S - 1)){
                q.push(n);
                ++cnt;
            }
            else{
                cout << "FULL" << endl;
            }
            
        }
        else if(op == 0){
            if(q.empty()) cout << "EMPTY" << endl;
            else{
                cout << q.front() << endl;
                --cnt;
                q.pop();
            }
        }
        else break;
    }
}