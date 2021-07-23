#pragma once

#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE	1
#define FALSE	0
#define STACK_LEN	100			// 스택 사이즈를 정할 메크로 선언

typedef int Data;

typedef struct _arrayStack {			// Stack 구조체 정의
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);			// Stack을 초기화 하는 함수 선언
int SIsEmpty(Stack* pstack);			// Stack이 비었는지 확인하는 함수 선언

void SPush(Stack* pstack, Data data);		// 값을 넣는 함수 선언
Data SPop(Stack* pstack);			// 값을 빼내는 함수 선언
Data SPeek(Stack* pstack);			// Stack에서 제일 위에 위치하고 있는 값을 확인하는 함수 선언

#endif
