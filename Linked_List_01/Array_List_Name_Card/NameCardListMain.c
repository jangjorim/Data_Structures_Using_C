#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main() {
	List list;
	NameCard* pcard;			// NameCard 구조체 형으로 포인터pcard을 선언한다.
	ListInit(&list);			// list를 초기화 셋팅한다.
 
	pcard = MakeNameCard("이진수", "010-1111-2222");			// pcard 구조체에 MakeNameCard함수로 이름과 전화번호를 저장하였다 
	LInsert(&list, pcard);			// list에 값이 들어있는구조체 주소를 넘겨준다
	
	pcard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("이진수", "010-3333-7777");
	LInsert(&list, pcard);

	// 한지영의 정보를 조회하여 출력
	if (LFirst(&list, &pcard)) {			// 값의 구조체 주소가 들어 있는 list의 주소와 현재 데이터 값이들어있는 구조체 주소를 인자로 넘겨준다.
		if (!NameCompare(pcard, "한지영")) {			// 현재 값이 들어있는 구조체 주소와 찾는 데이터를 인자로 넘겨주고 값이 같으면 하위구문을 실행한다.
			ShowNameCardInfo(pcard);			// 현재 데이터의 값이 있는 구조체를 인자로 넘겨주어 이름과 전화번호를 출력해준다.
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "한지영")) {
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	// 이진수의 정보를 조회하여 변경
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "이진수")) {
			ChangePhoneNum(pcard, "010-9999-9999");			// 현재 데이터가 들어있는 구조체 주소와 바꿀려는 문자열 데이터를 인자로 넘겨준다(넘어갈때 주소로 넘어감)
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "이진수")) {
					ChangePhoneNum(pcard, "010-9999-9999");
					break;
				}
			}
		}
	}

	// 조수진의 정보를 조회하여 삭제
	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "조수진")) {
			pcard = LRemove(&list);			// 데이터가 있는 구조체 주소 값들이 있는 list주소를 넘겨주고 삭제할 데이터의 주소를 포인터 변수  pcard에 대입한다.
			free(pcard);			// 메모리 할당을 해지해 준다.
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "조수진")) {
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	// 모든 사람들의 정보 출력
	printf("현재 데이터 수 : %d \n", LCount(&list));			// 현재 list에 들어있는 값(데이터가 있는 구조체 주소의 개수)의 개수를 출력해준다.

	if (LFirst(&list, &pcard)) {			// list에 저장된 첫번째 값이 있으면 실행
		ShowNameCardInfo(pcard);			// 현재 데이터에 저장되어 있는 이름과 전화번호를 출력해서준다

		while (LNext(&list, &pcard))			// list에 저장된 두번째 값이 있으면 실행
			ShowNameCardInfo(pcard);
	}
	return 0;
}
