/*
Author: Xiaoyo
id: 01057020
time: 2022/05/26
*/
#include "Mystring.h"
using namespace std;

int Mystring::total;
Mystring::record::record(char x){
    now = x;
    nxt = last = NULL;
}
Mystring::record::record(){
    now = 0;
    nxt = last = NULL;
}
int Mystring::length(){
    return len;
}
int Mystring::StringCount(){
    return total;
}
Mystring Mystring::operator + (Mystring x){
    record *ns = NULL, *nl = NULL; int nlen = len + x.len;
    record *now = start, *nowd;
    ns = nl = new record(now->now);
    now = now->nxt;
    while(now != NULL){
        nl->nxt = new record(now->now);
        nl->nxt->last = nl;
        nl = nl->nxt;
        now = now->nxt;
    }
    now = x.start;
    while(now != NULL){
        nl->nxt = new record(now->now);
        nl->nxt->last = nl;
        nl = nl->nxt;
        now = now->nxt;
    }
    Mystring y(ns, nl, nlen);
    return y;
}
Mystring Mystring::operator += (Mystring x){
    Mystring::record *now = x.start;
    while(now != x.last->nxt){
        last->nxt = new record(now->now);
        last->nxt->last = last;
        last = last->nxt;
        now = now->nxt;
    }
    len += x.len;
    return *this;
}
Mystring Mystring::operator = (Mystring x){
    len = x.len, start = last = NULL;
    record *now = x.start;
    start = last = new record(now->now); now = now->nxt;
    while(now != NULL){
        last->nxt = new record(now->now);
        last->nxt->last = last;
        last = last->nxt;
        now = now->nxt;
    }
    return *this;
}
char Mystring::operator = (char x){
    return x;
}
bool Mystring::operator == (Mystring &x){
    if(x.len != len) return 0;
    record *a = start, *b = x.start;
    while(a != NULL){
        if(a->now != b->now) return 0;
        a = a->nxt; b = b->nxt;
    }
    return 1;
}
bool Mystring::operator != (Mystring &x){
    return !(*this == x);
}
char& Mystring::operator [] (int x){
    int idx = 0;
    record *now = start;
    while(now != NULL){
        if(idx == x) return now->now;
        ++idx; now = now->nxt;
    }
    return now->now;
}
ostream& operator << (ostream &out, Mystring &x){
    Mystring::record *now = x.start;
    while(now != NULL){
        out << now->now;
        now = now->nxt;
    }
    return out;
}
istream& operator >> (istream &in, Mystring &x){
    char a;
    x.len = 0;
    x.start = x.last = NULL;
    while(in >> a){
        if(x.last == x.start && x.start == nullptr){
            x.start = x.last = new Mystring::record(a);
            x.len++;
        }
        else{
            x.last->nxt = new Mystring::record(a);
            x.last->nxt->last = x.last;
            x.last = x.last->nxt;
            x.len++;
        }
    }
    return in;
}

Mystring::Mystring(){
    len = 0; start = last = NULL;
    total++;
}
Mystring::Mystring(const char *str){
    len = 0; start = last = NULL;
    start = last = new record(str[0]);
    len = 1;
    for(const char *i = str + 1; *i != '\0'; i++){
        last->nxt = new record(*i);
        last->nxt->last = last;
        last = last->nxt;
        ++len;
    }
    total++;
}
Mystring::Mystring(Mystring &now){
    len = 0; start = last = NULL;
    record *nowd = now.start;
    start = last = new record(nowd->now);
    nowd = nowd->nxt;
    while(nowd != NULL){
        last->nxt = new record(nowd->now);
        last->nxt->last = last;
        last = last->nxt;
        nowd = nowd->nxt;
    }
    len = now.len;
    total++;
}
Mystring::Mystring(record *a, record *b, int l){
    start = a, last = b, len = l;
}
Mystring::~Mystring(){
    cout << "destruct: ";
    record *now = start;
    if(now != nullptr){
        for(int i = 0; i < len and now != nullptr; i++){
            cout << now->now;
            delete now->last;
            now = now->nxt;
        }
    }
    cout << endl;
    total--;
}

Mystring_Derived::Mystring_Derived() : Mystring(){}
Mystring_Derived::Mystring_Derived(const char *str) : Mystring(str){}
Mystring_Derived::Mystring_Derived(Mystring &x) : Mystring(x){}
Mystring_Derived::~Mystring_Derived(){} 
ostream& operator << (ostream &out, Mystring_Derived &x){
    Mystring_Derived::record *now = x.start;
    while(now != NULL){
        out << now->now;
        now = now->nxt;
    }
    return out;
}
void testMystring(){
    Mystring str1("String"), str2("Test String 2"), str3(str1);
    cout << "str1 is: " << str1 << endl;
    cout << "str2 is: " << str2 << endl;
    cout << "str3 is: " << str3 << endl;
    cout << "The number of MyString instances is: " << Mystring::StringCount() << endl;

    /////////////////////////////////////////////////////////
    cout << endl << "Test input: ";
    cout << "Give one word " << endl;
    cin >> str1; // from stdin "this is a test line"
    cout << "str1 is: " << str1 << endl;
    /////////////////////////////////////////////////////////
    
    cout << endl << "Test +: " << endl;
    Mystring str4 = str1 + str2;
    cout << "str1 + str2 is: " << str4 << endl;

    cout << endl << "Test =: " << endl; 
    str2 = str1;
    cout << "str2 is: " << str2 << endl;
    /////////////////////////////////////////////////////////

    cout << endl << "Test +=: " << endl;
    str3 += str1;
    cout << "str3 is: " << str3 << endl;

    /////////////////////////////////////////////////////////

    cout << endl << "Test [] 1: " << endl;
    cout << "str3 is: ";
    for (unsigned i = 0; i < str3.length(); i++) cout << str3[i];
    cout << endl;

    cout << endl << "Test [] 2: " << endl;
    for (unsigned i = 0; i < str3.length(); i++) str3[i] = 'a' + i;
    cout << "str3 is: " << str3 << endl;

    /////////////////////////////////////////////////////////
    cout << endl << "Compare: " << endl;
    cout << "str1 is: " << str1 << endl;
    cout << "str2 is: " << str2 << endl;
    cout << "str3 is: " << str3 << endl;
    cout << "Compare str1 == str2 is: " << (str1 == str2) << endl;
    cout << "Compare str1 == str3 is: " << (str1 == str3) << endl;
    cout << "Compare str1 != str2 is: " << (str1 != str2) << endl;
    cout << "Compare str1 != str3 is: " << (str1 != str3) << endl;

}

void testMyString_Derived(){
    Mystring_Derived str1("NTOU");
    Mystring str2 = (Mystring)str1;
    cout << str2 << endl;   
    Mystring *A = static_cast<Mystring*>(&str1);
    Mystring *B = dynamic_cast<Mystring*>(&str1);
    cout << A << " " << *A << endl;
    cout << B << " " << *B << endl;
}

int main(){
    cout << "testMystring: " << endl;
    testMystring();
    cout << endl;
    cout << "testMystring_Derived: " << endl;
    testMyString_Derived();
}