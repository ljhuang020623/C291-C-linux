#include<stdio.h>
#include<math.h>
float computeSeries(int X, int n, int L, int R);
int factorial(int n);
int generatePrime(int L, int R, int i);
int power(int X, int n);

int X,n,L,R;
int main(void){
	printf("Enter the value of X:");
	scanf("%d", &X);
	printf("Enter the value of n:");
	scanf("%d", &n);
	printf("Enter the value of L:");
        scanf("%d", &L);
        printf("Enter the value of R:");
        scanf("%d", &R);
	printf("Sum of series = %.4f\n", computeSeries(X,n,L,R));
	return 0;
}

float computeSeries(int X, int n, int L, int R){
	float sum = 0;
	int i, p = 0;
	for (i = 1; i <= n; i ++){
		sum += generatePrime(L, R, i);
	}for (p = 2; p <= n; p++){
                sum += (float)power(X, p) / factorial(p);
        }
	return X + sum;

}

int factorial(int n){
	if (n<=1){
		return 1;
	}else{
		return n * factorial(n - 1);
	}
}

int generatePrime(int L, int R, int i){
	int m , n, num = 0, count = 0;
	for (m = L; m < R; m ++){
		for (n = 2; n < m; n++){
			if ((m % n) != 0){
				count += 1;
			}else{
				break;
			}
		}if(count == (m - 2)){
			num += 1;	
			if (num == i){
				return m;
			}
		}
		count = 0;
	}
	return 0;
}

int power(int X, int n){
	return pow(X,n);
}
