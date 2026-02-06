#include "game.h"
#include "binary.h"
#include <unistd.h>
#define SIZE 32
#define INPUT_FILE "gof.txt"
#define REFRESH_PERIOD_MS 300
int main(int argc, char** argv) {
    int board[SIZE];
    initialize_board(INPUT_FILE, board);

    while(1){
        update(board, SIZE);
        usleep(REFRESH_PERIOD_MS * 1000);
        display(board, SIZE);
    }    
    return 0;
}

