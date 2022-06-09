/*
Author: Xiaoyo
time: 2022/06/09
//*/
#include "iostream"
using namespace std;

template<typename T, int S>
class stack{
    private:
        int top, size;
        T *s;
    public:
        stack() : top(0), size(S){
            s = (T *) malloc(S * sizeof(T));
        }
        bool IsEmpty(){
            return top == 0;
        }
        bool IsFull(){
            return top == size;
        }
        T Top(){
            if(top == 0) return 0;
            return s[top - 1];
        }
        bool pop(){
            if(IsEmpty()) return 0;
            top--;
            return 1;
        }
        bool push(T x){
            if(IsFull()) return 0;
            s[top++] = x;
            return 1;
        }
        void printStack(){
            for(int i = 0; i < top; i++)
                cout << s[i] << " ";
            cout << endl;
        }
};