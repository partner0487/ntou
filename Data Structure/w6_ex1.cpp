#include "iostream"
#include "stack"
#include "iomanip"
using namespace std;

struct BAG{
    char c;
    float v, w;
    BAG(char _c, float _v, float _w){
        c = _c , v = _v, w = _w;
    }
};

int main(){
    stack<BAG> bag;
    char c; float v, w;

    float wcnt = 0, vcnt = 0;;
    while(cin >> c >> v >> w){
        if(20 - wcnt >= w){
            bag.push(BAG(c, v, w));
            wcnt += w;
            vcnt += v;
        }
        //*
        else{
            stack<BAG> tmp;
            // cout << c << " " << v << " " << w << endl;
            while(!bag.empty()){
                BAG now = bag.top();
                bag.pop();
                // cout << now.c << " " << now.v << " " << now.w << endl << endl;
                if(20 - wcnt + now.w >= w && v > now.v){
                    wcnt -= now.w;
                    vcnt -= now.v;
                    while(!tmp.empty()){
                        bag.push(tmp.top());
                        tmp.pop();
                    }
                    wcnt += w;
                    vcnt += v;
                    bag.push(BAG(c, v, w));
                    break;
                }
                else{
                    tmp.push(now);
                }
            }
            while(!tmp.empty()){
                bag.push(tmp.top());
                tmp.pop();
            }
        }//*/
    }
    // cout << endl;
    while(!bag.empty()){
        cout << bag.top().c << " " << fixed << setprecision(1) << bag.top().v << " " << bag.top().w << endl;
        bag.pop();
    }
    cout << "weight:" << fixed << setprecision(1) << wcnt << endl;
    cout << "value:" << fixed << setprecision(1) << vcnt << endl;
}