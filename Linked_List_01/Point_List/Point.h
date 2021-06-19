#ifndef __POINT_H__			// ó������ �Ʒ� __POINT_H__�� ���� �Ǿ����� �ʱ� ������ endif������ ������ �����Ѵ�. �ߺ� �������� �����Ѵ�.
#define __POINT_H__

typedef struct _point {		// _point �̸����� ����ü�� �����Ѵ�.
	int xpos;				// ����
	int ypos;
}Point;						// Point ��� �̸����� ������ �Ѵ�.

// Point ����ü ����� xpos, ypos ���� �����ϴ� �Լ� ����
void SetPointPos(Point* ppos, int xpos, int ypos);

// Point ����ü ����� xpos, ypos ������ ����ϴ� �Լ� ����
void ShowPointPos(Point* ppos);

// �� Point ����ü ����� ��
int PointComp(Point* pos1, Point* pos2);

#endif