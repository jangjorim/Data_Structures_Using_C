#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) {			// 리스트를 초기화하는 함수 정의
	plist->head = NULL;					// 머리를 비워놓는다.
	plist->numOfData = 0;				// 저장된 노드의 갯수를 0으로 초기화 한다.
}

void LInsert(List* plist, Data data) {			// 리스트에 노드를 삽입하는 함수 정의
	Node* newNode = (Node*)malloc(sizeof(Node));			// 새 노드에 메모링 할당을 해준다
	newNode->data = data;									// 새 노드에 데이터를 삽입한다.

	newNode->next = plist->head;							// 새 노드 next를 head를 가리킨다.
	if (plist->head != NULL)								// 만약 해드가 NULL 이라면
		plist->head->prev = newNode;						// 해드의 prev가 새 노드를 가리킨다.

	newNode->prev = NULL;									// 새 노드의 prev가 NULL을 가리킨다.
	plist->head = newNode;									// head는 새 노드를 가리킨다.

	(plist->numOfData)++;									// 노드 갯수를 +1 해준다.
}

int LFirst(List* plist, Data* pdata) {			// 리스트를 처음에 탐색할 때 사용하는 함수 정의
	if (plist->head == NULL)					// 만약 리스트가 비어있다면
		return FALSE;							// 0을 반환 한다.
	
	plist->cur = plist->head;					// 현재 가리키는 노드를 head로 설정한다.
	*pdata = plist->cur->data;					// 현재 가리키는 노드의 데이터를 대입한다.

	return TRUE;								// 1을 반환 한다.
}

int LNext(List* plist, Data* pdata) {			// 리스트를 탐색 할 때 LFirst 다음으로 사용하는 함수 정의
	if (plist->cur->next == NULL)				// 만약 다음 노드가 없다면
		return FALSE;							// 0을 반환

	plist->cur = plist->cur->next;				// 가리키고 있는 노드를 다음 노드로 한칸 이동한다.
	*pdata = plist->cur->data;					// 현재 가리키는 노드의 데이터를 대입한다.

	return TRUE;								// 1을 반환한다.
}

int LPrevious(List* plist, Data* pdata) {		// LNext 함수의 반대 방향의 노드를 참조하는 함수 정의
	if (plist->cur->prev == NULL)				// 만약 이전 노드가 없다면 
		return FALSE;							// 0을 반환
	
	plist->cur = plist->cur->prev;				// 현재 가리키는 노드를 이전 노드로 한칸 이동
	*pdata = plist->cur->data;					// 현재 가리키는 노드의 데이터를 대입

	return TRUE;								// 1을 반환
}

int LCount(List* plist) {						// 저장된 노드의 갯수를 반환 하는 함수
	return plist->numOfData;
}