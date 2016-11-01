/* file:        maze.c                                              */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        13-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program solves a maze with the shortest path possible */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void *safeMalloc(int n) {
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

char **makeCharArray2D(int width, int height) {
  char row, **arr;

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

char **solveMaze(char **maze, int x, int y, int m, int n) {
  if(maze[y][x] == 'E') {
    maze[y][x] = '#';
    return maze;
  }
  printf("3.y:%d \t x:%d\n", y, x);
  if(!(y-1 < 0 || x-1 < 0 || y+1 >= m || x+1 >= n)) {
    printf("option 1\n");
   if(maze[y-1][x] == '.' || maze[y-1][x] == 'E') { // North
     maze[y][x] = '#';
     return solveMaze(maze, x, y-1, m, n);
    }
  }
  if(!(y-1 < 0 || x-1 < 0 || y+1 >= m || x+1 >= n)) {
    printf("option 2\n");
    if(maze[y][x-1] == '.' || maze[y][x-1] == 'E') { // West
      maze[y][x] = '#';
      return solveMaze(maze, x-1, y, m, n);
    }
  }
  if(!(y-1 < 0 || x-1 < 0 || y+1 >= m || x+1 >= n)) {
    printf("option 3\n");
    if(maze[y][x+1] == '.' || maze[y][x+1] == 'E') { // East
      maze[y][x] = '#';
      return solveMaze(maze, x+1, y, m, n);
    }
  }
  if(y+1 >= m) {
    printf("option 4\n");
    maze[y][x] = '#';
  	return solveMaze(maze, x, y+1, m, n); 
  }
}

int main(int argc, char *argv[]) {
  int m, n;
  scanf("%d %d", &m, &n);
  char ch;
  char **maze = makeCharArray2D(m, n);
  
  for(int y = 0; y < m; y++) { // Initialize array
    for(int x = 0; x < n; x++) {
     // printf("1.y:%d \t x:%d\n", y, x);
      scanf("%c", &ch);
      maze[y][x] = ch;
    }
  }

  for(int y = 0; y < m; y++) { // Search start point of maze
    for(int x = 0; x < n; x++) {
      printf("2.y:%d \t x:%d\n", y, x);
      if(maze[y][x] == 'S') {
        maze = solveMaze(maze, x, y, m, n);
        goto labelbreak;
      }
    }
  }

  labelbreak:

  for(int y = 0; y < m; y++) { // Print solved array 
    for(int x = 0; x < n; x++) {
      printf("%c", maze[y][x]);
    }
  }

  for(int y = 0; y < n; y++) {
    if(y%2) {
      printf("-");
    } else {
      printf("+");
    }
  }

  destroyCharArray2D(maze);
  return 0;
}