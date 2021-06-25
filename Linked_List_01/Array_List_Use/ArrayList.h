#ifndef __ARRAY_LIST_H__			//헤더 파일을 사용할 때 이중 포함 및 컴파일이 안되게 하기 위해 선언 되었다.
#define __ARRAY_LIST_H__

#define TRUE 1			//참임을 표현하기 위한 매크로 정의
#define FALSE 0			//거짓임을 표현하기 위한 매크로 정의

#define LIST_LEN 100	//리스트의 크기를 정하는 매크로 정의
typedef int LData;		//int 형을 LData라는 이름으로 정의

typedef struct __ArrayList {			// 배열 기반 리스트를 정의한 구조체
	LData arr[LIST_LEN];				// 리스트 저장 배열 사이즈 100
	int numOfData;						// 저장된 데이터의 수를 기록하는 변수
	int curPosition;					// 데이터의 참조위치를 기록하는 변수
} ArrayList;

typedef ArrayList List;					// ArrayList 구조체를 List 이름으로 정의

void ListInit(List* plist);				// 초기화 함수
void LInsert(List* plist, LData data);	// 데이터 저장 함수

int LFirst(List* plist, LData* pdata);	// 첫 데이터 참조 함수
int LNext(List* plist, LData* pdata);	// 두번째 이후 데이터 참조 함수

LData LRemove(List* plist);				// 참조한 데이터 삭제 함수
int LCount(List* plist);				// 저장된 데이터의 수 반환 함수

#endif