#include "ranlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BOARD_SIZE 8
#define TILE_SIZE 42
#define TILE_TYPES 5

const char tile_chars[TILE_TYPES] = {'#', '@', '$', '%', '&'};

char board[BOARD_SIZE][BOARD_SIZE];


// create a small function to randomly generate the tiles
char random_tile()
{
    return tile_chars[rand() % TILE_TYPES];

}

void init_board()
{
    for (int y = 0; y < BOARD_SIZE; y ++)
    {
        for (int x = 0; x < BOARD_SIZE; x ++){
            board [y][x] = random_tile();
        }
    }
}