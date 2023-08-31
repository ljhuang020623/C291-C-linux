#include<stdio.h>

int main(void){
	int a, n, d, AP;
	printf("Enter the starting number of AP series: ");
	scanf("%d", &a);

	printf("Enter the common difference: ");
	scanf("%d",&d);

	printf("Enter the nth term to be found: ");
	scanf("%d", &n);

	AP = a + (n - 1) * d;

	printf("The %dth term of the series is: %d\n", n, AP);

	return 0;
}
