#include <stdio.h>
#include "ArrayList.h"

int main() {
	//ArrayList의 생성 및 초기화 //
	List list;			// List 구조체 생성
	int data;
	ListInit(&list);	// List 초기화

	// 5개의 데이터 저장 //
	// List에 11, 11, 22, 22, 33 데이터를 저장 
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33); 

	// 저장된 데이터의 전체 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) {			// 첫 번째 데이터가 있으면 TRUE 없으면 FALSE를 반환
		printf("%d ", data);			// 첫 번째 데이터가 있다면 data에 arr배열 첫번째 값을 대입

		while (LNext(&list, &data))		// 두 번째 이후의 데이터가 있는지 확인하고 데이터가 들어 있는 배열의 마지막 부분까지 검색
			printf("%d ", data);		// 두 번째 이후 데이터가 있다면 data에 순차적으로 arr배열에 있는 값을 대입
	}
	printf("\n\n");

	// 숫자 22을 탐색하여 모두 삭제 //
	if (LFirst(&list, &data))			// 첫 번째 데이터가 있다면 실행
	{
		if (data == 22)					// 첫 번째 데이터가 만약 22라면 삭제
			LRemove(&list);

		while (LNext(&list, &data))		// 두 번째 이후 데이터를 확인하고 값이 들어 있는 배열의 마지막까지 검색
		{
			if (data == 22)				// 두 번째 이후 데이터를 검색하는중 만약 값이 22라면 삭제
				LRemove(&list);
		}
	}

	// 삭제 후 저장되어 있는 데이터 개수 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

	//arr배열에 남아있는 데이터를 확인하고 출력--------------
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	//----------------------------------------------------
	printf("\n\n");
	return 0;
}




