#include "stdio.h"
#include "stack.h"

int main() {
	int n;
	while (scanf_s("%d", &n)) {
		if (n == 1) def();
		else if (n == 2) allc();
		else if (n == 3) link();
		else break;
	}
}