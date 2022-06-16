/*
Author: Xiaoyo
time: 2022/06/16
*/
#include "string"
#include "map"
#include "iostream"
using namespace std;

class book{
    private:
        string bookName;
        string authors;
    public:
        int price;
        book(string BN, string AT, int _price);
        void assign(string BN, string AT, int _price);
        string getBN();
        string getAT();
        int getPrice();
        book();
        friend ostream& operator << (ostream &out, book &a){
            out << a.bookName << " " << a.authors << " " << a.price;
            return out;
        }
};
class Lookuptable{
    private:   
        map<string, book> table;
    public: 
        virtual int add(book) = 0;
        virtual int remove(book) = 0;
        virtual book *find(string BN) = 0;
        virtual void clean();
        virtual book mostExpensive() = 0;
        virtual book cheapest() = 0;
        virtual double average() = 0;
};
//*
class adaptee{
    map<string, book> MB;
    public:
        void add(book v, int &result);
        void remove(book v, int &result);
        void find(string BN, book *&p);
        void clean();
        book mostExpensive();
        book cheapest();
        double average();
};
class adapter_object_1 : public Lookuptable{
    private:
        adaptee ad;
    public:
        int add(book);
        int remove(book);
        book *find(string BN);
        void clean();
        book mostExpensive();
        book cheapest();
        double average();
};
class adapter_class_1 : public Lookuptable, public adaptee{
    public:
        int add(book);
        int remove(book);
        book *find(string BN);
        void clean();
        book mostExpensive();
        book cheapest();
        double average();
};//*/
class adapter_object_2 : public Lookuptable{
    private:
        adaptee ad;
    public:
        int add(book);
        int remove(book);
        book *find(string BN);
        void clean();
        book mostExpensive();
        book cheapest();
        double average();
};
class adapter_class_2 : public Lookuptable, public adaptee{
    public:
        int add(book);
        int remove(book);
        book *find(string BN);
        void clean();
        book mostExpensive();
        book cheapest();
        double average();
};//*/
class adapter_object_3 : public Lookuptable{
    private:
        adaptee ad;
    public:
        int add(book);
        int remove(book);
        book *find(string BN);
        void clean();
        book mostExpensive();
        book cheapest();
        double average();
};
class adapter_class_3 : public Lookuptable, public adaptee{
    public:
        int add(book);
        int remove(book);
        book *find(string BN);
        void clean();
        book mostExpensive();
        book cheapest();
        double average();
};//*/