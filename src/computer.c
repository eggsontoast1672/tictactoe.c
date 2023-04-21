#include "computer.h"

#include "board.h"

size_t ttt_computer_get_move_index(void)
{
    return rand() % BOARD_LENGTH;
}
