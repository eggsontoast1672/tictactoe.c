#ifndef TTT_BOARD_H
#define TTT_BOARD_H

#include <stdlib.h>

#define BOARD_CHAR_EMPTY '.'
#define BOARD_LENGTH 9

void board_initialize(char *board);
void board_print(const char *board);
void board_set_cell(char *board, size_t index, char piece);

#endif
