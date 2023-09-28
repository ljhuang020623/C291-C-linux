#include<stdio.h>

void printUniqueElements(int elements[], int lenArray);
 

int main(void){
	int i, lenArray;
	printf("Input Size of Array: ");
	scanf("%d", &lenArray);
	int elements[lenArray];
    	printf("Input: ");
    	for (i = 0; i < lenArray; i++) {
        	scanf("%d", &elements[i]);
    	}
	printUniqueElements(elements, lenArray);
	return 0;
}


void printUniqueElements(int elements[], int lenArray){
	int i, index = 0;
	int value = elements[0];
	printf("%d ",value);
	for(i = 1; i < lenArray ; i++){
		if (elements[i] != value){
			value = elements[i];
			index ++;
			printf("%d ",value);
		}
	}
	printf("\n");

}
