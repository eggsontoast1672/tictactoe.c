#include "board.h"

#include <stdio.h>
#include <stdlib.h>

void board_initialize(char *board)
{
    size_t i;

    for (i = 0; i < BOARD_LENGTH; ++i) {
        board[i] = BOARD_CHAR_EMPTY;
    }
}

void board_print(const char *board)
{
    printf("%c %c %c\n", board[0], board[1], board[2]);
    printf("%c %c %c\n", board[3], board[4], board[5]);
    printf("%c %c %c\n", board[6], board[7], board[8]);
}

void board_set_cell(char *board, size_t index, char piece)
{
    board[index] = piece;
}
