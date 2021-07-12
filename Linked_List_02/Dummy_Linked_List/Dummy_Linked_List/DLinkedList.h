#ifndef __D_LINKED_LIST_H__			// �� ������ ���� �ʵ��� ������ �ִ� ����
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData;			// int���� LData�� �� ����

typedef struct _node {			// ��� ����ü�� ����
	LData data;			// �����͸� �����ϴ� ���� ����
	struct _node* next;			// ���� ����� �ּҸ� ����Ű�� ������ ���� ����
} Node;			// Node�� �̸��� �缳��

typedef struct _linkedList {			// ���� ����Ʈ�� �����ϴ� ����ü�� ����
	Node* head;			// ���� ��带 ����Ű�� ����ü ���
	Node* cur;			// ���� �� ������ ���� ���
	Node* before;			// ������ ���� ���
	int nunOfData;			// ����� �������� ���� ����ϱ� ���� ���
	int(*comp)(LData d1, LData d2);			// ���� ������ ����ϱ� ���� ��� 
} LinkedList;			// ����ü �̸��� �缳��

typedef LinkedList List;			// ����ü �̸��� List�� �缳��

void ListInit(List* plist);			// ���� ����Ʈ �ʱ�ȭ �Լ�
void LInsert(List* plist, LData* pdata);			// ������ ���� �Լ�

int LFirst(List* plist, LData* pdata);			// ù ��° ������ ���� �Լ�
int LNext(List* plist, LData* pdata);			// �� ��° ���� ������ ���� �Լ�

LData LRemove(List* plist);			// ������ �����͸� �����ϴ� �Լ�
int LCount(List* plist);			// ����� ������ ���� ��ȯ �ϴ� �Լ�

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));			// ���� ������ �����ϴ� �Լ�

#endif // !1
