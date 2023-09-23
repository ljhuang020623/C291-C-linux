#include<stdio.h>

int calculateFactorial(int n);
unsigned long long ans = 1;


int main(void){
	int n, i, local_count = 0;
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	
	if (n <0){
		printf("Invalid input: Please enter a non-negative integer.\n");
	}else{
		for(i = n; i > 0; i--){
		local_count = calculateFactorial(i);
		}
		printf("Factorial of %d is %llu\n", n, ans);
		printf("Number of times calculateFactorial was called: %d\n", local_count);
	}
	return 0;
}




int calculateFactorial(int n){
	static int static_count = 0;
	static_count ++;
	ans *= n;
	return static_count;
}
