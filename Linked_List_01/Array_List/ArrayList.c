#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {			//List 구조체의 주소를 plist로 받는다
	(plist->numOfData) = 0;				//구조체 주소로 접근하여 numOfData 변수에 0을 대입한다.
	(plist->curPosition) = -1;			// 구조체 주소로 접근하여 curPosition 변수에 -1을 대입한다.
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
	if (plist->numOfData == 0)					// 구조체의 numOfData로 접근해서 0이라면 FALSE(0)을 리턴한다.
		return FALSE;

	(plist->curPosition) = 0;					// 구조체의 curPosition에 0을 대입한다.
	*pdata = plist->arr[0];						// 찾으려는 데이터를 구조체 arr배열 0번째 에서 찾아 data 변수에 대입한다.
	return TRUE;								// TRUE(1)를 반환한다.
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}