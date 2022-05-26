/*
Author: Xiaoyo
id: 01057020
time: 2022/05/26
*/
#ifndef string_h
#define string_h

#include "iostream"
using namespace std;

class Mystring{
    public:
        class record{
            public:
                char now;
                record *nxt, *last;
                record(char);
                record();
        };
        record *start, *last;
        int len;
        int length();
        static int total;
        static int StringCount();

        Mystring();
        Mystring(const char *str);
        Mystring(Mystring&);
        Mystring(record*, record*, int len);
        ~Mystring();

        Mystring operator + (Mystring);
        Mystring operator += (Mystring);
        Mystring operator = (Mystring);
        char operator = (char);
        bool operator == (Mystring&);
        bool operator != (Mystring&);
        char &operator [](int);
        friend ostream &operator << (ostream&, Mystring&);
        friend istream &operator >> (istream&, Mystring&);
};

class Mystring_Derived: public Mystring{
    public:
        Mystring_Derived();
        Mystring_Derived(const char *str);
        Mystring_Derived(Mystring&);
        ~Mystring_Derived();

        friend ostream &operator << (ostream&, Mystring_Derived&);
};

void testMyString_Derived();
void testMystring();

#endif