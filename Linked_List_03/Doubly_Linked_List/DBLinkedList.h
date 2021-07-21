#pragma once
#ifndef __DB_LINKED_LIST_H__			// �� ������ ���� �ʵ��� ������ �ִ� ����
#define __DB_LINKED_LIST_H__

#define TRUE	1			// ��ũ�� ���� 
#define FALSE	0

typedef int Data;			// int ���� Data�� ����

typedef struct _node {		// ��� ����ü�� ����
	Data data;				// Data�� �����͸� ��� data ���� ���� 
	struct _node* next;		// ���� ����� �ּҸ� ����Ű�� _node�� ������ ���� ����
	struct _node* prev;		// ���� ����� �ּҸ� ����Ű�� _node�� ������ ���� ����
} Node;			// ����ü �̸��� Node�� �缱��

typedef struct _DLinkedList {			// ����� ���� ����Ʈ�� �����ϴ� ����ü ����
	Node* head;							// ����Ʈ�� �Ӹ��� ����Ű�� ���
	Node* cur;							// ����Ʈ���� ���� ��带 ����Ű�� ���
	int numOfData;						// ����� ����� ������ �����ϴ� ����
} DBLinkedList;							// ����ü �̸��� �缱��

typedef DBLinkedList List;				// ����ü �̸��� List�� �缱��

void ListInit(List* plist);					// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
void LInsert(List* plist, Data data);		// ����Ʈ�� ��带 �߰��ϴ� �Լ�

int LFirst(List* plist, Data* pdata);		// ����Ʈ Ž���� ó������ ����Ǵ� �Լ�
int LNext(List* plist, Data* pdata);		// ����Ʈ Ž���� LFirst �������� �����ϴ� �Լ�
int LPrevious(List* plist, Data data);		// LNext �Լ��� �ݴ� ������ ��带 �����ϴ� �Լ�
int LCount(List* plist);					// ����� ����� ������ ��ȯ �ϴ� �Լ�

#endif // !__DB_LINKED_LIST_H__
