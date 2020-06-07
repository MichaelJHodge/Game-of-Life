
// Conway's Game of Life! //


// In the Game of Life, there is a grid that contains cells. In the beginning,
// each cell is either "dead" or "alive." The cells then update their own liveness
// in accordance to 4 rules, producing complex behavior:

// 1. Any live cell with 0 or 1 live neighbors becomes dead due to underpopulation
// 2. Any live cell with 2 or 3 live neighbors stays alive because its neighborhood is suitable
// 3. Any live cell with more than 3 live neighbors becomes dead due to overpopulation
// 4. Any dead cell with exactly 3 live neighbors becomes alive from reproduction



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void StartProgram(int height, int width);
char* create_state(int height, int width);
double GetRandomDouble(double min, double max);
void clear_screen(int height, int width, char* RandomState);
int count_neighbors(int height, int width, int x, int y, char* RandomState);
char* next_board_state(int height, int width, char* previous_state);


  int main(int argc, char* argv[])
  {
      int width = atoi(argv[1]);
      if(width <= 0)
      {
        printf("Width must be greater than 0. You put %d\n", width);
        return -1;
      }
      width+=2; //Creates a buffer

      int height = atoi(argv[2]);
      if(height <= 0)
      {
        printf("Height must be greater than 0. You put %d\n", height);
        return -1;
      }
      height+=2; //Creates a buffer

      StartProgram(height, width);
  }

  void clear_screen(int height, int width, char* RandomState)
  {
      printf("\033[H\033\[J");
      for(int i = 1; i < height - 1; i++)
      {
          for(int j = 1; j < width - 1; j++)
          {
            printf("%c ", *(RandomState + i*width + j));
          }
          printf("\n");
      }
  }

  int count_neighbors(int height, int width, int x, int y, char* RandomState)
  {
      int counter = 0;
      int pivot = y * width + x;

      for(int i = -1; i <= 1; i++)
       {
           for(int j = -1; j <= 1; j++)
           {
               char c = *(RandomState + pivot + (i*width) + j);

               if(c == '*') counter++;
           }
       }
       return counter;
  }

  char* next_board_state(int height, int width, char* previous_state)
  {
      char* current_state = calloc(height*width, sizeof(int));
      if(current_state == NULL)
      return NULL;

      for(int i = 1; i < height - 1; i++)
      {
            for(int j = 1; j < width - 1; j++)
            {
                int alive = count_neighbors(width,height,j,i,previous_state);
                char cell = *(previous_state+i*width+j);
                if(cell == '*') alive--;
                *(current_state+i*width+j) = cell;

                if(alive < 2)
                {
                    *(current_state+i*width+j) = ' ';
                }
                else if((alive == 2 || alive == 3) && cell == '*')
                {
                    *(current_state+i*width+j) = '*';
                }
                else if(alive > 3 && cell == '*')
                {
                    *(current_state+i*width+j) = ' ';
                }
                else if(alive == 3 && cell == ' ')
                {
                    *(current_state+i*width+j) = '*';
                }
            }
        }

        return current_state;
  }

  void StartProgram(int height, int width) //Start the program
  {
      puts("Starting the Game of Life!");
      char* RandomState = create_state(height, width);
      if(RandomState == NULL) return;
      clear_screen(height, width, RandomState);

      while(1)
        {
            char* next_iteration = next_board_state(height, width, RandomState);

            free(RandomState);
            RandomState = next_iteration;
            clear_screen(height, width, RandomState);
            usleep(1000000);
        }
  }

  double GetRandomDouble(double min, double max) //Get a random decimal
  {
      return ((double)rand()/RAND_MAX)*(max-min)+min;
  }

  char* create_state(int height, int width)
  {
      char* RandomState = (char*)calloc(height*width, sizeof(char));
      if(RandomState == NULL)
        return NULL;

      for(int i = 1; i < height - 1; i++)
      {
          for(int j = 1; j < width - 1; j++)
          {
            if(GetRandomDouble(0.0,1.0) <= 0.33)
            {
              *(RandomState + i * width + j) = '*';
            }
            else
            {
              *(RandomState + i * height + j) = ' ';
            }
          }
        }
        return RandomState;
  }
