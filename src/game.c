#include "game.h"

#include <stdlib.h>
#include <time.h>

#include "board.h"
#include "computer.h"

void ttt_game_initialize(TttGameState *state)
{
    srand(time(NULL));
    board_initialize(state->board);
}

void ttt_game_computer_move(TttGameState *state)
{
    size_t index = ttt_computer_get_move_index();

    board_set_cell(state->board, index, TTT_COMPUTER_CELL_CHAR);
}
