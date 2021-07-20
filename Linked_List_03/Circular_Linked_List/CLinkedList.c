#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {			// 리스트를 초기화하는 함수
	plist->tail = NULL;					
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List* plist, Data data) {			// 리스트 머리에 노드를 추가하는 함수
	Node* newNode = (Node*)malloc(sizeof(Node));			// 메모리 공간을 할당 받아 새 노드를 생성
	newNode->data = data;			// 새 노드에 데이터를 삽입

	if (plist->tail == NULL) {			// 꼬리 노드가 비어있다면
		plist->tail = newNode;			// 꼬리 노드를 새 노드로 한다.
		newNode->next = newNode;		// 다음 노드 주소를 연결을 자신으로 한다.
	}
	else {			// 꼬리 노드가 있다면
		newNode->next = plist->tail->next;			// 새 노드 next에 꼬리 노드의 next 주소를 넣는다.
		plist->tail->next = newNode;				// 꼬리 노드 next에 새 노드 주소값을 넣는다.
	}
	(plist->numOfData)++;			// 저장된 노드 갯수를 +1 해준다.
}

void LInsert(List* plist, Data data) {			// 리스트 꼬리에 노드를 추가하는 함수
	Node* newNode = (Node*)malloc(sizeof(Node));			// 메모리 공간을 할당 받아 새 노드를 생성
	newNode->data = data;			// 새 노드에 데이터를 삽입

	if (plist->tail == NULL) {			// 꼬리 노드가 비어있다면
		plist->tail = newNode;			// 꼬리 노드를 새 노드로 한다.
		newNode->next = newNode;		// 다음 노드 주소를 연결을 자신으로 한다.
	}
	else {			// 꼬리 노드가 있다면
		newNode->next = plist->tail->next;			// 새 노드 next에 꼬리 노드의 next 주소를 넣는다.
		plist->tail->next = newNode;				// 꼬리 노드 next에 새 노드 주소값을 넣는다.
		plist->tail = newNode;						// 꼬리 노드를 새 노드로 설정한다.
	}
	(plist->numOfData)++;			// 저장된 노드 갯수를 +1 해준다.
}

int LFirst(List* plist, Data* pdata) {			// 리스트 탐색시 처음에 실행되는 함수
	if (plist->tail == NULL)			// 노드가 존재하지 않는다면
		return FALSE;					// 0을 반환한다.

	plist->before = plist->tail;		// before가 꼬리를 가리키게 하고
	plist->cur = plist->tail->next;		// cur이 머리를 가리키게 한다.
	// 결국 before와 cur은 전부 tail노드를 가리키고있다. //

	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터를 반환한다.
	return TRUE;
}

int LNext(List* plist, Data* pdata) {			// 리스트 탐색시 LFirst 이후로 실행되는 함수
	if (plist->tail == NULL)			// 노드가 존재하지 않는다면
		return FALSE;					// 0을 반환한다.

	plist->before = plist->cur;			// before가 다음 노드를 가리키게 한다.
	plist->cur = plist->cur->next;		// cur이 다음 노드를 가리키게 한다.

	*pdata = plist->cur->data;			// cur이 가리키는 노드의 데이터를 반환한다.
	return TRUE;
}

Data LRemove(List* plist) {				// 노드를 삭제하는 함수
	Node* rpos = plist->cur;			// rpos이 cur을 가리키게 한다.
	Data rdata = rpos->data;			// rdata에 rpos의 데이터를 대입한다.

	if (rpos == plist->tail) {			// 삭제 대상을 tail이 가리킨다면
		if (plist->tail == plist->tail->next)			// 마지막 남은 노드라면
			plist->tail = NULL;			// tail 노드를 NULL로 초기화 한다.
		else							// tail 이외에 다른 노드가 더 있다면
			plist->tail = plist->before;			// tail이 before를 가리키게 한다.
	}

	plist->before->next = plist->cur->next;			// before와 cur이 가리키는 노드를 한칸씩 이동한다.
 	plist->cur = plist->before;						// cur이 before를 가리키게 한다.

	free(rpos);			// 메모리 할당을 해지한다.
	(plist->numOfData)--;			// 저장된 노드의 갯수를 -1한다.
	return rdata;					// 삭제된 데이터 값을 반환한다.
}

int LCount(List* plist) {			// 현재 저장된 노드의 갯수를 반환하는 함수
	return plist->numOfData;		
}