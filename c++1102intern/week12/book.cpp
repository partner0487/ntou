/*
Author: Xiaoyo
time: 2022/06/09
//*/
/*
#include "book.h"
#include "string"
#include "iostream"
#include "map"
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
//*/