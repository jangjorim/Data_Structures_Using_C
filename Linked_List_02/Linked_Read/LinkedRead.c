#include <stdio.h>
#include <stdlib.h>

typedef struct _node {			// _node ��� �̸��� ����ü�� ����
	int data;			// ����� �����͸� �����ϴ� ����
	struct _node* next;			// ���� ����� �ּҸ� �����ϴ� ������ ����
} Node;			// typedef�� Node��� �̸����� ����ü �̸��� �缳�� �Ѵ�.

int main() {
	Node* head = NULL;			// ���Ḯ��Ʈ�� �Ӹ��� ����Ű�� ������ �ּҸ� ��� ����
	Node* tail = NULL;			// ���Ḯ��Ʈ�� ������ ����Ű�� ������ �ּҸ� ��� ����
	Node* cur = NULL;			// ���Ḯ��Ʈ�� ����� �����͸� ��ȸ�ϴµ� ���Ǵ� ����

	Node* newNode = NULL;			// ���ο� ����� �ּҸ� ��� ������ ����
	int readData;			// �Է¹޴� �����͸� �����ϴ� ����

	// �����͸� �Է� �޴� ���� //
	while (1) {
		printf("�ڿ��� �Է�: ");
		scanf_s("%d", &readData);			// ���� �Է¹ޱ�
		if (readData < 1)			// �Էµ� ���� 1���� ������ while���� �����.
			break;

		// ����� �߰�����
		newNode = (Node*)malloc(sizeof(Node));			// ���ο� ��带 �Ҵ��Ѵ�.
		newNode->data = readData;			// ����� �����Ϳ� �Է� ���� ���� �����Ѵ�.
		newNode->next = NULL;			// ���ҵ� ������ �̾�����(�����ؾ��ϴ�) ���� �ּҴ� ���������.

		if (head == NULL)			// ���Ḯ��Ʈ�� �Ӹ��� ����Ű�� �ּҰ� ����ִٸ�
			head = newNode;			// �ص忡 ����尡 �ִ� �ּҰ��� �ִ´�.
		else
			tail->next = newNode;			// �׷��� �ʴٸ� ���Ḯ��Ʈ�� ������ �κ��� ����Ű�� tail�� ������� �ּҰ��� �ִ´�.

		tail = newNode;			// tail�� ���ο� ����� �ּҰ��� �ִ´�.
	}
	printf("\n");

	// �Է� ���� �������� ��°��� //
	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL) {
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);			// ù ��° ������ ���

		while (cur->next != NULL) {			// �� ���� ������ ������ ���
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// �޸� �������� //
	if (head == NULL) {
		return 0;			// ������ ��尡 �������� �ʴ´�.
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);			// ù ��° ��� ����

		while (delNextNode != NULL) {			// ù ��° ��� ����
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}