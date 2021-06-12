#include <stdio.h>

int BSearch(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;

	while (first <= last) {
		mid = (first + last) / 2;

		if (target == ar[mid]) {
			printf("Ÿ�� ���� �ε���: %d \n\n", mid);
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
	printf("�� ���� Ƚ��: %d \n", opCount);
	printf("Ž�� ���� \n\n");
	return 0;
}

int main() {
	int arr1[500] = { 0, };
	int arr2[5000] = { 0, };
	int arr3[50000] = { 0, };

	BSearch(arr1, sizeof(arr1) / sizeof(int), 1);			//arr1���� ������� ���� 1�� ã��
	BSearch(arr2, sizeof(arr2) / sizeof(int), 2);			//arr2���� ������� ���� 2�� ã��
	BSearch(arr3, sizeof(arr3) / sizeof(int), 3);			//arr3���� ������� ���� 3�� ã��

	return 0;
}

//�迭�� ũ�Ⱑ 500, 5000, 50000�϶� ���� Ƚ��
//
//���� Ž�� : 500ȸ, 5000ȸ, 50000ȸ	O(n)
//���� Ž�� : 9ȸ,	13ȸ,	16ȸ		O(logn)

