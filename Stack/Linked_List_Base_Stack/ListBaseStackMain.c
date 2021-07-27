#include <stdio.h>
#include "ListBaseStack.h"

int main() {
	Stack stack;
	StackInit(&stack);

	for (int i = 1; i < 6; i++) {
		SPush(&stack, i);
	}
	
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}