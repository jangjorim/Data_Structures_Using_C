#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"



int GetOpPrec(char op){			// 연산자의 우선 순위 정보를 반환 한다.
	switch (op)
	{
	case '*' :
	case '/' :
		return 5;				// 가장 높은 우선순위로 리턴
	
	case '+':
	case '-':
		return 3;				// 5보다는 작고 1보다는 높은 우선 순위로 리턴

	case '(':
		return 1;				// 가장 낮은 우선순위로 리턴
	}

	return -1;					// 등록되지 않은 연산자임을 알림
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)			// op1의 우선 순위가 높다면 1을 리턴
		return 1;
	else if (op1Prec < op2Prec)		// op2의 우선 순위가 더 높다면 -1을 리턴
		return -1;
	else							// op1과 op2가 우선 순위가 같다면 0을 리턴
		return 0;
}

void ConvToRPNExp(char exp[]) {
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);			// 변환된 수식을 담을 공간을 마련함

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);			// 할당된 배열을 0으로 초기화
	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i];			// exp에 저장된 수식을 한 문자씩 tok에 저장
		if (isdigit(tok)) {			// tok에 저장된 문자가 숫자인지 확인
			convExp[idx++] = tok;			// 숫자이면 배열 convExp에 저장
		}
		else {
			switch (tok)
			{
			case '(':					// 여는 소괄호 이면
				SPush(&stack, tok);		// 스택에 쌓는다
				break;

			case ')':					// 닫는 소괄호 이면
				while (1) {
					popOp = SPop(&stack);		// 스택에서 연산자를 꺼내어
					if (popOp == '(')			// 연산자 ( 를 만날 까지
						break;
					convExp[idx++] = popOp;		// 배열 convExp에 저장한다.
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))			// 스택에 남아 있는 모든 연산자를
		convExp[idx++] = SPop(&stack);	// 배열 convExp로 이동한다.

	strcpy(exp, convExp);				// 변환한 수식을 exp에 복사하고
	// strcpy 함수에서 오류가 발생하면 #pragma warning(disable:4996)를 선언해 준다.
	free(convExp);						// convExp는 소멸 시킨다.
}
