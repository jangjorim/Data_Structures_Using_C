#include <stdio.h>
#include "DLinkedList.h"

int main() {
	List list;			// ����Ʈ�� ����
	int data;
	ListInit(&list);			// �ʱ�ȭ�� ����

	LInsert(&list, 11); LInsert(&list, 11);			// �����͸� ����
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("���� �������� ��: %d \n", LCount(&list));			// ����� ������ ������ ���

	if (LFirst(&list, &data)) {			// ����Ǿ� �ִ� ������ ���� ���� ���
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data)) {			// ����Ǿ� �ִ� ù ��° ����� ������ ���� Ȯ��
		if (data == 22)			// ���� 22��� 
			LRemove(&list);			// �����͸� ������
		while (LNext(&list, &data)) {			// ����Ǿ� �ִ� �� ��° ��� ������ ���� Ȯ��
			if (data == 22)			// ���� 22���
				LRemove(&list);			// �����͸� ������
		}
	}

	printf("���� �������� ��: %d \n", LCount(&list));			// ����Ǿ��ִ� ������ ������ ���

	if (LFirst(&list, &data)) {			// ����Ǿ��ִ� ��� �����͸� ȭ�鿡 �����
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}