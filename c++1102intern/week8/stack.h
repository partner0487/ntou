#pragma once
#include "iostream"
#include "stdlib.h"
using namespace std;

class Stack {
private:
	int __top, __size;
	int *stack;
public:
	Stack(int size);
	~Stack();
	int stackInitial(int size);
	bool push(int x);
	bool pop();
	bool isempty();
	bool isfull();
	int Top();
	void takestack();
	void printstack();
};
