#include <stdio.h>
#include "DBLinkedList.h"			// ������ �ش������� ���

int main() {

	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// 8���� �����͸� ����
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	// ����� �����͸� ��ȸ �Ͽ� ȭ�鿡 ���
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		// ������ ���� �̵��ϸ鼭 ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		// ���� ���� �̵��ϸ鼭 ������ ��ȸ
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}
	return 0;
}