#include "game.h"
#include "binary.h"
#define SIZE 16
#define INPUT_FILE "gof.txt"
int main(int argc, char** argv) {
    int board[SIZE];
    initialize_board(board, INPUT_FILE);

    while(1){
        update(board, SIZE);
        display(board, SIZE);
    }    
    return 0;
}

