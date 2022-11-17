#include "iostream"
#include "queue"
#include "utility"
#include "string"
#include "iomanip"
using namespace std;

struct node{
    string c;
    float v, w;
    node(string &_c, float &_v, float &_w){
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
    float v, w;
    float totalw = 0;
    int totalv = 0;
    while(cin >> c){
        if(c == "-1") break;
        cin >> v >> w;
        node now = node(c, v, w);
        if(totalw + w <= 20){
            totalw += w;
            totalv += v;
            pq.push(now);
        }
        else{
            while(pq.top().v / pq.top().w < now.v / now.w || totalw + now.w <= 20){
                if(totalw + now.w <= 20){
                    totalw += w;
                    totalv += v;
                    pq.push(now);
                }
                else if(pq.top().v / pq.top().w < now.v / now.w){
                    totalw -= pq.top().w;
                    totalv -= pq.top().v;
                    pq.pop();
                }
            }
        }
    }
    while(!pq.empty()){
        cout << pq.top().c;
        pq.pop();
        cout << (pq.empty() ? "" : " ");
    }
    cout << endl;
    cout << "total weight:" << setprecision(2) << fixed << totalw << endl;
    cout << "total value:" << totalv << endl;
}