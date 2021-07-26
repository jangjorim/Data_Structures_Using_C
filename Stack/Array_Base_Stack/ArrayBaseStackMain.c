#include <stdio.h>
#include "ArrayBaseStack.h"

int main() {
	Stack stack;			// ���� ����
	StackInit(&stack);		// ���� �ʱ�ȭ

	for (int i = 1; i < 6; i++)			// 1~5���� ���ÿ� ����
		SPush(&stack, i);

	while (!SIsEmpty(&stack))			// ������ ������� ������ ����
		printf("%d ", SPop(&stack));	// ������ ��ܿ��� ���� �����͸� �ϳ��� ���

	return 0;
}