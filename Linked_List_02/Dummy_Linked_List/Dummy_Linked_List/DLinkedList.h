#ifndef __D_LINKED_LIST_H__			// 재 선언이 되지 않도록 제한을 주는 구문
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData;			// int형을 LData로 재 선언

typedef struct _node {			// 노드 구조체를 선언
	LData data;			// 데이터를 저장하는 변수 선언
	struct _node* next;			// 다음 노드의 주소를 가리키는 포인터 변수 선언
} Node;			// Node로 이름을 재설정

typedef struct _linkedList {			// 연결 리스트를 구성하는 구조체를 선언
	Node* head;			// 더미 노드를 가리키는 구조체 멤버
	Node* cur;			// 참조 및 삭제를 돕는 멤버
	Node* before;			// 삭제를 돕는 멤버
	int nunOfData;			// 저장된 데이터의 수를 기록하기 위한 멤버
	int(*comp)(LData d1, LData d2);			// 정렬 기준을 등록하기 위한 멤버 
} LinkedList;			// 구조체 이름을 재설정

typedef LinkedList List;			// 구조체 이름을 List로 재설정

void ListInit(List* plist);			// 연결 리스트 초기화 함수
void LInsert(List* plist, LData* pdata);			// 데이터 저장 함수

int LFirst(List* plist, LData* pdata);			// 첫 번째 데이터 참조 함수
int LNext(List* plist, LData* pdata);			// 두 번째 이후 데이터 참조 함수

LData LRemove(List* plist);			// 참조한 데이터를 삭제하는 함수
int LCount(List* plist);			// 저장된 데이터 수를 반환 하는 함수

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));			// 정렬 기준을 지정하는 함수

#endif // !1
