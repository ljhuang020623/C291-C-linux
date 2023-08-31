#include<stdio.h>

int main(void){
	int month, year, age;
	printf("Enter current month: ");
	scanf("%d", &month);
	
	printf("Enter current year: ");
	scanf("%d", &year);
	
	printf("Enter your age: ");
	scanf("%d", &age);

	printf("It is month %d and year %d and you are %d years old\n", month, year, age);
	
	return 0;
}
