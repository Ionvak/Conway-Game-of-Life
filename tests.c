#include <stdio.h>
#include "game.h"
#include "binary.h"
#define SIZE 16
#define INT_SIZE 32
#define INPUT_FILE "gof.txt"

int set_bit_test(){
    int tested[1] = {0};

    set_bit(1,1,tested);

    if(tested[0] == 1)
        return 1;
    else
        return 0;
}

int clear_bit_test(){
    int tested[1] = {1};

    clear_bit(1,1,tested);

    if(tested[0] == 0)
        return 1;
    else
        return 0;
}

void get_bit_test(){
    int tested[1] = {67};

    printf("Bit Read Test\nActual Value:   00000000000000000000000001000011\n");
    printf("get_bit result: ");
    for(int i = INT_SIZE; i >= 1 ; i--)
        printf("%d", get_bit(i,1,tested));
    printf("\n");
}

void test_display(){
    int board[SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    display(board, SIZE);
}

void test_update(){
    int board[SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    printf("original board:\n");
    display(board, SIZE);
    printf("updated board:\n");
    update(board, SIZE);
    display(board, SIZE);
}

int main(int argc, char** argv) {
    printf("Set Bit Test Result: %d\n",set_bit_test());
    printf("Clear Bit Test Result: %d\n",clear_bit_test());
    get_bit_test();
    test_display();
    test_update();
    return 0;
}