#include <stdio.h>
#include "PostCalculator.h"

int main() {
	char postExp1[] = "42*8+";            // 배열에 후위식을 삽입한다.
	char postExp2[] = "123+*4/";

	printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));            // 변환한 식을 화면에 출력한다.
	printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));

	return 0;
}
