#include <stdio.h>
#include <stdlib.h>

#define BOARD_CHAR_EMPTY '.'
#define BOARD_LENGTH 9

void board_initialize(char *board);
void board_print(const char *board);
void board_set_cell(char *board, size_t index, char piece);

int main(void)
{
    char board[BOARD_LENGTH];

    board_initialize(board);

    board_set_cell(board, 2, 'X');
    board_set_cell(board, 4, 'X');
    board_set_cell(board, 6, 'x');

    board_print(board);

    return 0;
}

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
