#include<stdio.h>

int main(void){
	int num, i;
	printf("Enter a positice integer that you wish to find prime factors of: ");
	scanf("%d", &num);
	if (num == 0 || num == 1){
		printf("%d has no prime factorization.", num);
	}else{
		printf("The prime factorization of %d is: ", num);
		for (i = 2 ; i <= num; i ++){
			while ((num % i) == 0){
				printf("%d ", i);
				num /= i;
			}  	
		}
	}
	printf("\n");
	return 0;
}

