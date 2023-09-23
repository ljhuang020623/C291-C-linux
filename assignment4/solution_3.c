#include<stdio.h>

int isPerfectNumber(int n);

int main(void){
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	if(isPerfectNumber(n) == 1){
		printf("%d is a perfect number\n", n);
	}else{
		printf("%d is not a perfect number\n", n);
	}
	return 0;
}

int isPerfectNumber(int n){
	int i, sum = 0;
	for (i = 1; i < n; i ++){
		if(n % i == 0){
			sum += i;
		}
	}
	if(sum == n){
		return 1;
	}else{
		return 0;
	}
}
