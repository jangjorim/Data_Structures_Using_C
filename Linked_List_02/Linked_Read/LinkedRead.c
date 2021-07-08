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
	printf("0 이하의 수를 입력시 입력이 종료됩니다. \n");
	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);			// 수를 입력받기
		if (readData < 1)			// 0이하의 수를 입력하면 데이터를 그만 입력받는다.
			break;

		// 노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));			// 새로운 노드를 할당한다.
		newNode->data = readData;			// 새노드 데이터에 입력 받은 값을 저장한다.
		newNode->next = NULL;			// 새노드 다음에 이어지는(연결해야하는) 곳의 주소는 비워놓는다.

		if (head == NULL)			// 첫 번째 노드라면
			head = newNode;			// 첫 번째 노드를 head가 가리키게 한다.
		else						// 두 번째 이후 노드라면
			tail->next = newNode;			// 연결리스트의 마지막 부분을 가리키는 tail에 새노드의 주소값을 넣는다.

		tail = newNode;			// tail에 새로운 노드의 주소값을 넣는다.
	}
	printf("\n");

	// 입력 받은 데이터의 출력과정 //
	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL) {			// 연결리스트가 시작되는 해드부분이 없으면 저장된 데이터가 없다는 뜻이다.
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else {
		cur = head;			// 탐색에 사용되는 포인터 변수에 리스트의 처음 시작되는 주소를 대입한다.
		printf("%d ", cur->data);			// 첫 번째 데이터 출력

		while (cur->next != NULL) {			// 두 번째 이후의 데이터가 있다면 마지막 노드까지 실행한다.
			cur = cur->next;			// 데이터 출력을 하고난 다음 노드의 주소값을 대입받는다.
			printf("%d ", cur->data);			// 다음노드의 데이터 값을 출력한다.
		}
	}
	printf("\n\n");

	// 메모리 해제과정 //
	if (head == NULL) {
		return 0;			// 해제할 노드가 존재하지 않는다.
	}
	else {
		Node* delNode = head;			// 삭제할 노드의 주소값을 저장할 포인터 변수에 연결리스트의 헤드 주소 값을 넣는다.
		Node* delNextNode = head->next;			// 삭제할 노드의 다음 주소값을 저장하는 포인터 변수를 선언하고 헤드의 next값을 넣는다.

		printf("%d을(를) 삭제합니다. \n", head->data);			// 삭제할 데이터를 화면에 출력해 준다.
		free(delNode);			// 첫 번째 노드 삭제하여 메모리 주소 할당을 해지한다.

		while (delNextNode != NULL) {			// 다음 노드가 있다면 계속 실행한다.
			delNode = delNextNode;			// 삭제후 다음에 삭제할 데이터가 있는 다음 주소값을 삭제할 노드를 가리키는 포인터 변수에 넣는다.
			delNextNode = delNextNode->next;			// 삭제하는 데이터가 있는 다음 주소값을 넣는다.

			printf("%d을(를) 삭제합니다. \n", delNode->data);				// 삭제하는 데이터를 출력해 준다.
			free(delNode);			// 메모리 할당을 해지해 준다.
		}
	}
	return 0;
}
