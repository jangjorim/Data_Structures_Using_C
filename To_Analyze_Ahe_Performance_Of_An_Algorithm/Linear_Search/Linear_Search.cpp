#include <stdio.h>			//21-06-10 �ۼ�

int Linear_Search(int ar[], int len, int target) {			//���� Ž�� �˰��� �Լ�
	int i;
	for (i = 0; i < len; i++) {
		if (ar[i] == target)
			return i;			//ã�� ����� �ε������� ��ȯ
	}
	return -1;			//ã�� ���ϸ� -1�� ��ȯ
}
int main() {
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = Linear_Search(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	idx = Linear_Search(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}
