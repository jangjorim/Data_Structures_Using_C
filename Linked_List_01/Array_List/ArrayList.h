#ifndef __ARRAY_LIST_H__			//��� ������ ����� �� ���� ���� �� �������� �ȵǰ� �ϱ� ���� ���� �Ǿ���.
#define __ARRAY_LIST_H__

#define TRUE 1			//������ ǥ���ϱ� ���� ��ũ�� ����
#define FALSE 0			//�������� ǥ���ϱ� ���� ��ũ�� ����

#define LIST_LEN 100	//����Ʈ�� ũ�⸦ ���ϴ� ��ũ�� ����
typedef int LData;		//int ���� LData��� �̸����� ����

typedef struct __ArrayList {			// �迭 ��� ����Ʈ�� ������ ����ü
	LData arr[LIST_LEN];				// ����Ʈ ���� �迭 ������ 100
	int numOfData;						// ����� �������� ���� ����ϴ� ����
	int curPosition;					// �������� ������ġ�� ����ϴ� ����
} ArrayList;

typedef ArrayList List;					// ArrayList ����ü�� List �̸����� ����

void ListInit(List* plist);				// �ʱ�ȭ �Լ�
void LInsert(List* plist, LData data);	// ������ ���� �Լ�

int LFirst(List* plist, LData* pdata);	// ù ������ ���� �Լ�
int LNext(List* plist, LData* pdata);	// �ι�° ���� ������ ���� �Լ�

LData LRemove(List* plist);				// ������ ������ ���� �Լ�
int LCount(List* plist);				// ����� �������� �� ��ȯ �Լ�

#endif