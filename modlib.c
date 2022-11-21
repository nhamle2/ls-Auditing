#include <stdio.h>
#include "func.h"

int main(int c, char **args){
    int num = checkls(args[1], args[2]);

    if (num ==0)
        printf("\n");
    return 0;
}
