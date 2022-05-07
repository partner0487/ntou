/*
Author: Xiaoyo
num: 01057020
time: 2022 / 05 / 07
//*/
#ifndef bigint_h
#define bigint_h
#include "string"

class bigint{
    public:
        int *digit;
        int cap, numdigit;
        ~bigint();
        bigint();
        bigint(int value, int size);
        bigint(const char * const, int size);
        bigint(bigint &);
        void zero();
        void add(bigint &);
        void add(int);
        void add(const char * const);
        void printvalue();
};

#endif