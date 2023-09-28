#include<stdio.h>

int checkSet(int input[], int input_length);
int findIntersection(int input1[], int input1_length, int input2[], int input2_length);
int findUnion(int input1[], int input1_length, int input2[], int input2_length);
float calculateJaccard(int input1[], int input1_length, int input2[], int input2_length);

int main(void){
	int input1_length, input2_length, i;
	printf("Input first set length: ");
	scanf("%d", &input1_length);
	int input1[input1_length];
	printf("Input first set: ");
	for(i = 0; i <input1_length; i++){
		scanf("%d,", &input1[i]);
	}
	if(checkSet(input1,input1_length) == 0){
		return 0;
	}
	printf("Input second set length: ");
        scanf("%d,", &input2_length);
        int input2[input2_length];
        printf("Input second set: ");
        for(i = 0; i <input2_length; i++){
                scanf("%d,", &input2[i]);
	}
	if(checkSet(input1,input1_length) == 0){
                return 0;
        }
	float Jaccard = calculateJaccard(input1,input1_length,input2,input2_length);
	printf("Jaccard similarity is %.3f\n", Jaccard);
	return 0;
}
int checkSet(int input[], int input_length){
	if (input_length == 0){
		printf("\n");
		printf("set cannot be empty.\n");
		return 0;
	}
	return 1;
}

int findIntersection(int input1[], int input1_length, int input2[], int input2_length){
	int i, j, count1 = 0;
	for (i = 0; i < input1_length; i ++){
		for (j = 0; j < input2_length; j++){
			if (input1[i] == input2[j]){
				count1 ++;
				break;
			}
		}
	}
	return count1;

}
int findUnion(int input1[], int input1_length, int input2[], int input2_length){
	int i, j, count2 = input1_length + input2_length;
        for (i = 0; i < input1_length; i ++){
                for (j = 0; j < input2_length; j++){
                        if (input1[i] == input2[j]){
                              	count2 --;
                        }
                }
        }
        return count2;
}
float calculateJaccard(int input1[], int input1_length, int input2[], int input2_length){
	float Intersection = (float)findIntersection(input1,input1_length,input2,input2_length);
	float Union = (float)findUnion(input1,input1_length,input2,input2_length);
	if (Union == 0){
		return 0;
	}else{
		return Intersection / Union;
	}
}
