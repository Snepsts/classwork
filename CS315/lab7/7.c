#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 12
#define COLUMNS 12

void printMaze(int maze[ROWS][COLUMNS]);

void traverseMaze(int maze[ROWS][COLUMNS], int x, int y, char dir);

void generateMaze(int maze[ROWS][COLUMNS]);

int checkWalls(int maze[ROWS][COLUMNS]);

int main(){
	int maze[ROWS][COLUMNS] = {0}; //initialze them all to zero
	int x, y;

	srand(time(0)); //ensure number is random everytime

	generateMaze(maze);

	//x = 0; y = 2;

	//traverseMaze(maze, x, y, 'r');

	printMaze(maze);

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

void generateMaze(int maze[ROWS][COLUMNS]){
	int x, y, chance;
	char dir;

	//generate borders
	for(size_t i = 0; i < 12; i++){
		maze[i][0] = 7; //top row is # signs
		maze[i][11] = 7; //bottom row is # signs
		maze[0][i] = 7; //left column is # signs
		maze[11][i] = 7; //right column is # signs
	}

	//generate entrance
	printf("Generating entrance...\n");
	x = rand() % 4;
	if(x == 0){ //left side, x = 0 is the far left
		y = rand() % 10 + 1; //range 1 - 10
		dir = 'r';
	}else if(x == 1){ //top side
		y = 0; //y = 0 is the very top
		x = rand() % 10 + 1;
		dir = 'd';
	}else if(x == 2){ //right side
		x = 11; //x = 11 is the far right
		y = rand() % 10 + 1;
		dir = 'l';
	}else{ //bottom side
		y = 11; //y = 11 is the very bottom
		x = rand() % 10 + 1;
		dir = 'u';
	}

	maze[x][y] = 3; //3 represents the entrance

	/*	-1 = exit
		0 = open/unvisited
		1 = walled/cannot pass
		2 = current character spot (not used here)
		3 = entrance
		4 = unused
		5 = passage way
		6 = seen
		7 = cannot go over
	*/

	printf("Generating maze...\n");

	do{
		sleep(1);
		switch(dir){
		case 'r':
			if(maze[x+1][y] == 7)
				break;
			x++;
			break;
		case 'd':
			if(maze[x][y+1] == 7)
				break;
			y++;
			break;
		case 'l':
			if(maze[x-1][y] == 7)
				break;
			x--;
			break;
		case 'u':
			if(maze[x][y-1] == 7)
				break;
			y--;
			break;
		}

		maze[x][y] = 5;
		if(maze[x+1][y] == 0)
			maze[x+1][y] = 6;
		if(maze[x-1][y] == 0)
			maze[x-1][y] = 6;
		if(maze[x][y-1] == 0)
			maze[x][y-1] = 6;
		if(maze[x][y+1] == 0)
			maze[x][y+1] = 6;

		chance = rand() % 4;
		switch(chance){
		case 0:
			dir = 'r';
			break;
		case 1:
			dir = 'd';
			break;
		case 2:
			dir = 'l';
			break;
		case 3:
			dir = 'u';
			break;
		}
	}while(!checkWalls(maze));

	sleep(1); //ensure the exit rand calls have had a second before they're called
	//generate exit
	printf("Generating exit...\n");
	int isDone = 0;
	do{
		sleep(1); //just in case the while runs again
		x = rand() % 4;
		if(x == 0){ //left side, x = 0 is the far left
			y = rand() % 10 + 1; //range 1 - 10
			if(maze[x+1][y] == 5)
				isDone = 1;
		}else if(x == 1){ //top side
			y = 0; //y = 0 is the very top
			x = rand() % 10 + 1;
			if(maze[x][y+1] == 5)
				isDone = 1;
		}else if(x == 2){ //right side
			x = 11; //x = 11 is the far right
			y = rand() % 10 + 1;
			if(maze[x-1][y] == 5)
				isDone = 1;
		}else{ //bottom side
			y = 11; //y = 11 is the very bottom
			x = rand() % 10 + 1;
			if(maze[x][y-1] == 5)
				isDone = 1;
		}
	}while(!isDone);
	//the above while ensures the exit is not the same or next to the entrance

	maze[x][y] = -1; //-1 represents the exit

	//convert the walls back to normal
	for(int x = 0; x < ROWS; x++){
		for(int y = 0; y < COLUMNS; y++){
			if(maze[x][y] == 5)
				maze[x][y] = 0;
			if(maze[x][y] == 7)
				maze[x][y] = 1;
		}
	}
}

int checkWalls(int maze[ROWS][COLUMNS]){
	int isDone = 1;

	for(int x = 1; x < ROWS - 1; x++){
		int count = 0;
		for(int y = 1; y < COLUMNS - 1; y++){
			if(maze[x][y] == 6){ //if it's been seen but not decided on yet
				if(maze[x+1][y] == 5)
					count++;
				if(maze[x-1][y] == 5)
					count++;
				if(maze[x][y+1] == 5)
					count++;
				if(maze[x+1][y-1] == 5)
					count++;
			} //end if
			if(count >= 2) //if at least two surrounding blocks are walkable, we can close this one off.
				maze[x][y] = 7;
		} //end y for
	} //end x for

	for(int x = 1; x < ROWS - 1; x++){
		for(int y = 1; y < COLUMNS - 1; y++){
			if(maze[x][y] == 6 || maze[x][y] == 0)
				isDone = 0;
		}
	}

	return isDone;
}
