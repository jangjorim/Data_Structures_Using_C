#pragma once
#ifndef __C_LINKED_LIST_H__			// �� ������ ���� �ʵ��� ������ �ִ� ����
#define __C_LINKED_LIST_H__

#define TRUE	1			// ��ũ�� ���� 
#define FALSE	0

typedef int Data;			// int ���� Data�� ����

typedef struct _node {			// ��� ����ü�� ����
	Data data;			// Data�� �����͸� ��� data ���� ����
	struct _node* next;			// ���� ����� �ּҸ� ����Ű�� _node�� ������ ���� ����
}Node;			// ����ü �̸��� Node�� �缱��

typedef struct _CLL {			// ���� ���� ����Ʈ�� �����ϴ� ����ü�� ����
	Node* tail;			// ����Ʈ�� ������ ����Ű�� ���
	Node* cur;			// ���� ��带 ����Ű�� �ִ� ���
	Node* before;		// ���� ��忡�� �Ѵܰ� ������ ��带 ����Ű�� ���
	int numOfData;		// ����� ����� ������ �����ϴ� ����
} CList;				// ����ü �̸��� CList�� �缱��

typedef CList List;			// ����ü �̸��� List�� �� ����

void ListInit(List* plist);			// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
void LInsert(List* plist, Data data);			// ��带 ������ �߰��ϴ� �Լ�
void LInsertFront(List* plist, Data data);		// ��带 �Ӹ��� �߰��ϴ� �Լ�

int LFirst(List* plist, Data* pdata);			// ����Ʈ Ž���� ó������ ����Ǵ� �Լ�
int LNext(List* plist, Data* pdata);			// ����Ʈ Ž���� LFirst �������� �����ϴ� �Լ�
Data LRemove(List* plist);						// ���� ����Ű�� �ִ� ��带 �����ϴ� �Լ�
int LCount(List* plist);						// ���� ����Ʈ�� ����� ����� ������ ��ȯ �ϴ� �Լ�

#endif // !__C_LINKED_LIST_H__
