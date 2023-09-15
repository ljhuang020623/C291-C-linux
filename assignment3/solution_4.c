#include<stdio.h>
#include<math.h>
int main(void){
	int num;
	printf("Enter a number to find the reverse binary representation: ");
	scanf("%d", &num);
	while (num > 0){
		printf("%d", num % 2);
		num /= 2;
	}
	if (num < 0){
	printf("Error: Number must be a positive integer.");
	}else if (num == 0){
		printf("0");
	}
	printf("\n");
	return 0;
}
