#pragma once
#ifndef __DB_LINKED_LIST_H__			// 재 선언이 되지 않도록 제한을 주는 구문
#define __DB_LINKED_LIST_H__

#define TRUE	1			// 매크로 선언 
#define FALSE	0

typedef int Data;			// int 형을 Data로 선언

typedef struct _node {		// 노드 구조체를 선언
	Data data;				// Data형 데이터를 담는 data 변수 선언 
	struct _node* next;		// 다음 노드의 주소를 가리키는 _node형 포인터 변수 선언
	struct _node* prev;		// 이전 노드의 주소를 가리키는 _node형 포인터 변수 선언
} Node;			// 구조체 이름을 Node로 재선언

typedef struct _DLinkedList {			// 양방향 연결 리스트를 구성하는 구조체 선언
	Node* head;							// 리스트의 머리를 가리키는 노드
	Node* cur;							// 리스트에서 현재 노드를 가리키는 노드
	int numOfData;						// 저장된 노드의 갯수를 저장하는 변수
} DBLinkedList;							// 구조체 이름을 재선언

typedef DBLinkedList List;				// 구조체 이름을 List로 재선언

void ListInit(List* plist);					// 리스트를 초기화 하는 함수
void LInsert(List* plist, Data data);		// 리스트에 노드를 추가하는 함수

int LFirst(List* plist, Data* pdata);		// 리스트 탐색시 처음에만 실행되는 함수
int LNext(List* plist, Data* pdata);		// 리스트 탐색시 LFirst 다음으로 실행하는 함수
int LPrevious(List* plist, Data data);		// LNext 함수의 반대 방향의 노드를 참조하는 함수
int LCount(List* plist);					// 저장된 노드의 갯수를 반환 하는 함수

#endif // !__DB_LINKED_LIST_H__
