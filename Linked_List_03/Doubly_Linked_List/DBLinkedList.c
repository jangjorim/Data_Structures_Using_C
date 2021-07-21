#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) {			// ����Ʈ�� �ʱ�ȭ�ϴ� �Լ� ����
	plist->head = NULL;					// �Ӹ��� ������´�.
	plist->numOfData = 0;				// ����� ����� ������ 0���� �ʱ�ȭ �Ѵ�.
}

void LInsert(List* plist, Data data) {			// ����Ʈ�� ��带 �����ϴ� �Լ� ����
	Node* newNode = (Node*)malloc(sizeof(Node));			// �� ��忡 �޸� �Ҵ��� ���ش�
	newNode->data = data;									// �� ��忡 �����͸� �����Ѵ�.

	newNode->next = plist->head;							// �� ��� next�� head�� ����Ų��.
	if (plist->head != NULL)								// ���� �ص尡 NULL �̶��
		plist->head->prev = newNode;						// �ص��� prev�� �� ��带 ����Ų��.

	newNode->prev = NULL;									// �� ����� prev�� NULL�� ����Ų��.
	plist->head = newNode;									// head�� �� ��带 ����Ų��.

	(plist->numOfData)++;									// ��� ������ +1 ���ش�.
}

int LFirst(List* plist, Data* pdata) {			// ����Ʈ�� ó���� Ž���� �� ����ϴ� �Լ� ����
	if (plist->head == NULL)					// ���� ����Ʈ�� ����ִٸ�
		return FALSE;							// 0�� ��ȯ �Ѵ�.
	
	plist->cur = plist->head;					// ���� ����Ű�� ��带 head�� �����Ѵ�.
	*pdata = plist->cur->data;					// ���� ����Ű�� ����� �����͸� �����Ѵ�.

	return TRUE;								// 1�� ��ȯ �Ѵ�.
}

int LNext(List* plist, Data* pdata) {			// ����Ʈ�� Ž�� �� �� LFirst �������� ����ϴ� �Լ� ����
	if (plist->cur->next == NULL)				// ���� ���� ��尡 ���ٸ�
		return FALSE;							// 0�� ��ȯ

	plist->cur = plist->cur->next;				// ����Ű�� �ִ� ��带 ���� ���� ��ĭ �̵��Ѵ�.
	*pdata = plist->cur->data;					// ���� ����Ű�� ����� �����͸� �����Ѵ�.

	return TRUE;								// 1�� ��ȯ�Ѵ�.
}

int LPrevious(List* plist, Data* pdata) {		// LNext �Լ��� �ݴ� ������ ��带 �����ϴ� �Լ� ����
	if (plist->cur->prev == NULL)				// ���� ���� ��尡 ���ٸ� 
		return FALSE;							// 0�� ��ȯ
	
	plist->cur = plist->cur->prev;				// ���� ����Ű�� ��带 ���� ���� ��ĭ �̵�
	*pdata = plist->cur->data;					// ���� ����Ű�� ����� �����͸� ����

	return TRUE;								// 1�� ��ȯ
}

int LCount(List* plist) {						// ����� ����� ������ ��ȯ �ϴ� �Լ�
	return plist->numOfData;
}