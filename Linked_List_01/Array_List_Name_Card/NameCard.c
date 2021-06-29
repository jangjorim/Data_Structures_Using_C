#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone) {			// NameCard ����ü������ �Լ��� ���� �Ѵ�.
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));			// NameCard ����ü ũ�⸸ŭ�� �޸� ������ �Ҵ��ϰ� �ּҸ� newCard ������ ������ �����Ѵ�.
	strcpy(newCard->name, name);			// �Լ� ���ڷ� ���� name �ּҰ��� newCard �ּ� ������ �̵��� NameCard ��� ���� name�� �����Ѵ�.
	strcpy(newCard->phone, phone);			// �Լ� ���ڷ� ���� phone �ּҰ��� newCard �ּ� ������ �̵��� NameCard ��� ������ phone�� �����Ѵ�.
	return newCard;			// NameCard ����ü �ּҰ� ����ִ� newCard �� ��ȯ�Ѵ�.
}

void ShowNameCardInfo(NameCard* pcard) {			// NameCard ����ü �ּҸ� ���ڷ� �޴´�.
	printf("[�̸�] %s \n", pcard->name);				// ����ü �ּҿ� �����Ͽ� NameCard ��� ������ name�� ���� ������ش�.
	printf("[��ȣ] %s \n\n", pcard->phone);			// ����ü �ּҿ� �����Ͽ� NameCard ��� ������ phone�� ���� ����� �ش�.
}

int NameCompare(NameCard* pcard, char* name) {			// ���� �����Ͱ� �ִ� ����ü �ּҿ� ã�� ���ڿ��� �ִ� ������ �ּҸ� ���ڷ� �Է� �޴´�.
	return strcmp(pcard->name, name);			// strcmp()�Լ��� �̿��Ͽ� ���ϴ� �����Ͱ� ã�� �����Ϳ� ������ 0 �ٸ��� 0�̾ƴ� �ٸ����� ��ȯ���Ѵ�.
}

void ChangPhoneNum(NameCard* pcard, char* phone) {			// �ٲٷ��� �ϴ� �����Ͱ� �ִ� ����ü �ּҿ� �ٲٴ� ���ڿ� ������ ���� �ִ� ���� �ּҸ� ���ڷ� �Է� �޴´�.
	strcpy(pcard->phone, phone);			// stcpy() �Լ��� �̿��� ���ο� ���ڿ� �����Ͱ� ����ִ� �ּҸ� �ٲٷ��� �����Ͱ� �ִ� �ּҿ� ���� ���翡�� �ִ´�.
}