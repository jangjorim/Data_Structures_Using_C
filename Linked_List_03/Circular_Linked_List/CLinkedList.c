#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {			// ����Ʈ�� �ʱ�ȭ�ϴ� �Լ�
	plist->tail = NULL;					
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List* plist, Data data) {			// ����Ʈ �Ӹ��� ��带 �߰��ϴ� �Լ�
	Node* newNode = (Node*)malloc(sizeof(Node));			// �޸� ������ �Ҵ� �޾� �� ��带 ����
	newNode->data = data;			// �� ��忡 �����͸� ����

	if (plist->tail == NULL) {			// ���� ��尡 ����ִٸ�
		plist->tail = newNode;			// ���� ��带 �� ���� �Ѵ�.
		newNode->next = newNode;		// ���� ��� �ּҸ� ������ �ڽ����� �Ѵ�.
	}
	else {			// ���� ��尡 �ִٸ�
		newNode->next = plist->tail->next;			// �� ��� next�� ���� ����� next �ּҸ� �ִ´�.
		plist->tail->next = newNode;				// ���� ��� next�� �� ��� �ּҰ��� �ִ´�.
	}
	(plist->numOfData)++;			// ����� ��� ������ +1 ���ش�.
}

void LInsert(List* plist, Data data) {			// ����Ʈ ������ ��带 �߰��ϴ� �Լ�
	Node* newNode = (Node*)malloc(sizeof(Node));			// �޸� ������ �Ҵ� �޾� �� ��带 ����
	newNode->data = data;			// �� ��忡 �����͸� ����

	if (plist->tail == NULL) {			// ���� ��尡 ����ִٸ�
		plist->tail = newNode;			// ���� ��带 �� ���� �Ѵ�.
		newNode->next = newNode;		// ���� ��� �ּҸ� ������ �ڽ����� �Ѵ�.
	}
	else {			// ���� ��尡 �ִٸ�
		newNode->next = plist->tail->next;			// �� ��� next�� ���� ����� next �ּҸ� �ִ´�.
		plist->tail->next = newNode;				// ���� ��� next�� �� ��� �ּҰ��� �ִ´�.
		plist->tail = newNode;						// ���� ��带 �� ���� �����Ѵ�.
	}
	(plist->numOfData)++;			// ����� ��� ������ +1 ���ش�.
}

int LFirst(List* plist, Data* pdata) {			// ����Ʈ Ž���� ó���� ����Ǵ� �Լ�
	if (plist->tail == NULL)			// ��尡 �������� �ʴ´ٸ�
		return FALSE;					// 0�� ��ȯ�Ѵ�.

	plist->before = plist->tail;		// before�� ������ ����Ű�� �ϰ�
	plist->cur = plist->tail->next;		// cur�� �Ӹ��� ����Ű�� �Ѵ�.
	// �ᱹ before�� cur�� ���� tail��带 ����Ű���ִ�. //

	*pdata = plist->cur->data;			// cur�� ����Ű�� ����� �����͸� ��ȯ�Ѵ�.
	return TRUE;
}

int LNext(List* plist, Data* pdata) {			// ����Ʈ Ž���� LFirst ���ķ� ����Ǵ� �Լ�
	if (plist->tail == NULL)			// ��尡 �������� �ʴ´ٸ�
		return FALSE;					// 0�� ��ȯ�Ѵ�.

	plist->before = plist->cur;			// before�� ���� ��带 ����Ű�� �Ѵ�.
	plist->cur = plist->cur->next;		// cur�� ���� ��带 ����Ű�� �Ѵ�.

	*pdata = plist->cur->data;			// cur�� ����Ű�� ����� �����͸� ��ȯ�Ѵ�.
	return TRUE;
}

Data LRemove(List* plist) {				// ��带 �����ϴ� �Լ�
	Node* rpos = plist->cur;			// rpos�� cur�� ����Ű�� �Ѵ�.
	Data rdata = rpos->data;			// rdata�� rpos�� �����͸� �����Ѵ�.

	if (rpos == plist->tail) {			// ���� ����� tail�� ����Ų�ٸ�
		if (plist->tail == plist->tail->next)			// ������ ���� �����
			plist->tail = NULL;			// tail ��带 NULL�� �ʱ�ȭ �Ѵ�.
		else							// tail �̿ܿ� �ٸ� ��尡 �� �ִٸ�
			plist->tail = plist->before;			// tail�� before�� ����Ű�� �Ѵ�.
	}

	plist->before->next = plist->cur->next;			// before�� cur�� ����Ű�� ��带 ��ĭ�� �̵��Ѵ�.
 	plist->cur = plist->before;						// cur�� before�� ����Ű�� �Ѵ�.

	free(rpos);			// �޸� �Ҵ��� �����Ѵ�.
	(plist->numOfData)--;			// ����� ����� ������ -1�Ѵ�.
	return rdata;					// ������ ������ ���� ��ȯ�Ѵ�.
}

int LCount(List* plist) {			// ���� ����� ����� ������ ��ȯ�ϴ� �Լ�
	return plist->numOfData;		
}