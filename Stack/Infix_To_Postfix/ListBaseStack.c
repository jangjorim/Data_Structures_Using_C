
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack) {			// ���� �ʱ�ȭ �Լ� ����
	pstack->head = NULL;				// ������ ���� head�� NULL�� �ʱ�ȭ
}

int SIsEmpty(Stack* pstack) {			// ������ ������ �� �۵��ϴ� �Լ� ����
	if (pstack->head == NULL) {			// ������ ��� head���� NULL�� �����
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void SPush(Stack* pstack, Data data) {			// ���ÿ� ���� �����ϴ� �Լ� ����
	Node* newNode = (Node*)malloc(sizeof(Node));			// ���ο� ��� ����

	newNode->data = data;						// ����忡 ������ ����
	newNode->next = pstack->head;					// ��尡 ����Ű�� ��带 ����尡 ����Ų��

	pstack->head = newNode;						//��尡 ����带 ����Ű�� �Ͽ� �Ӹ��κп� ��带 �߰� ��Ų��.
}

Data SPop(Stack* pstack) {						// ���þ��� �����͸� �̾Ƴ��� �Լ� ����
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {						// ������ ��� �Ʒ� ������ �����Ű�� ���α׷� ����
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;					// ������ ����� �����͸� �ӽ÷� ����
	rnode = pstack->head;						// ������ ����� �ּ� ���� �ӽ÷� ����

	pstack->head = pstack->head->next;			// ������ ����� ���� ��带 head�� ����Ų��.
	free(rnode);								// ��带 ������

	return rdata;								// ������ ����� �����͸� ��ȯ
}

Data SPeek(Stack* pstack) {						// ���ÿ��� �ֻ����� ����Ǿ� �ִ� �����͸� Ȯ���ϴ� �Լ� ����
	if (SIsEmpty(pstack)) {						// ������ ��� �Ʒ� ������ �����Ű�� ���α׷� ����
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;					// head�� ����Ű�� �ֻ�� ��忡 ����� ������ ��ȯ
}