#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
//#include "ArrayList.h"

int main() {
	List list;
	Point comPos;
	Point* ppos;

	ListInit(&list);

	//4�� ������ ����
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	Linsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	Linsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	Linsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	Linsert(&list, ppos);

	//����� �������� ���
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos)) {
			ShowPointPos(ppos);
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
			if(PointComp(ppos, &comPos) == 1) {
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