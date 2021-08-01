#include <stdint.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack) {			// 스택 초기화 함수 정의
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {			// 스택이 공백일 때 작동하는 함수 정의
	if (pstack->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void SPush(Stack* pstack, Data data) {			// 스택에 값을 삽입하는 함수 정의
	Node* newNode = (Node*)malloc(sizeof(Node));			// 새로운 노드 생생

	newNode->data = data;						// 새노드에 데이터 삽입
	newNode->next = pstack->head;					// 헤드가 가리키는 노드를 새노드가 가리킨다

	pstack->head = newNode;						//헤드가 새노드를 가리키게 하여 머리부분에 노드를 추가 시킨다.
}

Data SPop(Stack* pstack) {
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}
