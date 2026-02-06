#include "game.h"
#include "binary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_SIZE 32

void update(int* board, int size){
    int live_neighbors;
    int bit_val;
    int board_cpy[size];
    memcpy(board_cpy, board, size * sizeof(int));
    
    for(int line = 1 ; line <= size; line++){
        for(int bit = 1; bit <= INT_SIZE ; bit++){
            bit_val = get_bit(bit, line, board_cpy);
            live_neighbors = 0;

            //top row. left, middle, right bits.
            if(bit > 1        && line > 1    && get_bit(bit-1,line-1,board_cpy)) live_neighbors++;
            if(                  line > 1    && get_bit(bit  ,line-1,board_cpy)) live_neighbors++;
            if(bit < INT_SIZE && line > 1    && get_bit(bit+1,line-1,board_cpy)) live_neighbors++;

            //middle row. left, right bits.
            if(bit > 1        &&                get_bit(bit-1,line  ,board_cpy)) live_neighbors++;
            if(bit < INT_SIZE &&                get_bit(bit+1,line  ,board_cpy)) live_neighbors++;

            //bottom row. left, middle, right bits.
            if(bit > 1        && line < size && get_bit(bit-1,line+1,board_cpy)) live_neighbors++;
            if(                  line < size && get_bit(bit  ,line+1,board_cpy)) live_neighbors++;
            if(bit < INT_SIZE && line < size && get_bit(bit+1,line+1,board_cpy)) live_neighbors++;

            if(!bit_val && live_neighbors == 3)
                set_bit(bit, line, board);  
            else if(bit_val && (live_neighbors < 2 || live_neighbors > 3))
                clear_bit(bit, line, board);
        }     
    }
}

void display(int* board, int size){
    system("clear");
    for(int line = 1 ; line <= size; line++){
        for(int bit = 1; bit <= INT_SIZE ; bit++){
            int bit_val = get_bit(bit, line, board);
            if(bit_val)
                printf("# ");
            else
                printf("* ");
        }
        printf("\n");
    }
}

void initialize_board(char* file_name, int* board){
    FILE* fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("Could not open input file: %s.", file_name);
        return;
    }

    int row = 1;
    int col = 1;
    int file_in;
    while((file_in = getc(fp)) != EOF){
        if(file_in == ' ' || file_in == '\n') continue;
        else if(file_in == ','){
            row++;
            col = 0;
            continue;
        }

        if(file_in != '0')
            set_bit(col,row,board);
        else
            clear_bit(col,row,board);
        col++;
    }

    fclose(fp);
}