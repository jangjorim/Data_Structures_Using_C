#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist) {			// 리스트 초기화를 하는 함수
	plist->head = (Node*)malloc(sizeof(Node));			// 더미 노드를 생성
	plist->head->next = NULL;			// 더미 노드 다음 노드는 NULL 값으로 설정
	plist->comp = NULL;			// 
	plist->nunOfData = 0;			// 저장된 데이터의 갯수를 0으로 세팅
}

void FInsert(List*plist, LData data) {			// 정렬 기준이 없을때 데이터를 삽입할 때 사용하는 함수
	Node * newNode = (Node*)malloc(sizeof(Node));			// 새 노드를 생성함
	newNode->data = data;			// 새 노드에 데이터를 저장함

	newNode->next = plist->head->next;			// 새 노드가 기존에 더미노드가 가리키던 노드를 가리킴
	plist->head->next = newNode;			// 더미 노드가 새 노드를 가리키게 함

	(plist->nunOfData)++;			// 데이터 갯수를 1 증가함
}

void SInsert(List * plist, LData data) {			// 정렬 기준이 있을때 데이터를 삽입하는 함수
	Node * newNode = (Node*)malloc(sizeof(Node));			// 새 노드를 생성함
	Node * pred = plist->head;			// pred가 더미 노드를 가리키게 함
	newNode->data = data;			// 새 노드에 데이터를 저장


	// pred가 리스트의 마지막 노드를 가리키지 않으면서
	// 새 데이터와 pred 다음의 노드에 저장된 데이터의 우선순위를 확인하여 반환 값이 0이 아니라면 아래 구문을 계속 실행함
	while (pred->next != NULL && plist->comp(data, pred->next->next) != 0) {
		pred = pred->next;			// 다음 노드로 이동
	}

	newNode->next = pred->next;			//새 노드의 오른쪽은 연결함
	pred->next = newNode;			// 새 노드의 왼쪽을 연결함

	(plist->nunOfData)++;			// 저장된 데이터의 수를 1 증가함
}

void LInsert(List * plist, LData data) {			// 데이터를 입력하는 함수
	if (plist->comp == NULL)			// 정렬 기준이 없다면 FInsert 함수를 실행 하여 머리에 노드를 추가
		FInsert(plist, data);
	else
		SInsert(plist, data);			// 정렬 기준이 있다면 SInsert 함수를 실행
}

int LFirst(List * plist, LData * pdata) {			// 첫 번째로 데이터를 조회할 때 사용하는 함수
	if (plist->head->next == NULL)			// 더미 노드가 NULL을 가리킨다면 반환할 데이터는 없다
		return FALSE;

	plist->before = plist->head;			// before는 더미 노드를 가리키게 함
	plist->cur = plist->head->next;			// cur은 첫 번째 노드를 가리키게 함

	*pdata = plist->cur->data;			// 첫 번째 노드의 데이터를 전달함
	return TRUE;
}

int LNext(List * plist, LData * pdata) {			// 두 번째 이후의 데이터를 조회할 때 사용하는 함수
	if (plist->cur->next == NULL)			// cur이 NULL을 가리키면 반환할 데이터가 없다
		return FALSE;

	plist->before = plist->cur;			// cur이 가리키던 것을 before가 가리키게 함
	plist->cur = plist->cur->next;			// cur은 다음 노드를 가리킴

	*pdata = plist->cur->data;			// 데이터를 전달 받고 TRUE를 리턴함
	return TRUE;
}

LData LRemove(List * plist) {
	Node * rpos = plist->cur;			// 소멸 대상의 주소 값을 rpos에 저장
	LData rdata = rpos->data;			// 소멸 대상의 데이터를 rdata에 저장

	plist->before->next = plist->cur->next;			// 소멸 대상의 다음 노드를 before->next에 넣는다
	plist->cur = plist->before;			// cur의 위치를 조정해서 before와 같은 곳을 가리키게함

	free(rpos);			// 메모리 할당을 해지함
	(plist->nunOfData)--;			// 저장된 데이터 수를 1 감소함
	return rdata;			// 삭제한 데이터를 반환해 줌
}

int LCount(List * plist) {
	return plist->nunOfData;			// 저장된 데이터 수를 반환해 줌
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;			// comp를 새로운 조건으로 초기화 함
}

