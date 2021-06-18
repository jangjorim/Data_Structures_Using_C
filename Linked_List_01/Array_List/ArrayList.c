#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {			//List 구조체의 주소를 plist로 받는다
	(plist->numOfData) = 0;				//구조체 주소로 접근하여 numOfData 변수에 0을 대입한다.			numOfData는 데이터의 수를 의미함
	(plist->curPosition) = -1;			// 구조체 주소로 접근하여 curPosition 변수에 -1을 대입한다.		curPosition은 데이터의 참조하는 위치를 의미함
}

void LInsert(List* plist, LData data) {			// 구조체 주소와 LData형 data를 받아온다
	if (plist->numOfData >= LIST_LEN) {			// 구조체로 접근하여 numOfData의 크기가 배열의 크기보다 같거나 커지면 실행한다.
		puts("저장이 불가능 합니다.");
		return;
	}
	plist->arr[plist->numOfData] = data;		// 구조체로 주소로 접근하여 arr배열에 numOfData의 크기 번째에 data를 저장한다.
	(plist->numOfData)++;						// numOfData의 값을 1 더해준다.
}

int LFirst(List* plist, LData* pdata) {			// 구조체 주소와 찾으려는 데이터를 저장할 변수의 주소를 입력받는다
	if (plist->numOfData == 0)					// 구조체의 numOfData로 접근해서 데이터가 없다면(0 이라면) FALSE(0)을 리턴한다.
		return FALSE;

	(plist->curPosition) = 0;					// 구조체의 curPosition에 0을 대입한다.
	*pdata = plist->arr[0];						// 찾으려는 데이터를 구조체 arr배열 0번째 에서 찾아 data 변수에 대입한다.
	return TRUE;								// TRUE(1)를 반환한다.
}

int LNext(List* plist, LData* pdata) {			// 구조체 주소와 데이터를 저장할 변수의 주소를 입력받는다.
	if (plist->curPosition >= (plist->numOfData) - 1)			// 구조체의 curPosition 멤버와 numOfData 멤버의 수를 비교하여 curPosition가 더 크다면 실행
		return FALSE;											// 0을 리턴함
	(plist->curPosition)++;										// 위의 조건이 아니라면 참조위치를 1더해준다.
	*pdata = plist->arr[plist->curPosition];					// 데이터를 저장할 변수에 arr[참조위치]에 있는 값을 대입한다.
	return TRUE;												// 1을 리턴함
}

LData LRemove(List* plist) {					// 구조체의 주소를 입력받는다.
	int rpos = plist->curPosition;				// 구조체 멤버의 참조 위치를 대입 받는다.
	int num = plist->numOfData;					// 구조체 멤버의 데이터 수를 대입 받는다.
	int i;
	LData rdata = plist->arr[rpos];				// LData형 변수에 구조체 멤버 arr[삭제참조위치] 의 값을 대입한다.

	for (i = rpos; i < num - 1; i++)			// 삭제하는 데이터 참조주소가 데이터의 수 -1 가 될 때까지 i가 1씩 증가한다.
		plist->arr[i] = plist->arr[i + 1];		// 앞에 데이터 주소에 한칸 뒤의 데이터를 저장하여 앞으로 데이터를 한칸씩 당긴다.

	(plist->numOfData)--;						// 데이터의 수를 1 줄인다.
	(plist->curPosition)--;						// 데이터의 참조위치를 1 되돌린다.
	return rdata;								// 삭제하는 데이터를 리턴한다.
}

int LCount(List* plist) {						// 구조체의 주소를 입력받는다.
	return plist->numOfData;					// 데이터의 수를 리턴한다.
}