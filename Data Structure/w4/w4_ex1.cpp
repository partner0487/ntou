#include "iostream"
#include "string"
using namespace std;

int main(){
    string s, t1, t2;
    getline(cin, s);
    getline(cin, t1);
    t1.pop_back();
    getline(cin, t2);

    size_t found;
    while(1){
        found = s.find(t1);
        if(found != string::npos){
            s.erase(found, t1.length());
            s.insert(found, t2);
        }
        else break;    
    }
    cout << s << endl;
}