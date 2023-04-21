#ifndef TTT_GAME_H
#define TTT_GAME_H

#include "board.h"

typedef struct TttGameState {
    char board[BOARD_LENGTH];
} TttGameState;

void ttt_game_initialize(TttGameState *state);

void ttt_game_computer_move(TttGameState *state);
void ttt_game_player_move(TttGameState *state);

void ttt_game_draw_board(const TttGameState *state);

#endif
