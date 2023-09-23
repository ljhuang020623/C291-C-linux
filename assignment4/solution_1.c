#include<stdio.h>
#include<math.h>

float binomialDistribution(int k, int n, float p);
float factorial(int n);

int main(void){
	int n, k; 
	float p;	
	printf("Enter k value: ");
	scanf("%d", &k);
	printf("Enter n value: ");
	scanf("%d", &n);
	printf("Enter p value: ");
	scanf("%f", &p);
	printf("The answer is %.6f\n", binomialDistribution(k, n, p));
	printf(" ");
	return 0;
}

float binomialDistribution(int k, int n, float p){
	return (factorial(n) / (factorial(k) * factorial(n - k)) * pow(p,k) * pow(1-p, n-k));
}

float factorial(int n){
	if (n == 0){
		return 1;
	}else{
		return n * factorial(n - 1);
	}
}
