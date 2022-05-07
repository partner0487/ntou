#include "iostream"
#include "max.h"
#include "stack.h"
using namespace std;

int main() {
	int n, m;
	while (cin >> n) {
		if (n == 1) {
			int a1[] = { 1, 2, 3, 5, 4 };
			double a2[] = { 1.2, 3.4, 5.6, 2.3, 4.5 };
			while(cin >> m){
				if (m == 1) cout << Max<int>(a1, 5) << endl;
				else if (m == 2) cout << Max<double>(a2, 5) << endl;
				else break;
			}
		}
		else if (n == 2) {
			while (cin >> m) {
				if (m == 1) {
					stack<int, 20> arr = stack<int, 20>();
					for (int i = 0; i < 20; i++) {
						arr.push(i) ? cout << "push success" : cout << "push fail";
						cout << endl;
					}
					arr.isfull() ? cout << "full" : cout << "not full";
					cout << endl;
					arr.pop() ? cout << "pop success" : cout << "pop fail";
					cout << endl;
					arr.printstack();
					cout << endl;
					//*
					while (!arr.isempty()) {
						cout << arr.Top() << endl;
						arr.pop();
					}
					cout << endl;//*/
				}
				else if (m == 2) {
					stack<float, 15> arr = stack<float, 15>();
					for (float i = 0; i < 20; i += 0.5) {
						arr.push(i) ? cout << "push success" : cout << "push fail";
						cout << endl;
					}
					arr.isfull() ? cout << "full" : cout << "not full";
					cout << endl;
					arr.pop() ? cout << "pop success" : cout << "pop fail";
					cout << endl;
					arr.printstack();
					cout << endl;
					//*
					while (!arr.isempty()) {
						cout << arr.Top() << endl;
						arr.pop();
					}
					cout << endl;//*/
				}
				else break;
			}
		}
		else break;
	}
}