#include <stdio.h>			//21-06-10 작성

int Linear_Search(int ar[], int len, int target) {			//순차 탐색 알고리즘 함수
	int i;
	for (i = 0; i < len; i++) {
		if (ar[i] == target)
			return i;			//찾은 대상의 인덱스값을 반환
	}
	return -1;			//찾지 못하면 -1을 반환
}
int main() {
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = Linear_Search(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = Linear_Search(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}
