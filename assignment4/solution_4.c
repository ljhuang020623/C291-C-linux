#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int rollDice(void);
int getSum(int a,int b);
void checkCraps(int score);


int gamestate = 0;
int point = 0;

int main(void){
	srand(time(NULL));	
	char ans;
	int a, b, score;
	printf("Would you like to play a game of craps?Type y for yes or n for no:");
	scanf("%c", &ans);
	if (ans == 'y'){
		printf("Dice is rolling ....\n");
		a = rollDice();
		b = rollDice();
		printf("Score on dice are: %d and %d\n",a,b); 
		score = getSum(a,b);
		checkCraps(score);
		point = score;
		while (gamestate == 3){
			printf("Dice is rolling ....\n");
			a = rollDice();
			b = rollDice();
			printf("Score on dice are: %d and %d\n",a,b);
			score = getSum(a,b);
			if (score == point){
				printf("Consecutive same sum.you won!!\n");
				break;
			}else if (score == 7){
				printf("you lost!!\n");
				break;
			}
		}
	}	
	return 0;
}

int rollDice(void){
	return 1 + (rand() %  6);
}

int getSum(int a, int b){
	int score = a + b;
	printf("Sum is %d\n",score);
	return score;
}
void checkCraps(int score){
	if(score == 7 || score == 11){
		printf("Congratulations you won!!!\n");
		gamestate =  1;
	}else if (score == 2 || score == 3 || score == 12){
		printf("Sorry you have lost and House won!!!\n");
		gamestate = 2;
	}else{
		printf("Your point is %d ...\n", score);
		gamestate = 3;
	}
}
