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
	comPos.xpos = 2;			// 삭제할 데이터를 Point 구조체의 멤버에 저장하였다.
	comPos.ypos = 0;

	if (LFirst(&list, &ppos)) {			// 데이터가 들어있는 구조체 주소와 현재 데이터가 들어있는 구조체 주소를 인자로 전달한다.
		if (PointComp(ppos, &comPos) == 1) {			// 현재 메모리 주소에 담겨있는 주소와 삭제할 데이터가 있는 구조체 주소를 함수의 인자로 받아 xpos의 값이 서로 같다면 1을 반환하므로 참이된다.
			ppos = LRemove(&list);			// 삭제할 데이터가 있는 곳의 주소를 대입받는다.
			free(ppos);			// 할당된 메모리를 해제해준다.
		}

		while (LNext(&list, &ppos)) {			// 데이터가 들어있는 구조체 주소와 현재 데이터가 들어있는 구조체 주소를 인자로 전달한다.
			if (PointComp(ppos, &comPos) == 1) {			// 현재 메모리 주소에 담겨있는 주소와 삭제할 데이터가 있는 구조체 주소를 함수의 인자로 받아 xpos의 값이 서로 같다면 1을 반환하므로 참이되어 아래 구문을 실행한다.
				ppos = LRemove(&list);			// 삭제할 데이터가 있는 곳의 주소를 대입받는다.
				free(ppos);			// 할당된 메모리를 해제해준다.
			}
		}
	}

	// 삭제후 남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {			// 데이터가 들어있는 구조체 주소와 현재 데이터를 가지고 있는 메모리 주소를 인자로 넘겨준다.
		ShowPointPos(ppos);			// 현재 데이터 값을 화면에 출력해 준다.

		while (LNext(&list, &ppos))			// 데이터가 들어 있는 구조체 주소와 현재 데이터를 가지고 있는 메모리 주소를 인자로 전달하여 마지막 데이터 까지 검사하고 검사가 끝나기 전까지 계속 실행된다.
			ShowPointPos(ppos);			// 현제 데이터의 값을 화면에 출력해 준다.
	}
	printf("\n");

	return 0;
}