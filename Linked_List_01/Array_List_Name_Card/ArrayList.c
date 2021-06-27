#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {			//List ����ü�� �ּҸ� plist�� �޴´�
	(plist->numOfData) = 0;				//����ü �ּҷ� �����Ͽ� numOfData ������ 0�� �����Ѵ�.			numOfData�� �������� ���� �ǹ���
	(plist->curPosition) = -1;			// ����ü �ּҷ� �����Ͽ� curPosition ������ -1�� �����Ѵ�.		curPosition�� �������� �����ϴ� ��ġ�� �ǹ���
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
	if (plist->numOfData == 0)					// ����ü�� numOfData�� �����ؼ� �����Ͱ� ���ٸ�(0 �̶��) FALSE(0)�� �����Ѵ�.
		return FALSE;

	(plist->curPosition) = 0;					// ����ü�� curPosition�� 0�� �����Ѵ�.
	*pdata = plist->arr[0];						// ã������ �����͸� ����ü arr�迭 0��° ���� ã�� data ������ �����Ѵ�.
	return TRUE;								// TRUE(1)�� ��ȯ�Ѵ�.
}

int LNext(List* plist, LData* pdata) {			// ����ü �ּҿ� �����͸� ������ ������ �ּҸ� �Է¹޴´�.
	if (plist->curPosition >= (plist->numOfData) - 1)			// ����ü�� curPosition ����� numOfData ����� ���� ���Ͽ� curPosition�� �� ũ�ٸ� ����
		return FALSE;											// 0�� ������
	(plist->curPosition)++;										// ���� ������ �ƴ϶�� ������ġ�� 1�����ش�.
	*pdata = plist->arr[plist->curPosition];					// �����͸� ������ ������ arr[������ġ]�� �ִ� ���� �����Ѵ�.
	return TRUE;												// 1�� ������
}

LData LRemove(List* plist) {					// ����ü�� �ּҸ� �Է¹޴´�.
	int rpos = plist->curPosition;				// ����ü ����� ���� ��ġ�� ���� �޴´�.
	int num = plist->numOfData;					// ����ü ����� ������ ���� ���� �޴´�.
	int i;
	LData rdata = plist->arr[rpos];				// LData�� ������ ����ü ��� arr[����������ġ] �� ���� �����Ѵ�.

	for (i = rpos; i < num - 1; i++)			// �����ϴ� ������ �����ּҰ� �������� �� -1 �� �� ������ i�� 1�� �����Ѵ�.
		plist->arr[i] = plist->arr[i + 1];		// �տ� ������ �ּҿ� ��ĭ ���� �����͸� �����Ͽ� ������ �����͸� ��ĭ�� ����.

	(plist->numOfData)--;						// �������� ���� 1 ���δ�.
	(plist->curPosition)--;						// �������� ������ġ�� 1 �ǵ�����.
	return rdata;								// �����ϴ� �����͸� �����Ѵ�.
}

int LCount(List* plist) {						// ����ü�� �ּҸ� �Է¹޴´�.
	return plist->numOfData;					// �������� ���� �����Ѵ�.
}