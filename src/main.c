#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_CHAR_COMPUTER 'O'
#define BOARD_CHAR_EMPTY '.'
#define BOARD_CHAR_PLAYER 'X'
#define BOARD_SIZE 9
#define BUFFER_SIZE 1024

typedef enum Turn {
    TURN_COMPUTER,
    TURN_PLAYER
} Turn;

void board_init(char *board);
int board_is_full(const char *board);

int main(void)
{
    size_t i;
    char player_input_buffer[BUFFER_SIZE];
    size_t player_move_index;
    char board[BOARD_SIZE];
    size_t computer_move_index;
    Turn turn = TURN_PLAYER;

    srand(time(NULL));
    board_init(board);
    while (1) {
        if (board_is_full(board)) {
            exit(0);
        }
        if (turn == TURN_PLAYER) {
            if (fgets(player_input_buffer, BUFFER_SIZE, stdin) == NULL) {
                fprintf(stderr, "Failed to get string from stdin\n");
                exit(1);
            }
            player_move_index = atoi(player_input_buffer);
            if (player_move_index < BOARD_SIZE) {
                board[atoi(player_input_buffer)] = BOARD_CHAR_PLAYER;
            }
            turn = TURN_COMPUTER;
        } else {
            do {
                computer_move_index = rand() % BOARD_SIZE;
            } while (board[computer_move_index] != BOARD_CHAR_EMPTY);
            board[computer_move_index] = BOARD_CHAR_COMPUTER;
            turn = TURN_PLAYER;
        }
        printf("%c %c %c\n", board[0], board[1], board[2]);
        printf("%c %c %c\n", board[3], board[4], board[5]);
        printf("%c %c %c\n", board[6], board[7], board[8]);
    }
    return 0;
}

void board_init(char *board)
{
    size_t i;

    for (i = 0; i < BOARD_SIZE; ++i)
        board[i] = BOARD_CHAR_EMPTY;
}

int board_is_full(const char *board)
{
    size_t i;

    for (i = 0; i < BOARD_SIZE; ++i)
        if (board[i] == BOARD_CHAR_EMPTY)
            return 0;
    return 1;
}
