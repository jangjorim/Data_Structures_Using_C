#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist) {			// ����Ʈ �ʱ�ȭ�� �ϴ� �Լ�
	plist->head = (Node*)malloc(sizeof(Node));			// ���� ��带 ����
	plist->head->next = NULL;			// ���� ��� ���� ���� NULL ������ ����
	plist->comp = NULL;			// 
	plist->nunOfData = 0;			// ����� �������� ������ 0���� ����
}

void FInsert(List*plist, LData data) {			// ���� ������ ������ �����͸� ������ �� ����ϴ� �Լ�
	Node * newNode = (Node*)malloc(sizeof(Node));			// �� ��带 ������
	newNode->data = data;			// �� ��忡 �����͸� ������

	newNode->next = plist->head->next;			// �� ��尡 ������ ���̳�尡 ����Ű�� ��带 ����Ŵ
	plist->head->next = newNode;			// ���� ��尡 �� ��带 ����Ű�� ��

	(plist->nunOfData)++;			// ������ ������ 1 ������
}

void SInsert(List * plist, LData data) {			// ���� ������ ������ �����͸� �����ϴ� �Լ�
	Node * newNode = (Node*)malloc(sizeof(Node));			// �� ��带 ������
	Node * pred = plist->head;			// pred�� ���� ��带 ����Ű�� ��
	newNode->data = data;			// �� ��忡 �����͸� ����


	// pred�� ����Ʈ�� ������ ��带 ����Ű�� �����鼭
	// �� �����Ϳ� pred ������ ��忡 ����� �������� �켱������ Ȯ���Ͽ� ��ȯ ���� 0�� �ƴ϶�� �Ʒ� ������ ��� ������
	while (pred->next != NULL && plist->comp(data, pred->next->next) != 0) {
		pred = pred->next;			// ���� ���� �̵�
	}

	newNode->next = pred->next;			//�� ����� �������� ������
	pred->next = newNode;			// �� ����� ������ ������

	(plist->nunOfData)++;			// ����� �������� ���� 1 ������
}

void LInsert(List * plist, LData data) {			// �����͸� �Է��ϴ� �Լ�
	if (plist->comp == NULL)			// ���� ������ ���ٸ� FInsert �Լ��� ���� �Ͽ� �Ӹ��� ��带 �߰�
		FInsert(plist, data);
	else
		SInsert(plist, data);			// ���� ������ �ִٸ� SInsert �Լ��� ����
}

int LFirst(List * plist, LData * pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist) {
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->nunOfData)--;
	return rdata;
}

int LCount(List * plist) {
	return plist->nunOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}

