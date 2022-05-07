#pragma once
#include "stdio.h"
#include "stdlib.h"
#define STACK_SIZE 10

class defarray {
	private:
		int top, size;
		float *stack;
	public:
		defarray() : top(0), size(STACK_SIZE) {
			stack = new float[size];
		}
		bool push(float x);
		bool pop();
		bool isempty();
		bool isfull();
		float Top();
		void printstack(defarray s);
};

class allcarray{
	private:
		int top, size;
		float *stack;
	public:
		allcarray() : top(0), size(0){}
		bool init(int x) {
			size = x;
			stack = (float *)malloc(size * sizeof(float));
			if (stack == NULL) {
				printf("malloc fail\n");
				return 0;
			}
			printf("malloc success\n");
			return 1;
		}
		bool push(float x);
		bool pop();
		bool isempty();
		bool isfull();
		float Top();
		void printstack(allcarray s);
};

class node {
	private:
		float data;
		node *next;
	public:
		node(float x, node *nextnode) : data(x), next(nextnode) {};
		friend class stacklist;
};
class stacklist {
	private:
		node *top;
		int size;
	public:
		stacklist() : size(0), top(0) {};
		bool push(float x);
		bool pop();
		bool isempty();
		float Top();
		void printstack(stacklist s);
};

void def();
void allc();
void link();