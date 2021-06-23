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
	LInsert(&list, ppos);							// LInsert 함수에 매계 변수로 list 구조체 주소와 구조체에 데이터가 들어 있는 구조체의 주소값을 넣어 준다.

	ppos = (Point*)malloc(sizeof(Point));			// Point 구조체 크기만큼 새로운 메모리를 할당한 Point 구조체 주소를 포인트 변수 ppos에 저장한다.
	SetPointPos(ppos, 2, 2);						// 새로 할당 받은 메모리 주소에 Point 멤버인 xpos에 2를 ypos에 2을 대입한다.
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	//저장된 데이터의 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));			// LCount 함수를 이용하여 현재 저장되어 있는 데이터의 수를 화면에 출력한다.

	if (LFirst(&list, &ppos)) {			// list 구조체로 접근해서 값이 있는지 확인하고 있다면 TRUE를 반환하여 아래 구문이 실행된다.
		ShowPointPos(ppos);			// 현재 데이터가 저장되어 있는 메모리 주소를 인자로 전달하여 현재 구조체 멤버의 값을 출력한다.

		while (LNext(&list, &ppos)) {			// 저장되어 있는 데이터를 전부 확인 할 때까지 구문이 실행된다.
			ShowPointPos(ppos);			// 현재 데이터가 저장 되어있는 메모리 주소로 접근해서 데이터가 있는 구조체 멤법의 값을 출력한다.
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