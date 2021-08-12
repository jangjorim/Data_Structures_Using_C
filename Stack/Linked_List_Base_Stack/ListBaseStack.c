#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack) {			// 스택 초기화 함수 정의
	pstack->head = NULL;				// 포인터 변수 head는 NULL로 초기화
}

int SIsEmpty(Stack* pstack) {			// 스택이 공백일 때 작동하는 함수 정의
	if (pstack->head == NULL) {			// 스택이 비면 head에는 NULL이 저장됨
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

Data SPop(Stack* pstack) {						// 스택안의 데이터를 뽑아내는 함수 정의
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {						// 스택이 비면 아래 구문을 실행시키고 프로그램 종료
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;					// 삭제할 노드의 데이터를 임시로 저장
	rnode = pstack->head;						// 삭제할 노드의 주소 값을 임시로 저장

	pstack->head = pstack->head->next;			// 삭제할 노드의 다음 노드를 head가 가리킨다.
	free(rnode);								// 노드를 삭제함

	return rdata;								// 삭제된 노드의 데이터를 반환
}

Data SPeek(Stack* pstack) {						// 스택에서 최상위에 저장되어 있는 데이터를 확인하는 함수 정의
	if (SIsEmpty(pstack)) {						// 스택이 비면 아래 구문을 실행시키고 프로그램 종료
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;					// head가 가리키는 최상단 노드에 저장된 데이터 반환
}
