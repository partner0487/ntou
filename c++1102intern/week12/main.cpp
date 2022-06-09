/*
Author: Xiaoyo
time: 2022/06/09
*/
#include "iostream"
#include "string"
#include "map"
#include "book.h"
using namespace std;

book::book() : bookName(""), authors(""), price(0){}
book::book(string BN, string AT, int _price){
    bookName = BN;
    authors = AT;
    price = _price;
}
void book::assign(string BN, string AT, int _price){
    bookName = BN;
    authors = AT;
    price = _price;
}
string book::getBN() { return bookName; }
string book::getAT() { return authors; }
int book::getPrice() { return price; }

int Lookuptable::insert(book a){
    if(table.find(a.getBN()) != table.end()) return 0;
    table[a.getBN()] = a;
    return 1;
}
int Lookuptable::remove(book a){
    if(table.find(a.getBN()) == table.end()) return 0;
    table.erase(a.getBN());
    return 1;
}
book *Lookuptable::get(string BN){
    if(table.find(BN) == table.end()) return 0;
    return &table[BN];
}
void adaptee::insert(book v, int &result){
    if(MB.find(v.getBN()) != MB.end()) result = 0;
    else{
        MB[v.getBN()] = v;
        result = 1;
    }
}
void adaptee::remove(book v, int &result){
    if(MB.find(v.getBN()) == MB.end()) result = 0;
    else{
        MB.erase(v.getBN());
        result = 1;
    }
}
void adaptee::get(string BN, book *&p){
    if(MB.find(BN) == MB.end()) p = nullptr;
    else p = &MB[BN];
}
int adapter_object::insert(book a){
    int ret;
    ad.insert(a, ret);
    return ret;
}
int adapter_object::remove(book a){
    int ret;
    ad.remove(a, ret);
    return ret;
}
book *adapter_object::get(string BN){
    book *p;
    ad.get(BN, p);
    return p;
}
int adapter_class::insert(book a){
    int ret = 0;
    adaptee::insert(a, ret);
    return ret;
}
int adapter_class::remove(book a){
    int ret = 0;
    adaptee::remove(a, ret);
    return ret;
}
book *adapter_class::get(string BN){
    book *p;
    adaptee::get(BN, p);
    return p;
}

void run_LookupTable(Lookuptable *ptr){
    cout << endl << "Test LookupTable" << endl;

// insert
    cout << "Test insert" << endl;
    book val("精通光學辨識技術:應用ABBYY FineReader 11 OCR", "黃敦義", 371);
    cout << ptr->insert(val) << endl;
    val.assign("程式設計-使用C++", "黃建庭", 420);
    cout << ptr->insert(val) << endl;
    val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
    cout << ptr->insert(val) << endl;
    val.assign("程式設計-使用C++", "黃建庭", 420);
    cout << ptr->insert(val) << endl;

// remove
    cout << "Test remove" << endl;
    val.assign("VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
    cout << ptr->remove(val) << endl;
    cout << ptr->remove(val) << endl;

// get
    cout << "Test get" << endl;
    cout << ptr->get("精通光學辨識技術:應用ABBYY FineReader 11 OCR") << endl;
    cout << ptr->get("VISUAL FORTRAN程式設計與開發") << endl;
    cout << ptr->get("程式設計-使用C++") << endl;
}

int main(){
    cout << "Test adapter_class" << endl;
    // Lookuptable test;
    // run_LookupTable(&test);
    adapter_class ac;
    run_LookupTable(&ac);
    cout << endl;
    cout << "Test adapter_object" << endl;
    adapter_object ao;
    run_LookupTable(&ao);
}