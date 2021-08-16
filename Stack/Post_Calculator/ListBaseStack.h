#pragma once
#ifndef  __LB_STACK_H__			// �ߺ� ������ �������� ����
#define  __LB_STACK_H__

#define TRUE	1;
#define FALSE	0;

typedef int Data;			// int���� Data��� �̸����� �缱��

typedef struct _node {			// ���� ����Ʈ�� ��带 ǥ���� ����ü
	Data data;
	struct _noed* next;
} Node;

typedef struct _listStack {			// ���� ����Ʈ ��� ������ ǥ���� ����ü
	Node* head;
} ListStack;

typedef ListStack Stack;			// Stack���� �̸��� �� ����

void StackInit(Stack* pstack);		// ���� �ʱ�ȭ
int SIsEmpty(Stack* pstack);		// ������ ������� Ȯ��

void SPush(Stack* pstack, Data data);			// ������ Push ����
Data SPop(Stack* pstack);						// ������ pop ����
Data SPeek(Stack* pstack);						// ������ peek ����


#endif // ! __LB_STACK_H__
