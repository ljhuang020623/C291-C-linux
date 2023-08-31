#include<stdio.h>

int main(void){
	int a, b, sum, difference, product, remainder;
	printf("Input a: ");
	scanf("%d", &a);

	printf("Input b: ");
	scanf("%d", &b);

	sum = a + b;
	difference = a - b;
	product = a * b;
	remainder = a % b;

	printf("The sum of %d and %d is %d.\n", a, b, sum);
	printf("The difference of %d and %d is %d.\n", a, b, difference);
	printf("The product of %d and %d is %d.\n", a, b, product);
	printf("The remainder of %d and %d is %d.\n", a, b, remainder);

	return 0;
}
