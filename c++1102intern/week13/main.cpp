/*
Author: Xiaoyo
time: 2022/06/09
//*/
#include "iostream"
#include "stack.h"
using namespace std;

int main(){
    stack<int, 20> s1;
    cout << (s1.IsEmpty() ? "Is empty" : "Not empty") << endl;
    cout << (s1.IsFull() ? "Is full" : "Not full") << endl;
    for(int i = 1; i <= 15; i++)
        cout << (s1.push(i) ? "push succeed" : "push failed") << endl;
    cout << s1.Top() << endl;
    s1.printStack();
    cout << (s1.IsEmpty() ? "Is empty" : "Not empty") << endl;
    cout << (s1.IsFull() ? "Is full" : "Not full") << endl;
    for(int i = 1; i <= 15; i++)
        cout << (s1.pop() ? "pop succeed" : "pop failed") << endl;
    cout << (s1.IsEmpty() ? "Is empty" : "Not empty") << endl;
    cout << (s1.IsFull() ? "Is full" : "Not full") << endl;
    cout << endl;
    stack<float, 20> s2;
    cout << (s2.IsEmpty() ? "Is empty" : "Not empty") << endl;
    cout << (s2.IsFull() ? "Is full" : "Not full") << endl;
    for(float i = 1.01; i < 11; i += 1.01)
        cout << (s2.push(i) ? "push succeed" : "push failed") << endl;
    cout << s2.Top() << endl;
    s2.printStack();
    cout << (s2.IsEmpty() ? "Is empty" : "Not empty") << endl;
    cout << (s2.IsFull() ? "Is full" : "Not full") << endl;
    for(int i = 1; i <= 10; i++)
        cout << (s2.pop() ? "pop succeed" : "pop failed") << endl;
    cout << (s2.IsEmpty() ? "Is empty" : "Not empty") << endl;
    cout << (s2.IsFull() ? "Is full" : "Not full") << endl;
}