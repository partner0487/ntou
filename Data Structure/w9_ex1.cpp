#include "iostream"
#include "queue"
#include "utility"
#include "string"
using namespace std;

struct node{
    string c;
    int v, w;
    node(string &_c, int &_v, int &_w){
        c = _c, v = _v, w = _w;
    }
};

struct cmp{
    bool operator()(node a, node b){
        int x = a.v / a.w, y = b.v / b.w;
        return x > y || (x == y && a.w < b.w);
    }
};

int main(){
    priority_queue<node, vector<node>, cmp> pq;

    string c;
    int v, w;
    int totalw = 0, totalv = 0;
    while(cin >> c){
        if(c == "-1") break;
        cin >> v >> w;
        node now = node(c, v, w);
        totalw += w, totalv += v;
        if(totalw > 20){
            totalw -= pq.top().w;
            totalv -= pq.top().v;
            pq.pop();
            pq.push(now);
        }
        else pq.push(now);
        cout << pq.top().c << " " << pq.top().v << " " << pq.top().w << endl;
    }
    cout << totalv << " " << totalw << endl;
}