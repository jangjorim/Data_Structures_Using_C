#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack) {			// 스택을 초기화 하는 함수 정의
	pstack->topIndex = -1;			// top을 가리키는 변수를 -1로 초기화 한다.
}

int SIsEmpty(Stack* pstack) {			// 스택이 비었는지 확인하는 함수 정의
	if (pstack->topIndex == -1)		// 스택이 비어 있다면
		return TRUE;			// 1을 반환 한다.
	else					// 그렇지 않다면
		return FALSE;			// 0을 반환 한다.
}

void SPush(Stack* pstack, Data data) {			// 스택에 데이터를 넣는 함수 정의
	pstack->topIndex += 1;				// 스택 데이터 삽입 위치를 +1 해준다.
	pstack->stackArr[pstack->topIndex] = data;	// 데이터를 삽입한다.
}

Data SPop(Stack* pstack) {			// 데이터를 제거하는 함수 정의
	int rIdx;				// 삭제할 데이터의 인덱스 값을 저장하는 변수

	if (SIsEmpty(pstack)) {			// 스택이 비었다면
		printf("Stack Memory Error!");	// 문구를 출력해 주고
		exit(-1);			// 시스템을 종료 한다.
	}
	rIdx = pstack->topIndex;		// 삭제할 데이터의 저장 위치를 변수에 대입한다.
	pstack->topIndex -= 1;			// 데이터 삽입 위치를 -1 해준다.

	return pstack->stackArr[rIdx];		// 삭제하는 데이터를 반환해 준다.
}

Data SPeek(Stack* pstack) {			// 스택에서 제일 상단에 위치해 있는 값을 반환하는 함수 정의
	if (SIsEmpty(pstack)) {			// 스택이 비었다면
		printf("Stack Memory Error!");	// 문구를 출력해 주고
		exit(-1);			// 시스템을 종료한다.
	}
	return pstack->stackArr[pstack->topIndex];			// 상단에 위치해 있는 데이터를 반환해 준다.
}
