/******************************************************************************
** Student name: 	Marco Tessari
** Student number: 	S3382522
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "board.h"
extern Player playerOne;

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	/* iterates through board and fills it with empty cells*/
	int i;
	int j;
    for(i = 0; i < 10; i++)
    {
    for(j = 0; j < 10; j++)
        {
        board[i][j] = 0;
        }
    }
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
	/* iterates through board, and copies the boardToLoad 1 for 1 into board*/
	int i;
	int j;
    for(i = 0; i < 10; i++)
    {
    for(j = 0; j < 10; j++)
        {
        board[j][i] = boardToLoad[j][i];
        }
    }
}
/*
Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
	didn't need these??
     put the player in the array position
    return FALSE;
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	if(board[playerOne.position.y][playerOne.position.x] == 1){
		printf("Chosen square blocked, try again\n");
		inGameOptions();}
	else if(board[playerOne.position.y][playerOne.position.x] == 0){
		board[playerOne.position.y][playerOne.position.x] = 2;
}
*/
void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
int i;
int j;
char boardSpace = ' '; /* char that will be used to represent blocked or empty tiles*/
printf("| |0|1|2|3|4|5|6|7|8|9|\n"); /* top line*/
for(i = 0; i < 10; i++) /*iterate through each cells and print a char that corresponds to the entry */
    {
    int verticalNumber = i;
    printf("|%i|", verticalNumber);
    for(j = 0; j < 10; j++){
        
        if(board[i][j] == 0){
		boardSpace = ' ';
		printf("%c|", boardSpace);}
        else if(board[i][j] == 1){
		boardSpace = '*';
		printf("%c|", boardSpace);}
        else if(board[i][j] == 2){
		displayDirection(playerOne.direction);} /*if it's a player in the cell, send it off to a function that prints the correspondign arrow		*/

       
    }
    printf("\n");
    }

}
