/* file:        maze.c                                              */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        20-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program solves a maze with the shortest path possible */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solveMaze(char maze[], int i, int n){
	if(maze[i]=='#'){
		if(maze[i+1]=='E'){
			maze[i+1]='#';
		} else { // Search possible paths in the maze
			if(maze[i+n]=='.'){
				maze[i+n]='#';
				solveMaze(maze, i+n, n);
			} else {
				if(maze[i+1]=='.'){
				maze[i+1]='#';
				solveMaze(maze, i+1, n);
				} else {
					if(i>n&&maze[i-n]=='.'){
						maze[i-n]='#';
						solveMaze(maze, i-n, n);
					} else {
						if(i>0&&maze[i-1]=='.'){
							maze[i-1] ='#';
							solveMaze(maze, i-1, n);
				} else { // If the path is not correct, 'walk' back and fill up path

		maze[i]='*';
		if(maze[i+n]=='#'){
			solveMaze(maze, i+n, n);
		} else {
			if(maze[i+1]=='#'){
				solveMaze(maze, i+1, n);
			} else {
				if(i>n&&maze[i-n]=='#'){
					solveMaze(maze, i-n, n);
				} else {
					if(i>0&&maze[i-1]=='#'){
						solveMaze(maze, i-1, n);
					}
				}
			}
		}
				}

					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	char maze[400];
	int m, n;
	int start = 0;
	char ch;

	scanf("%d %d", &m, &n);
	for(int i=0;i<n*m;i++){ // Initialize array and determine start point
		scanf(" %c",&ch);
		maze[i] = ch;
		if(maze[i]=='S'){
			maze[i]='#';
			start = i;
		}
	}

	solveMaze(maze, start, n);

	for(int i=0;i<n*m;i++){ // Print the correctly formatted maze
		if(maze[i]=='*'){
			maze[i]='.';
		}
		ch = maze[i];
		printf("%c",ch);
		if((i+1)%n==0){
			printf("\n");
		}
	}

	return 0;
}