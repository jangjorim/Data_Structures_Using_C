#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone) {			// NameCard 구조체형으로 함수를 선언 한다.
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));			// NameCard 구조체 크기만큼의 메모리 공간을 할당하고 주소를 newCard 포인터 변수에 삽입한다.
	strcpy(newCard->name, name);			// 함수 인자로 들어온 name 주소값을 newCard 주소 값으로 이동해 NameCard 멤버 변수 name에 복사한다.
	strcpy(newCard->phone, phone);			// 함수 인자로 들어온 phone 주소값을 newCard 주소 값으로 이동해 NameCard 멤버 변수인 phone에 복사한다.
	return newCard;			// NameCard 구조체 주소가 들어있는 newCard 를 반환한다.
}

void ShowNameCardInfo(NameCard* pcard) {			// NameCard 구조체 주소를 인자로 받는다.
	printf("[이름] %s \n", pcard->name);				// 구조체 주소에 접근하여 NameCard 멤버 변수인 name의 값을 출력해준다.
	printf("[번호] %s \n\n", pcard->phone);			// 구조체 주소에 접근하여 NameCard 멤버 변수인 phone의 값을 출력해 준다.
}

int NameCompare(NameCard* pcard, char* name) {			// 비교할 데이터가 있는 구조체 주소와 찾는 문자열이 있는 변수의 주소를 인자로 입력 받는다.
	return strcmp(pcard->name, name);			// strcmp()함수를 이용하여 비교하는 데이터가 찾는 데이터와 같으면 0 다르면 0이아닌 다른값을 반환다한다.
}

void ChangPhoneNum(NameCard* pcard, char* phone) {			// 바꾸려고 하는 데이터가 있는 구조체 주소와 바꾸는 문자열 데이터 값이 있는 변수 주소를 인자로 입력 받는다.
	strcpy(pcard->phone, phone);			// stcpy() 함수를 이용해 새로운 문자열 데이터가 들어있는 주소를 바꾸려는 데이터가 있는 주소에 값을 복사에서 넣는다.
}