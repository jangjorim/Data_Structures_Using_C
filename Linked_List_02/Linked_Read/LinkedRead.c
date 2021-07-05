#include <stdio.h>
#include <stdlib.h>

typedef struct _node {			// _node 라는 이름의 구조체를 형성
	int data;			// 노드의 데이터를 저장하는 변수
	struct _node* next;			// 다음 노드의 주소를 저장하는 포인터 변수
} Node;			// typedef로 Node라는 이름으로 구조체 이름을 재설정 한다.

int main() {
	Node* head = NULL;			// 연결리스트의 머리를 가리키는 포인터 주소를 담는 변수
	Node* tail = NULL;			// 연결리스트의 꼬리를 가리키는 포인터 주소를 담는 변수
	Node* cur = NULL;			// 연결리스트의 저장된 데이터를 조회하는데 사용되는 변수

	Node* newNode = NULL;			// 새로운 노드의 주소를 담는 포인터 변수
	int readData;			// 입력받는 데이터를 저장하는 변수

	// 데이터를 입력 받는 과정 //
	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);			// 수를 입력받기
		if (readData < 1)			// 입력된 값이 1보다 작으면 while문을 벗어난다.
			break;

		// 노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));			// 새로운 노드를 할당한다.
		newNode->data = readData;			// 새노드 데이터에 입력 받은 값을 저장한다.
		newNode->next = NULL;			// 새소드 다음에 이어지는(연결해야하는) 곳의 주소는 비워놓은다.

		if (head == NULL)			// 연결리스트의 머리를 가리키는 주소가 비어있다면
			head = newNode;			// 해드에 새노드가 있는 주소값을 넣는다.
		else
			tail->next = newNode;			// 그렇지 않다면 연결리스트의 마지막 부분을 가리키는 tail에 새노드의 주소값을 넣는다.

		tail = newNode;			// tail에 새로운 노드의 주소값을 넣는다.
	}
	printf("\n");

	// 입력 받은 데이터의 출력과정 //
	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL) {
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);			// 첫 번째 데이터 출력

		while (cur->next != NULL) {			// 두 번쨰 이후의 데이터 출력
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 메모리 해제과정 //
	if (head == NULL) {
		return 0;			// 해제할 노드가 존재하지 않는다.
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);			// 첫 번째 노드 삭제

		while (delNextNode != NULL) {			// 첫 번째 노드 삭제
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}