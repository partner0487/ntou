#pragma once
#include "iostream"
using namespace std;

template<typename type, int mxn> struct stack {
	int top, size;
	type *s;
	stack() {
		top = 0;
		size = mxn;
		s = (type *)malloc(size * sizeof(type));
	}
	bool isempty() {
		return top == 0;
	}
	bool isfull() {
		return top == size;
	}
	type Top() {
		if (top == 0) return 0;
		return s[top - 1];
	}
	bool pop() {
		if (isempty()) return 0;
		top--;
		return 1;
	}
	bool push(type x) {
		if (isfull()) return 0;
		s[top++] = x;;
		return 1;
	}
	void printstack() {
		for (int i = 0; i < top; i++){
			cout << s[i] << " ";
		}
		cout << endl;
	}
};


