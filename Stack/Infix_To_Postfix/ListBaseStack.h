#pragma once
#ifndef  __LB_STACK_H__			// 중복 선언을 막기위한 구문
#define  __LB_STACK_H__

#define TRUE	1;
#define FALSE	0;

typedef int Data;			// int형을 Data라는 이름으로 재선언

typedef struct _node {			// 연결 리스트의 노드를 표현한 구조체
	Data data;
	struct _noed* next;
} Node;

typedef struct _listStack {			// 연결 리스트 기반 스택을 표현한 구조체
	Node* head;
} ListStack;

typedef ListStack Stack;			// Stack으로 이름을 재 선언

void StackInit(Stack* pstack);		// 스택 초기화
int SIsEmpty(Stack* pstack);		// 스택이 비었는지 확인

void SPush(Stack* pstack, Data data);			// 스택의 Push 연산
Data SPop(Stack* pstack);						// 스택의 pop 연산
Data SPeek(Stack* pstack);						// 스택의 peek 연산


#endif // ! __LB_STACK_H__
