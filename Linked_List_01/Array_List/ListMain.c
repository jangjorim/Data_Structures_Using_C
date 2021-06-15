#include <stdio.h>
#include "ArrayList.h"

int main() {
	//ArrayList�� ���� �� �ʱ�ȭ //
	List list;			// List ����ü ����
	int data;
	ListInit(&list);	// List �ʱ�ȭ

	// 5���� ������ ���� //
	// List�� 11, 11, 22, 22, 33 �����͸� ���� 
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33); 

	// ����� �������� ��ü ��� //
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {			// ù ��° �����Ͱ� ������ TRUE ������ FALSE�� ��ȯ
		printf("%d ", data);			// ù ��° �����Ͱ� �ִٸ� data�� arr�迭 ù��° ���� ����

		while (LNext(&list, &data))		// �� ��° ������ �����Ͱ� �ִ��� Ȯ���ϰ� �����Ͱ� ��� �ִ� �迭�� ������ �κб��� �˻�
			printf("%d ", data);		// �� ��° ���� �����Ͱ� �ִٸ� data�� ���������� arr�迭�� �ִ� ���� ����
	}
	printf("\n\n");

	// ���� 22�� Ž���Ͽ� ��� ���� //
	if (LFirst(&list, &data))			// ù ��° �����Ͱ� �ִٸ� ����
	{
		if (data == 22)					// ù ��° �����Ͱ� ���� 22��� ����
			LRemove(&list);

		while (LNext(&list, &data))		// �� ��° ���� �����͸� Ȯ���ϰ� ���� ��� �ִ� �迭�� ���������� �˻�
		{
			if (data == 22)				// �� ��° ���� �����͸� �˻��ϴ��� ���� ���� 22��� ����
				LRemove(&list);
		}
	}

	// ���� �� ����Ǿ� �ִ� ������ ���� ��� //
	printf("���� �������� ��: %d \n", LCount(&list));

	//arr�迭�� �����ִ� �����͸� Ȯ���ϰ� ���--------------
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	//----------------------------------------------------
	printf("\n\n");
	return 0;
}




