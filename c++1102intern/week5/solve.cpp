#include "stack.h"
#include "stdlib.h"

bool defarray::isfull() {
	return (top == size);
}
bool defarray::isempty() {
	return (!top);
}
bool defarray::push(float x) {
	if (isfull()) {
		printf("push fail\n");
		return 0;
	}
	stack[top++] = x;
	printf("push success\n");
	return 1;
}
bool defarray::pop() {
	if (isempty()) {
		printf("pop fail\n");
		return 0;
	}
	--top;
	printf("pop success\n");
	return 1;
}
void defarray::printstack(defarray s) {
	while (top) {
		printf("%f ", s.Top());
		s.pop();
		--top;
	}
}
float defarray::Top() {
	return stack[top - 1];
}

bool allcarray::isfull() {
	return (top == size);
}
bool allcarray::isempty() {
	return (!top);
}
bool allcarray::push(float x) {
	if (isfull()) {
		printf("push fail\n");
		return 0;
	}
	stack[top++] = x;
	printf("push success\n");
	return 1;
}
bool allcarray::pop() {
	if (isempty()) {
		printf("pop fail\n");
		return 0;
	}
	--top;
	printf("pop success\n");
	return 1;
}
void allcarray::printstack(allcarray s) {
	while (top) {
		printf("%f ", s.Top());
		s.pop();
		--top;
	}
}
float allcarray::Top() {
	return stack[top - 1];
}

bool stacklist::isempty() {
	return size == 0;
}
bool stacklist::push(float x) {
	printf("push success\n");
	node *newnode = new node(x, top);
	newnode->next = top;
	top = newnode;
	size++;
	return 1;
}
bool stacklist::pop() {
	if (isempty()) {
		printf("pop fail\n");
		return 0;
	}
	node *dlt = top;
	top = top->next;
	delete dlt;
	size--;
	printf("pop success\n");
	return 1;
}
void stacklist::printstack(stacklist s) {
	while (!s.isempty()) {
		printf("%f ", s.Top());
		s.pop();
	}
}
float stacklist::Top() {
	if (isempty()) {
		printf("isempty\n");
		return -1;
	}
	return top->data;
}
