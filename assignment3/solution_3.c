#include<stdio.h>

int main(void){
	int num, count = 1;
	printf("Enter the starting Fizz Buzz number: ");
	scanf("%d", &num);
	if (num <= 0){
		printf("Error: Cannot compute Fizz Buzz of %d.", num);
	}else{
		while(num > 0){
			if ((count % 4) == 0){
				if ((num % 15) == 0){
                                        printf("Fizz-Buzz ");
                                }else if((num % 5) == 0){
                                        printf("Buzz ");
                                }else if((num % 3) == 0){
                                        printf("Fizz ");
                                }else{
                                        printf("%d ", num);
                                }
				printf("\n");
			}else{
				if ((num % 15) == 0){
					printf("Fizz-Buzz ");	
				}else if((num % 5) == 0){
					printf("Buzz ");
				}else if((num % 3) == 0){
					printf("Fizz ");
				}else{
					printf("%d ", num);
				}
			}
			num -= 1;
			count += 1;
		}	
	}
	printf("\n");
	return 0;
}
