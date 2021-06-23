#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "ArrayList.h"

int main() {
	List list;			// list ����ü ����
	Point comPos;		// �񱳰��� ���� ����ü ���� ����
	Point* ppos;		// �����͸� ������ ����ü ������ ���� ����

	ListInit(&list);	// List�� �ʱ�ȭ�Ѵ�

	//4�� ������ ����
	ppos = (Point*)malloc(sizeof(Point));			// Point ����ü ũ�⸸ŭ �޸𸮸� �Ҵ��� Point ����ü �ּҸ� ����Ʈ ���� ppos�� �����Ѵ�.		
	SetPointPos(ppos, 2, 1);						// �Ҵ� ���� �޸� �ּҿ� Point ����� xpos�� 2�� ypos�� 1�� �����Ѵ�. 
	LInsert(&list, ppos);							// LInsert �Լ��� �Ű� ������ list ����ü �ּҿ� ����ü�� �����Ͱ� ��� �ִ� ����ü�� �ּҰ��� �־� �ش�.

	ppos = (Point*)malloc(sizeof(Point));			// Point ����ü ũ�⸸ŭ ���ο� �޸𸮸� �Ҵ��� Point ����ü �ּҸ� ����Ʈ ���� ppos�� �����Ѵ�.
	SetPointPos(ppos, 2, 2);						// ���� �Ҵ� ���� �޸� �ּҿ� Point ����� xpos�� 2�� ypos�� 2�� �����Ѵ�.
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	//����� �������� ���
	printf("���� �������� ��: %d \n", LCount(&list));			// LCount �Լ��� �̿��Ͽ� ���� ����Ǿ� �ִ� �������� ���� ȭ�鿡 ����Ѵ�.

	if (LFirst(&list, &ppos)) {			// list ����ü�� �����ؼ� ���� �ִ��� Ȯ���ϰ� �ִٸ� TRUE�� ��ȯ�Ͽ� �Ʒ� ������ ����ȴ�.
		ShowPointPos(ppos);			// ���� �����Ͱ� ����Ǿ� �ִ� �޸� �ּҸ� ���ڷ� �����Ͽ� ���� ����ü ����� ���� ����Ѵ�.

		while (LNext(&list, &ppos)) {			// ����Ǿ� �ִ� �����͸� ���� Ȯ�� �� ������ ������ ����ȴ�.
			ShowPointPos(ppos);			// ���� �����Ͱ� ���� �Ǿ��ִ� �޸� �ּҷ� �����ؼ� �����Ͱ� �ִ� ����ü ����� ���� ����Ѵ�.
		}
	}
	printf("\n");

	//xpos�� 2�� ��� ������ ����
	comPos.xpos = 2;
	comPos.ypos = 0;

	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &comPos) == 1) {
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &comPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// ������ ���� ������ ��ü ���
	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}