/*
 * Written by Alexander Yauchler => terminatedNULL | 7/8/2024
 *
 * This is an adaptation of the BFS search algorithm, 
 * adapted to locate an edge, or detect if there is no path to one.
 */

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define QUEUE_MAX 100

// Represents a position and if it has been visited
typedef struct Point {
  int x;
  int y;
} Point;

// Function Prototypes
unsigned int boundsCheck(const int x, const int y);
void push(Point* pos);
void pop();

// Global queue variables
Point* queue[QUEUE_MAX];
int front = 0;
int back = 0;

// Global maps
Point* pMap[WIDTH][HEIGHT] = {};
const char map[WIDTH][HEIGHT] = {
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 0, 0, 0, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
  {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
  {0, 1, 1, 1, 0, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Positions to check for graph connections
const int positions[4][2] = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int main() { 
  Point startPos = { 2, 1 };
  push(&startPos);

  while(front != back) {
    Point currPoint = *queue[front];
    pop();

    for(size_t i = 0; i < 4; i++) {
      // Skip out-of-bounds points
      if(!boundsCheck(currPoint.x + positions[i][1], currPoint.y + positions[i][0])) { continue; }

      if(
        (currPoint.x == 0 || currPoint.x == (WIDTH - 1)
         || currPoint.y == 0 || currPoint.y == (HEIGHT - 1))
         && map[currPoint.x][currPoint.y] == 1
      ) {
        printf("Path exists! [ %d, %d ]\n", currPoint.x, currPoint.y);
        return 1;
      }
      
      if( // Check that the point is 1. A valid path 2. Not null 3. Not visited
        map[currPoint.x + positions[i][1]][currPoint.y + positions[i][0]]
         && pMap[currPoint.x + positions[i][1]][currPoint.y + positions[i][0]] == NULL
      ) {
        Point* newPoint = (Point*)malloc(sizeof(Point));
        newPoint->x = currPoint.x + positions[i][1];
        newPoint->y = currPoint.y + positions[i][0];
        push(newPoint);
      }
    }
  }

  printf("Path does not exist!\n");
  return -1;
}

// Checks for an out-of-bounds array access
unsigned int boundsCheck(const int x, const int y) {
  return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

// Pushes a value onto the end of the global queue
void push(Point* pos) {
  pMap[pos->x][pos->y] = pos;
  queue[back] = pos;
  back = (back + 1) % QUEUE_MAX;
}

// Removes the front value from the global queue
void pop() {
  queue[front] = NULL;
  front = (front + 1) % QUEUE_MAX;
}
