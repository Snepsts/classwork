#include <stdio.h>
#include <unistd.h>
#define ROWS 12
#define COLUMNS 12

void printMaze(int maze[ROWS][COLUMNS]);

void traverseMaze(int maze[ROWS][COLUMNS], int x, int y, char dir);

int main(){
	int maze[ROWS][COLUMNS] = {0}; //initialze them all to zero
	int x, y;

	//Predefined maze
	for(size_t i = 0; i < 12; i++){
		maze[i][0] = 1; //top row is # signs
		maze[i][11] = 1; //bottom row is # signs
	}

	for(size_t i = 0; i < 12; i++){
		if(i == 2) //left side with enterance
			maze[0][i] = 3;
		else
			maze[0][i] = 1;
	}

	for(size_t i = 0; i < 12; i++){
		if(i == 4) //right side with exit
			maze[11][i] = -1;
		else
			maze[11][i] = 1;
	}

	maze[4][1] = 1;
	maze[2][2] = 1; maze[4][2] = 1; maze[6][2] = 1; maze[7][2] = 1; maze[8][2] = 1; maze[9][2] = 1;
	maze[1][3] = 1; maze[2][3] = 1; maze[4][3] = 1; maze[9][3] = 1;
	maze[5][4] = 1; maze[6][4] = 1; maze[7][4] = 1; maze[9][4] = 1;
	maze[1][5] = 1; maze[2][5] = 1; maze[3][5] = 1; maze[5][5] = 1; maze[7][5] = 1; maze[9][5] = 1;
	maze[3][6] = 1; maze[5][6] = 1; maze[7][6] = 1; maze[9][6] = 1;
	maze[1][7] = 1; maze[3][7] = 1; maze[5][7] = 1; maze[7][7] = 1; maze[9][7] = 1;
	maze[9][8] = 1;
	maze[1][9] = 1; maze[2][9] = 1; maze[3][9] = 1; maze[4][9] = 1; maze[5][9] = 1; maze[7][9] = 1; maze[8][9] = 1; maze[9][9] = 1;
	maze[7][10] = 1;

	x = 0; y = 2;

	traverseMaze(maze, x, y, 'r');

	return 0;
}

void printMaze(int maze[ROWS][COLUMNS]){
	for(size_t y = 0; y < 12; y++){
		for(size_t x = 0; x < 12; x++){
			if(maze[x][y] == -1) //end
				printf(". ");
			else if(maze[x][y] == 3) //begin
				printf(". ");
			else if(maze[x][y] == 2){ //current position
				printf("X ");
				maze[x][y] = 0;
			}
			else if(maze[x][y] == 1) //wall
				printf("# ");
			else //open space
				printf(". ");
		} //end x loop
		printf("\n");
	} //end y loop

	sleep(1); //wait a second
	for(int i = 0; i < 100; i++) //clear the terminal so the next print looks dope
		printf("\n");
}

void traverseMaze(int maze[ROWS][COLUMNS], int x, int y, char dir){
	int isFinished = 0; //our end of maze value

	if(maze[x][y] == 3){ //initial point
		maze[x][y] = 2;
		printMaze(maze);
		maze[x][y] = 3; //set the value back to the beginning point

		if(x == 0)
			dir = 'r';
		else if(x == 11)
			dir = 'l';
		else if(y == 0)
			dir = 'd';
		else if(y == 11)
			dir = 'u';
		else
			dir = 'r';
	}
	else if(maze[x][y] == -1){
		maze[x][y] = 2;
		printMaze(maze);
		printf("You win!!!\n");
		isFinished = 1; //we have reached the end
	}
	else{
		maze[x][y] = 2;
		printMaze(maze);
	}

	switch(dir){
		case 'u':
			goto UP;
			break;
		case 'd':
			goto DOWN;
			break;
		case 'r':
			goto RIGHT;
			break;
		case 'l':
			goto LEFT;
			break;
	}

	while(!isFinished){ //Our search loop
	UP:
		if(maze[x+1][y] < 1){
			traverseMaze(maze, x+1, y, 'r');
			break; //ensure loop ends
		}
	LEFT:
		if(maze[x][y-1] < 1){
			traverseMaze(maze, x, y-1, 'u');
			break; //ensure loop ends
		}
	DOWN:
		if(maze[x-1][y] < 1){
			traverseMaze(maze, x-1, y, 'l');
			break; //ensure loop ends
		}
	RIGHT:
		if(maze[x][y+1] < 1){
			traverseMaze(maze, x, y+1, 'd');
			break; //ensure loop ends
		}
	} //end while
}
