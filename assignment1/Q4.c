#include <stdio.h>

int main(void){
	int r, area, diameter, circumference;

	printf("Enter a radius: ");
	scanf("%d", &r);
	

	area = 3 * r * r;
	diameter = 2 * r;
	circumference = 2 * 3 * r;

	printf("The Area of circle with radius %d is %d.\n", r, area);
	printf("The Diameter of circle with radius %d is %d.\n", r, diameter);
	printf("The circumference of circle with radius %d is %d.\n", r, circumference);
	
	return 0;
}
