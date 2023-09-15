#include<stdio.h>

int main(void){
	char backLetter, frontLetter;
	frontLetter = 'a';
	for (char frontLetter = 'a'; frontLetter <= 'z'; frontLetter ++){
		for (char backLetter = 'a'; backLetter <= 'z'; backLetter++ ){
			printf("www.%c%c.com\n", frontLetter, backLetter);
		}	
	}
	return 0;
}
