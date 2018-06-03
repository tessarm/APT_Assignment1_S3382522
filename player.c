/******************************************************************************
** Student name: 	Marco Tessari
** Student number: 	S3382522
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/
#include "board.h"
#include "player.h"
extern Player playerOne;
extern Position playerPos;
extern Cell board[BOARD_HEIGHT][BOARD_WIDTH];
extern Direction playerDir;


void initialisePlayer(Player player, Position position, Direction direction)
{/*Initialise the player, I cheated a little bit, changed it away from pointers and didn't do it 100% */
    playerOne.position = position;
	playerOne.direction = direction;
	playerOne.moves = 0;
	if(board[playerOne.position.y][playerOne.position.x] == 1){
		printf("Chosen square blocked, try again\n");
		getInitOptions();}
	else if(board[playerOne.position.y][playerOne.position.x] == 0){
		board[playerOne.position.y][playerOne.position.x] = 2;
		playGame();}
		
		}

void turnDirection(Player player, TurnDirection turnDirection)
{
    if(turnDirection == 0){ /* turn left*/
		if(playerOne.direction == NORTH ){
			playerOne.direction = WEST;}
		else if(playerOne.direction == EAST ){
			playerOne.direction = NORTH;}
		else if(playerOne.direction == SOUTH ){
			playerOne.direction = EAST;}
		else if(playerOne.direction == WEST ){
			playerOne.direction = SOUTH;}}
	if(turnDirection == 1){/* turn right*/
		if(playerOne.direction == NORTH ){
			playerOne.direction = EAST;}
		else if(playerOne.direction == EAST ){
			playerOne.direction = SOUTH;}
		else if(playerOne.direction == SOUTH ){
			playerOne.direction = WEST;}
		else if(playerOne.direction == WEST ){
			playerOne.direction = NORTH;}}	
			
	playGame();
}

Position getNextForwardPosition(Player player)
{
	Position nextPossiblePos;
	nextPossiblePos.y = playerOne.position.y; /* temporary variable to store the eventual position ofthe player*/
	nextPossiblePos.x = playerOne.position.x;
	/* getting where the player will go if they go forward*/
	if(playerOne.direction == NORTH ){
		nextPossiblePos.y -= 1;}
	else if(playerOne.direction == EAST ){
		nextPossiblePos.x += 1;}
	else if(playerOne.direction == SOUTH ){
		nextPossiblePos.y += 1;}
	else if(playerOne.direction == WEST ){
		nextPossiblePos.x -=1;}


	if(board[nextPossiblePos.y][nextPossiblePos.x] == 1){
		printf("Chosen square blocked, try again\n"); /* obstacle check*/
		void inGameOptions();}
	else if(nextPossiblePos.x > 9 || nextPossiblePos.x < 0 || nextPossiblePos.y > 9 || nextPossiblePos.y < 0){
		printf("Chosen square out of bounds, try again\n");/*out of bounds check */
		void inGameOptions();}
	else if(board[nextPossiblePos.y][nextPossiblePos.x] == 0){
		board[playerOne.position.y][playerOne.position.x] = 0;
		playerOne.position = nextPossiblePos;
		board[playerOne.position.y][playerOne.position.x] = 2;
		playerOne.moves += 1;
		 /*set the player one square forward if able to, then up the moves counter*/
		playGame();}
		
}
/*
void updatePosition(Player * player, Position position)
{
    player.position = position;
}
*/
void displayDirection(Direction direction)
{/* function to print the arrow pointing the right direction*/
	if(direction == 0 ){
		printf(DIRECTION_ARROW_OUTPUT_NORTH);}
	else if(direction == 1 ){
		printf(DIRECTION_ARROW_OUTPUT_EAST);}
	else if(direction == 2 ){
		printf(DIRECTION_ARROW_OUTPUT_SOUTH);}
	else if(direction == 3 ){
		printf(DIRECTION_ARROW_OUTPUT_WEST);}
	printf("|");
	
}

