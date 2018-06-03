/******************************************************************************
** Student name: 	Marco Tessari
** Student number: 	S3382522
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"
extern int xCoord;
extern int yCoord;
extern Cell board[BOARD_HEIGHT][BOARD_WIDTH];
extern Direction playerDir;
extern Player playerOne;
extern Position playerPos;
extern TurnDirection playerTurn;
void playGameOptions(){
/* printout of all options*/

printf("\nYou can use the following commands to play the game\n");
printf("Load <g>\n");
printf("    g: number of the game board to load\n");
printf("Init <x>,<y>,<direction>\n");
printf("    x: horizontal position of the car on the board (between 0 & 9\n");
printf("    y: vertical position of the car on the board (betweenn 0 & 9)\n");
printf("    direction: direction of the car's movement ( north, east, south, west)\n");
printf("forward (or f)\n");
printf("turn_left (or l)\n");
printf("turn_right (or r)\n");
printf("quit\n");
getInitialOptions();
}

/* menu for different stages in the game, most of the others follow the same formula, treat these comments as the same for similar code*/
void getInitialOptions(){
    char user_input[81], *token[80];
    user_input[0] = 0;
	int i = 0;

    while (strlen(user_input) <= 1 || strlen(user_input) > 82) {
        fgets(user_input, sizeof(user_input), stdin); /* fgets statement to start the menu*/
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len-1] == '\n') {
        user_input[--len] = '\0';} /* shaves off the /n at the ends of the stdin stream input*/
	}

/* strtok to tokenize the string from fgets and make it usable for a menu*/
    token[0] = strtok(user_input, " ");
    while (token[i] != NULL) {
        i++;
        token[i] = strtok(NULL, " ");
    }
/* series of if statements to figure out which option the user has selected*/
if(strcmp(token[0], "Load") == 0 || strcmp(user_input,"Load") == 0){
	if(strcmp(token[1], "1") == 0){
		loadBoard(board, BOARD_1);
		displayBoard(board, NULL);
		getInitOptions();}
	else if(strcmp(token[1], "2") == 0){
		loadBoard(board, BOARD_2);
		displayBoard(board, NULL);
	getInitOptions();}
	else{
		printf("Invalid Input.\n");
		playGameOptions();}
	playGameOptions();}
else if(strcmp(token[0], "Init") == 0 || strcmp(user_input,"Init") == 0){
	xCoord = atoi(token[1]);
	yCoord = atoi(token[2]);
	if(xCoord == 1 || xCoord ==2 && yCoord == 1 || yCoord == 2){
		/*init option checks */
		}
	else{/* sends them back to the start if they put an invalid input in*/
		printf("Please enter valid Input: Init,x,y\n");
		getInitialOptions();}
		}
else if(strcmp(token[0], "quit") == 0 || strcmp(user_input,"quit") == 0){
		main();} /* takes them home if they quit*/
else{
	printf("Invalid Input.\n");
	playGameOptions();}

}

void getInitOptions(){
	printf("Please initialize player position\n");
	int i = 0;
    char user_input[81], *token[80];
    user_input[0] = 0;
    while (strlen(user_input) <= 1 || strlen(user_input) > 82) {
        fgets(user_input, sizeof(user_input), stdin);
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len-1] == '\n') {
        user_input[--len] = '\0';}
	}
    token[0] = strtok(user_input, " ");
    while (token[i] != NULL) {
        i++;
        token[i] = strtok(NULL, " ");
    }

if(strcmp(token[0], "Init") == 0 || strcmp(user_input,"Init") == 0){
	xCoord = atoi(token[1]);
	yCoord = atoi(token[2]);
	if(xCoord >= 10 || xCoord < 0 || yCoord >= 10 || yCoord < 0){
		printf("Please enter valid Input: Init,x,y,direction\n");
		getInitOptions();}
	if(strcmp(token[3], "north") == 0 ){ /* checks what direction the user selected for the car to face*/
		playerDir = 0;}
	else if(strcmp(token[3], "east") == 0 ){
		playerDir = 1;}
	else if(strcmp(token[3], "south") == 0 ){
		playerDir = 2;}
	else if(strcmp(token[3], "west") == 0 ){
		playerDir = 3;}}		
	playerPos.x = xCoord; 
	playerPos.y = yCoord;
	initialisePlayer(playerOne, playerPos, playerDir);
	/*do the thing*/

}	

void inGameOptions(){ /* menu for when the user is playing them game, trimmed down options*/
	printf("forward (or f)\n");
	printf("turn_left (or l)\n");
	printf("turn_right (or r)\n");
	printf("quit\n");
int i = 0;
    char user_input[81], *token[80];
    user_input[0] = 0;


    while (strlen(user_input) <= 1 || strlen(user_input) > 82) {
        fgets(user_input, sizeof(user_input), stdin);
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len-1] == '\n') {
        user_input[--len] = '\0';}
	}


    token[0] = strtok(user_input, " ");
    while (token[i] != NULL) {
        i++;
        token[i] = strtok(NULL, " ");
    }
/* checks to see what player wants to do*/
if(strcmp(token[0], "forward") == 0 || strcmp(user_input,"forward") == 0 || strcmp(token[0],"f") == 0 || strcmp(user_input,"f") == 0){
	getNextForwardPosition(playerOne);} /* single letter inputs don't do anything but you get to retry the input */
else if(strcmp(token[0], "turn_left") == 0 || strcmp(user_input,"turn_left") == 0 || strcmp(token[0],"l") == 0 || strcmp(user_input,"l") == 0){
	playerTurn = TURN_LEFT;
	turnDirection(playerOne,playerTurn);}
else if(strcmp(token[0], "turn_right") == 0 || strcmp(user_input,"turn_right") == 0 || strcmp(token[0],"r") == 0 || strcmp(user_input,"r") == 0){
	playerTurn = TURN_RIGHT;
	turnDirection(playerOne,playerTurn);}
else if(strcmp(token[0], "quit") == 0 || strcmp(user_input,"quit") == 0){
	printf("Returning to main menu \n\n");
	printf("%d move commands issued\n\n",playerOne.moves); /* goes home, and prints how many forward moves have succesfully been made*/
    main();}
else{
	printf("Invalid input, try again\n");

}
}
void playGame()
{
	int playNumber = 1;
	while(playNumber == 1){
	displayBoard(board, NULL);
	inGameOptions();
	}
/* loop to play the game once the player position is initialized
	can be exitied by using the quit command so it isn't infinite*/
   /* */
}

