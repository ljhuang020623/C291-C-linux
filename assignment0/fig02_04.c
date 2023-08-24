#include<stdio.h>

// Addition program

int main(void){
	int integer1 = 0;
	int integer2 = 0;
	printf("Enter first integer:");
	scanf("%d", &integer1);
	printf("Enter second integer:");
	scanf("%d", &integer2);
	int sum = 0;
	sum = integer1 + integer2;
	printf("Sum is %d\n", sum);
}
