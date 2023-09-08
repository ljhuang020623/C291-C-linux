#include<stdio.h>

int main (void){
	int a, b, c;
	printf("Input first angle: ");
	scanf("%d", &a);
	printf("Input second angle: ");
	scanf("%d", &b);
	printf("Input third angle: ");
	scanf("%d", &c);

	if ((a+b+c == 180) && a > 0 && b > 0 & c > 0){
		printf("The triangle is valid.\n");
		if (a < 90 && b < 90 && c < 90){
			printf("It's an acute triangle.\n");
			if (a == c || b == c || a == b){
                        	printf("It's isosceles.\n");
				if (a == b && b == c){
                                	printf("Its an equilateral triangle.\n");
                        	}
			}else{
                        	printf("Its not isosceles.\n");
     			}
		}else if (a == 90 || b == 90 || c == 90){
			printf("It's a right triangle.\n");
			printf("It's not isosceles.\n");
		}else if (a > 90 || b > 90 || c > 90){
			printf("It's an obtuse triangle.\n");
		         if (a == c || b == c || a == b){
                                printf("It's isosceles.\n");
			 }else{
                                printf("Its not isosceles.\n");
                        }	
		}		
	}else{
		printf("The triangle is invalid\n");
	}
}
