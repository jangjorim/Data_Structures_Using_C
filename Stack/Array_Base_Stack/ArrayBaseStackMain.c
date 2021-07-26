#include <stdio.h>
#include "ArrayBaseStack.h"

int main() {
	Stack stack;			// 스택 생성
	StackInit(&stack);		// 스택 초기화

	for (int i = 1; i < 6; i++)			// 1~5까지 스택에 삽입
		SPush(&stack, i);

	while (!SIsEmpty(&stack))			// 스택이 비어지기 전까지 실행
		printf("%d ", SPop(&stack));	// 스택의 상단에서 부터 데이터를 하나씩 출력

	return 0;
}