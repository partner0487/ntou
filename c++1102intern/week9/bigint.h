#ifndef bigint_h
#define bigint_h
#include "string"

class bigint{
    private:
        int *digit;
        int cap, numdigit;
    public:
        ~bigint();
        bigint();
        bigint(const int value, const int size);
        bigint(const char * const, const int size);
        bigint(const bigint &);
        void zero();
        void add(const bigint &);
        void add(const int);
        void add(const char * const);
        void printvalue();
};

#endif