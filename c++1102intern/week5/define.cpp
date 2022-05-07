#include "stdio.h"
#include "stack.h"

void def() {
	defarray s;
	s.pop();
	for (float i = 0; i < 11; i += 0.5) {
		s.push(i);
	}
	// s.pop();
	s.printstack(s);
}