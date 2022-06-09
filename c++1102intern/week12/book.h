/*
Author: Xiaoyo
time: 2022/06/09
*/
#include "string"
#include "map"
#include "iostream"
using namespace std;

class book{
    private:
        string bookName;
        string authors;
        int price;
    public:
        book(string BN, string AT, int _price);
        void assign(string BN, string AT, int _price);
        string getBN();
        string getAT();
        int getPrice();
        book();
};
class Lookuptable{
    private:   
        map<string, book> table;
    public:
        virtual int insert(book) = 0;
        virtual int remove(book) = 0;
        virtual book *get(string BN) = 0;
};
//*
class adaptee{
    map<string, book> MB;
    public:
        void insert(book v, int &result);
        void remove(book v, int &result);
        void get(string BN, book *&p);
};
class adapter_object : public Lookuptable{
    private:
        adaptee ad;
    public:
        int insert(book);
        int remove(book);
        book *get(string BN);
};
class adapter_class : public Lookuptable, public adaptee{
    public:
        int insert(book);
        int remove(book);
        book *get(string BN);
};//*/