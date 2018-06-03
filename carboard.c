/******************************************************************************
** Student name: 	Marco Tessari
** Student number: 	S3382522
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

/*
Instructions:
Commands are literal, they only work with the formatting shown, except for the first menu that requires 1,2 or 3
known issue that a non int in first menu causes infinite loop.
known issue that the f,r,l commands do not work

 */



#include "carboard.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int xCoord;
int yCoord;
Cell board[BOARD_HEIGHT][BOARD_WIDTH];
Direction playerDir;
Player playerOne;
Position playerPos;
TurnDirection playerTurn;
/* global variable declarations*/
int main()
/* loop for main menu, using scanf because it was easier for this, fgets used later. if quit is chosen
the loop ends, and the program puts a goodbye message in and ends*/
{
	int loopnumber = 1;
	while(loopnumber == 1){
		int number = 4;
		printf("Welcome to Car Board\n");
		printf("--------------------\n");
		printf("1. Play game\n");
		printf("2. Show student's Information\n");
		printf("3. Quit\n\n");
		printf("Please enter your choice:");
		scanf("%d", &number);
		if(number == 1){
			displayBoard(board, NULL);
			playGameOptions();}
		else if(number == 2){
		showStudentInformation();}
		else if(number == 3){
		loopnumber = 0;}
		else{
		printf("Try again");}
	}
    printf("Good bye! \n\n");
	exit(0);
    return EXIT_SUCCESS;
	
}

void showStudentInformation()
{
	/*requiring the use of defined variables for name required me to use extra
	printf's to get the name:, no, email in*/
    
    printf("Name: ");
	printf(STUDENT_NAME);
    printf("\nNo: \n");
	printf(STUDENT_ID);
    printf("\nEmail: ");
	printf(STUDENT_EMAIL);
	printf("\n\n");
}

