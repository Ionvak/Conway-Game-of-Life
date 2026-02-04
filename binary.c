#include "binary.h"

void set_bit(int x, int y, int* board){
    int flag = 1;
    flag << x - 1;

    board[y-1] = board[y-1] | flag;
}

void clear_bit(int x, int y, int* board){
    int flag = 1;
    flag << x - 1;
    flag = ~flag;

    board[y-1] = board[y-1] & flag;
}

int get_bit(int x, int y, int* board){
    int flag = 1;
    flag << x - 1;

    if(flag & board[y-1])
        return 1;
    else 
        return 0;
}