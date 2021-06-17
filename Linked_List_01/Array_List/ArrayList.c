#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {			//List ����ü�� �ּҸ� plist�� �޴´�
	(plist->numOfData) = 0;				//����ü �ּҷ� �����Ͽ� numOfData ������ 0�� �����Ѵ�.
	(plist->curPosition) = -1;			// ����ü �ּҷ� �����Ͽ� curPosition ������ -1�� �����Ѵ�.
}

void LInsert(List* plist, LData data) {			// ����ü �ּҿ� LData�� data�� �޾ƿ´�
	if (plist->numOfData >= LIST_LEN) {			// ����ü�� �����Ͽ� numOfData�� ũ�Ⱑ �迭�� ũ�⺸�� ���ų� Ŀ���� �����Ѵ�.
		puts("������ �Ұ��� �մϴ�.");
		return;
	}
	plist->arr[plist->numOfData] = data;		// ����ü�� �ּҷ� �����Ͽ� arr�迭�� numOfData�� ũ�� ��°�� data�� �����Ѵ�.
	(plist->numOfData)++;						// numOfData�� ���� 1 �����ش�.
}

int LFirst(List* plist, LData* pdata) {			// ����ü �ּҿ� ã������ �����͸� ������ ������ �ּҸ� �Է¹޴´�
	if (plist->numOfData == 0)					// ����ü�� numOfData�� �����ؼ� 0�̶�� FALSE(0)�� �����Ѵ�.
		return FALSE;

	(plist->curPosition) = 0;					// ����ü�� curPosition�� 0�� �����Ѵ�.
	*pdata = plist->arr[0];						// ã������ �����͸� ����ü arr�迭 0��° ���� ã�� data ������ �����Ѵ�.
	return TRUE;								// TRUE(1)�� ��ȯ�Ѵ�.
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}