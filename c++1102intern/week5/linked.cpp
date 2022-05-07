#include "stdio.h"
#include "stack.h"

void link() {
	stacklist s;
	s.pop();
	for (float i = 0; i < 20; i += 0.5) {
		s.push(i);
	}
	s.printstack(s);
}