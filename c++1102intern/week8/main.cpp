#include "iostream"
#include "stack.h"
using namespace std;

int main() {
	Stack s(5);
	cout << "Q1" << endl;
	for (int i = 0; i < 5; i++)
		cout << (s.push(i) ? "push success" : "push failed") << endl;
	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	for (int i = 0; i < 3; i++)
		cout << (s.pop() ? "pop success" : "pop failed" ) << endl;

	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	for (int i = 0; i < 2; i++)
		cout << (s.pop() ? "pop success" : "pop failed") << endl;

	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	//-------------------------------------- 
	cout << "Q2" << endl;
	s.stackInitial(10);
	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	for (int i = 0; i < 10; i++)
		cout << (s.push(i) ? "push success" : "push failed") << endl;
	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	for (int i = 0; i < 5; i++)
		cout << (s.pop() ? "pop success" : "pop failed") << endl;

	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	for (int i = 0; i < 5; i++)
		cout << (s.pop() ? "pop success" : "pop failed") << endl;

	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	//--------------------------------------
	cout << "Q3" << endl;
	s.stackInitial(15);
	for (int i = 0; i < 15; i++)
		cout << (s.push(i) ? "push success" : "push failed") << endl;
	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	for (int i = 0; i < 5; i++)
		cout << (s.pop() ? "pop success" : "pop failed") << endl;

	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	for (int i = 0; i < 5; i++)
		cout << (s.pop() ? "pop success" : "pop failed") << endl;

	cout << (s.isempty() ? "stack is empty" : "stack is not empty") << endl;
	cout << (s.isfull() ? "stack is full" : "stack is not full") << endl;

	///////////////////////////////////////////////////////////////////////////////////////////
}