#include<stdio.h>

int main(void){
	int num;
	printf("Input a number: ");
	scanf("%d", &num);
	if (num % 2){
       	 	return num + "is an even number";
	} else {
		return num + " is an odd number";
	}
}


