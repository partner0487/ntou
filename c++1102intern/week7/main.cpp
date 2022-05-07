#include "iostream"
using namespace std;
#define p1n2(ans, x, y) ans = x * y
#define p1n3(ans, x, y, z) ans = x * y * z

void p2(int &ans, int x, int y, int z = 1){
    ans = x * y * z;
}
void p2(float &ans, float x, float y, float z = 1.0){
    ans = x * y * z;
}

template<typename type>void p3(type &ans, type x, type y){
    ans = x * y;
}
template<typename type> void p3(type &ans,  type x, type y, type z){
    ans = x * y * z;
}

template<typename type> void p4(type &ans, type x, type y, type z = 1){
    ans = x * y * z;
}

int main(){
    int ans1; float ans2;

    cout << "Q1:" << endl;
    p1n2(ans1, 1, 2);
    cout << "ans1:" << ans1 << endl;
    p1n3(ans1, 1, 2, 3);
    cout << "ans1:" << ans1 << endl;
    p1n2(ans2, 1.1f, 2.2f);
    cout << "ans2:" << ans2 << endl;
    p1n3(ans2, 1.1f, 2.2f, 3.3f);
    cout << "ans2:" << ans2 << endl;
    cout << endl;
    
    cout << "Q2:" << endl;
    p2(ans1, 1, 2);
    cout << "ans1:" << ans1 << endl;
    p2(ans1, 1, 2, 3);
    cout << "ans1:" << ans1 << endl;
    p2(ans2, 1.1f, 2.2f);
    cout << "ans2:" << ans2 << endl;
    p2(ans2, 1.1f, 2.2f, 3.3f);
    cout << "ans2:" << ans2 << endl;
    cout << endl;

    cout << "Q3:" << endl;
    p3(ans1, 1, 2);
    cout << "ans1:" << ans1 << endl;
    p3(ans1, 1, 2, 3);
    cout << "ans1:" << ans1 << endl;
    p3(ans2, 1.1f, 2.2f);
    cout << "ans2:" << ans2 << endl;
    p3(ans2, 1.1f, 2.2f, 3.3f);
    cout << "ans2:" << ans2 << endl;
    cout << endl;

    cout << "Q4:" << endl;
    p4(ans1, 1, 2);
    cout << "ans1:" <<ans1 << endl;
    p4(ans1, 1, 2, 3);
    cout << "ans1:" << ans1 << endl;
    p4(ans2, 1.1f, 2.2f);
    cout << "ans2:" << ans2 << endl;
    p4(ans2, 1.1f, 2.2f, 3.3f);
    cout << "ans2:" << ans2 << endl;
}