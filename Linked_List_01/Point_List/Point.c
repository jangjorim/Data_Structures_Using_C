#include <stdio.h>
#include "Point.h"			// ������ ����ü�� �Լ��� ����ϱ� ���� �����Ѵ�.

void SetPointPos(Point* ppos, int xpos, int ypos) {			// ����ü �ּҿ� ���� �����ϱ� ���� ������ �޴´�.
	ppos->xpos = xpos;			// Point ����� xpos�� �Է¹��� xpos ���� �����Ѵ�.
	ppos->ypos = ypos;			// Point ����� ypos�� �Է¹��� ypos ���� �����Ѵ�.
}

void ShowPointPos(Point* ppos) {			// ����� ����ü �ּҸ� �޴´�.
	printf("[%d, %d] \n", ppos->xpos, ppos->ypos);			// ���� Point ����ü ����� ���� ȭ�鿡 ������ش�.
}

int PointComp(Point* pos1, Point* pos2) {			// �� Point ����ü �ּҸ� �Է¹޴´�.
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)			// ù ��°�� �� ���� ����ü ����� ���� ��� ������ 0�� ��ȯ�Ѵ�.
		return 0;
	else if (pos1->xpos == pos2->xpos)				// �� Point ����ü ����� xpos�� ���� ���� ������ 1�� ��ȯ�Ѵ�.
		return 1;
	else if (pos1->ypos == pos2->ypos)				// �� Point ����ü ����� ypos�� ���� ���� ������ 2�� ��ȯ�Ѵ�.
		return 2;
	else											// �� Point ����ü ����� ���� ��� ���� ���� ������ -1�� ��ȯ�Ѵ�.
		return -1;
}