#include<stdio.h>

void generateKGrams(int k, char input[]);
void printGrams(int n, int k);
int length(char str[]);

#define MAX_STRING_LENGTH 1000
#define MAX_KGRAMS_LENGTH 1000

char kGrams[MAX_KGRAMS_LENGTH][MAX_STRING_LENGTH];

int main(void){
	char input[] = "because the arrays starting address is passed, the called function knows precisely where the array is stored";
	int k, i;
	printf("Input value of k: ");
	scanf("%d", &k);
	int n = length(input) - k + i;

	generateKGrams(k, input);
	printf("Output:\n");
	printGrams(n,k);
	return 0;
}

void generateKGrams(int k, char input[]){
	int j, i;
	int l = length(input);
	for (i = 0; i <= l - k; i++){
		for(j = 0; j < k; j++){
			kGrams[i][j] = input[i + j];			
		}
		kGrams[i][j] = '\0';
	}
}


void printGrams(int n, int k){
	printf("[");
	for (int i = 0; i < n; i++){
		printf("'%s', ", kGrams[i]);
	}
	printf("]\n");
}

int length(char str[]){
	int len = 0;
	while(str[len] != '\0'){
		len ++;
	}
	return len;
}
