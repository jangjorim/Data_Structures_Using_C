#include <stdio.h>

int BSearch(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;

	while (first <= last) {
		mid = (first + last) / 2;

		if (target == ar[mid]) {
			printf("타겟 저장 인덱스: %d \n\n", mid);
			return 0;
		}
		else {
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}

		opCount += 1;
	}
	printf("비교 연산 횟수: %d \n", opCount);
	printf("탐색 실패 \n\n");
	return 0;
}

int main() {
	int arr1[500] = { 0, };
	int arr2[5000] = { 0, };
	int arr3[50000] = { 0, };

	BSearch(arr1, sizeof(arr1) / sizeof(int), 1);			//arr1에서 저장되지 않은 1을 찾기
	BSearch(arr2, sizeof(arr2) / sizeof(int), 2);			//arr2에서 저장되지 않은 2을 찾기
	BSearch(arr3, sizeof(arr3) / sizeof(int), 3);			//arr3에서 저장되지 않은 3을 찾기

	return 0;
}

//배열의 크기가 500, 5000, 50000일때 연산 횟수
//
//순차 탐색 : 500회, 5000회, 50000회	O(n)
//이진 탐색 : 9회,	13회,	16회		O(logn)

