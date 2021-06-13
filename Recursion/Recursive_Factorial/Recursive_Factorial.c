#include <stdio.h>

long int Factorial(long int n) {
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

long int main() {
	printf("1! = %d \n", Factorial(1));
	printf("2! = %d \n", Factorial(2));
	printf("3! = %d \n", Factorial(3));
	printf("4! = %d \n", Factorial(4));
	printf("9! = %d \n", Factorial(9));

	return 0;
}