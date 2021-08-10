#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

//#pragma warning(disable:4996)

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
	char* convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);
	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			convExp[idx++] = tok;
		}
		else {
			switch (tok)
			{
			case 'c':
				SPush(&stack, tok);
				break;

			case ')':
				while (1) {
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
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

	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}