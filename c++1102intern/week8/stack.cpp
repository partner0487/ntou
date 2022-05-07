#include "stack.h"
#include "iostream"
using namespace std;

Stack::Stack(int size = 10) {
	__top = 0;
	__size = size;
	stack = (int *)malloc(__size * sizeof(int));
}

Stack::~Stack() {
	free(stack);
}
int Stack::stackInitial(int size) {
	__top = 0;
	__size = size;
	free(stack);
	stack = (int *)malloc(size * sizeof(size));
	return (stack == NULL ? 0 : 1);
}

bool Stack::isfull() {
	return (__top == __size);
}
bool Stack::isempty() {
	return (!__top);
}
bool Stack::push(int x) {
	if (isfull()) return 0;
	stack[__top++] = x;
	return 1;
}
bool Stack::pop() {
	if (isempty()) return 0;
	--__top;
	return 1;
}
void Stack::printstack() {
	for (int i = 0; i < __top; i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
}
void Stack::takestack() {
	while (__top) {
		cout << Top() << " ";
		pop();
	}
	cout << endl;
}
int Stack::Top() {
	return stack[__top - 1];
}