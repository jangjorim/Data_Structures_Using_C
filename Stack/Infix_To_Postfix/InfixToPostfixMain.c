#include <stdio.h>
#include "InfixToPostfix.h"

int main() {
	char exp1[] = "1+2*3";			// 중위식을 배열에 저장한다.
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);			// 함수를 사용하여 중위식을 후위식으로 변환한다.
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s \n", exp1);			// 변환한 식을 화면에 출력한다.
	printf("%s \n", exp2);
	printf("%s \n", exp3);

	return 0;
}
