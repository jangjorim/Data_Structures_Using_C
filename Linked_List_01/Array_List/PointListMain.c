#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "ArrayList.h"

int main() {
	List list;			// list 구조체 선언
	Point comPos;		// 비교값을 담을 구조체 변수 선언
	Point* ppos;		// 데이터를 저장할 구조체 포인터 변수 선언

	ListInit(&list);	// List를 초기화한다

	//4개 데이터 저장
	ppos = (Point*)malloc(sizeof(Point));			// Point 구조체 크기만큼 메모리를 할당한 Point 구조체 주소를 포인트 변수 ppos에 저장한다.		
	SetPointPos(ppos, 2, 1);						// 할당 받은 메모리 주소에 Point 멤버인 xpos에 2를 ypos에 1을 대입한다. 
	LInsert(&list, ppos);							// list 구조체에 데이터가 들어 있는 구조체의 주소값을 넣어 준다.

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	//저장된 데이터의 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	printf("\n");

	//xpos가 2인 모든 데이터 삭제
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

	// 삭제후 남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}