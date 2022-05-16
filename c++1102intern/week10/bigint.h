/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 15
//*/
#ifndef bigint_h
#define bigint_h
#include "iostream"
#include "string"
using namespace std;

class bigint{
    public:
        char *digit;
        int cap, numdigit, sign;
        ~bigint();
        bigint();
        bigint(int value, int size);
        bigint(const char * const, int size);
        bigint(bigint &);
        bigint(char *, int, int, int);
        void zero();
        void printvalue();
        void update(int);
        void update(bigint);

        friend ostream &operator << (ostream &, const bigint &);
        // bigint operator = (bigint);
        bigint operator = (int);
        bigint operator = (bigint);
        bigint operator += (bigint);
        bigint operator += (int);
        bigint operator + (bigint);
        bigint operator + (int);
        bigint operator ++ ();
        bigint operator ++ (int);
};

ostream &operator << (ostream&, bigint &);

#endif