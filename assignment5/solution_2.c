#include<stdio.h>
#define NCOLS 4

void filterStudents(int students[][NCOLS], int minAge, int minYear, int minGrade);


int main(void){
	int students[5][4] = {{1,18,11,90}, {2,16,10,75}, {3,15,9,85}, {4,10,10,60}, {5,11,9,60}};
	int minAge, minYear, minGrade;
	printf("Enter filtering parameters: ");
	scanf("%d %d %d", &minAge, &minYear, &minGrade);
	filterStudents(students, minAge,  minYear, minGrade);
	return 0;
}

void filterStudents(int students[][NCOLS], int minAge, int minYear, int minGrade){
	int i;
	for (i = 0; i < 5; i++){
		if ((minAge == -1 || students[i][1] >= minAge) &&
            	    (minYear == -1 || students[i][2] >= minYear) &&
                    (minGrade == -1 || students[i][3] >= minGrade)) {
			printf("%d ", students[i][0]);
		}
	}
	printf("\n");
}
	
