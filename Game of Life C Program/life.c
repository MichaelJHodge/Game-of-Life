// Conway's Game of Life! //

#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10
#define ALIVE 1
#define DEAD 0


//Starts the board to an inactive state
void initializeBoard(int board[HEIGHT][WIDTH]) {
  int height, width;

  for (height = 0; height < HEIGHT; height++)
    for (width = 0; width < WIDTH; width++)
        board[height][width] = DEAD;
}

// Prints the board
void printBoard(int board[HEIGHT][WIDTH]){
  int height, width;

  for (height = 0; height < HEIGHT; height++) {
    for (width = 0; width < WIDTH; width++) {
        if (board[height][width] == ALIVE) {
            printf("X");
        } else {
            printf("-");
          }
      }
      printf("\n");
    }
}

//Counts neighbors
int verify_neighbors(int board[HEIGHT][WIDTH], int x, int y) {
    int height, width, count = 0;

    for (height = -1; height <= 1; height++)
        for (width = -1; width <= 1; width++)
            if (!(height == 0 && width == 0) &&
                (x + height >= 0 && x + height < HEIGHT) &&
                (y + width >= 0 && y + width < WIDTH) &&
                (board[x + height][y + width] == ALIVE))
                count++;
    return count;
}

//Counts active cells
int verify_active(int board[HEIGHT][WIDTH]) {

    int height, width, count = 0;

    for (height = 0; height < HEIGHT; height++)
        for (width = 0; width < WIDTH; width++)
            if (board[height][width] == ALIVE)
            count++;
    return count;
}

//Copies original board to the next board to start from a clean slate
void copy_board_state(int original_board[HEIGHT][WIDTH], int next_board[HEIGHT][WIDTH])
{

    int height, width;

    for (height = 0; height < HEIGHT; height++)
        for (width = 0; width < WIDTH; width++)
            next_board[height][width] = original_board[height][width];
}

//Changes current board to next board
void next_iteration(int board[HEIGHT][WIDTH])
{

    int height, width;
    int next_board[HEIGHT][WIDTH];
    initialize_board(next);

    for (height = 0; height < HEIGHT; height++)
        for (width = 0; width < WIDTH; width++)
            iterate_cell(board, next, height, width);
    copy_board(next_board, board);
}
