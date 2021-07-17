#include <stdio.h>
#include "DLinkedList.h"

int main() {
	List list;			// 리스트를 생성
	int data;
	ListInit(&list);			// 초기화를 진행

	LInsert(&list, 11); LInsert(&list, 11);			// 데이터를 저장
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수: %d \n", LCount(&list));			// 저장된 데이터 갯수를 출력

	if (LFirst(&list, &data)) {			// 저장되어 있는 값중 첫 번째 데이터가 있는지 확인하고 
		printf("%d ", data);			// 있다면 화면에 출력한다.

		while (LNext(&list, &data))			// 두 번쨰 이후로도 데이터가 있다면 마지막 데이터까지
			printf("%d ", data);			// 화면에 출력해 준다.
	}
	printf("\n\n");

	if (LFirst(&list, &data)) {			// 저장되어 있는 첫 번째 노드의 데이터 값을 확인
		if (data == 22)			// 값이 22라면 
			LRemove(&list);			// 데이터를 삭제함
		while (LNext(&list, &data)) {			// 저장되어 있는 두 번째 노드 이후의 값을 확인
			if (data == 22)			// 값이 22라면
				LRemove(&list);			// 데이터를 삭제함
		}
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));			// 저장되어있는 데이터 갯수를 출력

	if (LFirst(&list, &data)) {			// 저장되어 있는 값중 첫 번째 데이터가 있는지 확인하고 
		printf("%d ", data);			// 있다면 화면에 출력한다.

		while (LNext(&list, &data))			// 두 번쨰 이후로도 데이터가 있다면 마지막 데이터까지
			printf("%d ", data);			// 화면에 출력해 준다.
	}
	
	printf("\n\n");
	return 0;
}
