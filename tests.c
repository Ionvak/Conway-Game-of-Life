#include <stdio.h>
#include "game.h"
#include "binary.h"
#define SIZE 16
#define INPUT_FILE "gof.txt"

int set_bit_test(){
    int tested[1] = {0};
    printf("%d\n", tested[0]);

    set_bit(1,1,tested);

    printf("%d\n", tested[0]);
    if(tested[0] == 1)
        return 1;
    else
        return 0;
}

int clear_bit_test(){
    int tested[1] = {1};
    printf("%d\n", tested[0]);

    clear_bit(1,1,tested);

    printf("%d\n", tested[0]);
    if(tested[0] == 0)
        return 1;
    else
        return 0;
}

int main(int argc, char** argv) {
    printf("Set Bit Test Result: %d\n",set_bit_test());
    printf("Clear Bit Test Result: %d",clear_bit_test());

    return 0;
}