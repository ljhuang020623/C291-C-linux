#include<stdio.h>

void printSortedMergedArray(int array1[], int lenArray1, int array2[], int lenArray2);

int main(void){
	int i, lenArray1, lenArray2;
	printf("Input Size of Array 1: ");
	scanf("%d", &lenArray1);
	int array1[lenArray1];
	printf("Input Array 1: ");
	if (lenArray1 == 0){
		printf("\n");
	}
	for(i = 0; i < lenArray1 ; i++){
		scanf("%d", &array1[i]);
	}
	printf("Input Size of Array 2: ");
        scanf("%d", &lenArray2);
        int array2[lenArray2];
        printf("Input Array 2: ");
	if (lenArray2 == 0){
                printf("\n");
        }
        for(i = 0; i < lenArray2 ; i++){
                scanf("%d", &array2[i]);
        }
	printSortedMergedArray(array1, lenArray1, array2, lenArray2);
	return 0;
}

void printSortedMergedArray(int array1[], int lenArray1, int array2[], int lenArray2){
	int i, j, k, l, m, num = 0;
	int array3[lenArray1 + lenArray2];
	for(i = 0; i < lenArray1; i++){
		array3[i] = array1[i];	
	}	
	for(j = 0; j< lenArray2 ;j++){
		array3[j+lenArray1] = array2[j];		
	}
	for(k = 0; k< (lenArray1 + lenArray2); k ++){
                for(l = k + 1; l < (lenArray1 + lenArray2); l++){
                        if (array3[l] < array3[k]){
                                num = array3[k];
				array3[k] = array3[l];
                        	array3[l] = num;
			}
                }
        }
	for(m = 0; m < lenArray1 + lenArray2; m ++){
		printf("%d ", array3[m]);
	}
	printf("\n");
}
