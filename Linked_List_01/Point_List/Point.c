#include <stdio.h>
#include "Point.h"			// 선언한 구조체와 함수를 사용하기 위해 포함한다.

void SetPointPos(Point* ppos, int xpos, int ypos) {			// 구조체 주소와 값을 설정하기 위해 변수를 받는다.
	ppos->xpos = xpos;			// Point 멤버인 xpos에 입력받은 xpos 값을 대입한다.
	ppos->ypos = ypos;			// Point 멤버인 ypos에 입력받은 ypos 값을 대입한다.
}

void ShowPointPos(Point* ppos) {			// 사용할 구조체 주소를 받는다.
	printf("[%d, %d] \n", ppos->xpos, ppos->ypos);			// 현재 Point 구조체 멤버의 값을 화면에 출력해준다.
}

int PointComp(Point* pos1, Point* pos2) {			// 두 Point 구조체 주소를 입력받는다.
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)			// 첫 번째와 두 번쨰 구조체 멤버의 값이 모두 같으면 0을 반환한다.
		return 0;
	else if (pos1->xpos == pos2->xpos)				// 두 Point 구조체 멤버중 xpos의 값이 서로 같으면 1을 반환한다.
		return 1;
	else if (pos1->ypos == pos2->ypos)				// 두 Point 구조체 멤버중 ypos의 값이 서로 같으면 2를 반환한다.
		return 2;
	else											// 두 Point 구조체 멤버의 값이 모두 서로 같지 않으면 -1를 반환한다.
		return -1;
}