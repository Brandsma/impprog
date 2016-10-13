/* file:        maze.c                                              */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        13-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program finds the shortest path in a maze      */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

char **makeCharArray2D(char width, char height) {
	unsigned char row, **arr;

	arr = safeMalloc(height*sizeof(char *));
	arr[0] = safeMalloc(width*height*sizeof(char));

	for (row=1; row < height; row++) {
		arr[row] = arr[row-1] + width;
	}
	return arr;
}

void destroyCharArray2D(char **arr) {
	free(arr[0]);
	free(arr);
}

void findPath(int maze**, int y, int x, int yGoal, int xGoal) {
	if(y == yGoal && x == xGoal) {
		return 1;
	}
	if()
}

int main(int argc, char *argv[]) { 
	int m, n;
	int x1, y1, xEnd, yEnd;
	int xep*;
	int yep*;
	int mp*;
	int np*;
	scanf("%d %d", &m, &n);
	char **maze = makeCharArray2D(m, n);

	mp = &m;
	np = &n;

	for(int y = 0; y < m; y++) { // Initialize array
		for(int x = 0; x < n; x++) {
			scanf("%c", &maze[y][x]);
			if(maze[y][x] == 'S') {
				x1 = x;
				y1 = y;
			}
			if(maze[y][x] == 'E') {
				xEnd = x;
				yEnd = y;
			}
		}
	}

	findPath(maze**, y1, x1, yEnd, xEnd);

	destroyCharArray2D(maze);
	return 0;
}
