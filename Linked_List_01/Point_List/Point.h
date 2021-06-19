#ifndef __POINT_H__			// 처음에는 아래 __POINT_H__가 정의 되어있지 않기 때문에 endif까지의 구문을 실행한다. 중복 컴파일을 방지한다.
#define __POINT_H__

typedef struct _point {		// _point 이름으로 구조체를 정의한다.
	int xpos;				// 변수
	int ypos;
}Point;						// Point 라는 이름으로 재정의 한다.

// Point 구조체 멤버의 xpos, ypos 값을 설정하는 함수 선언
void SetPointPos(Point* ppos, int xpos, int ypos);

// Point 구조체 멤버의 xpos, ypos 정보를 출력하는 함수 선언
void ShowPointPos(Point* ppos);

// 두 Point 구조체 멤버의 비교
int PointComp(Point* pos1, Point* pos2);

#endif