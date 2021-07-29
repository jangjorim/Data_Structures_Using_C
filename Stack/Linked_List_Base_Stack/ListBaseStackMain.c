#include <stdio.h>
#include "ListBaseStack.h"

int main() {
	Stack stack;			// Stack을 생성한다.
	StackInit(&stack);		// Stack을 초기화 한다.

	for (int i = 1; i < 6; i++) {	// Stack에 값을 1에서 5까지 삽입한다.
		SPush(&stack, i);
	}
	
	while (!SIsEmpty(&stack))			// Stack안의 데이터를 전부 꺼내어 화면에 출력한다.
		printf("%d ", SPop(&stack));

	return 0;			// 프로그램을 종료한다.
}
