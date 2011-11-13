/**
 * @file stack.c
 * @details Stack
 * @version 0.1
 * @date 2011-11-13
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include "../library/stack.h"

int main()
{
    printf("Stack start");
    Stack* myStack;
    initialize(myStack);
    push(myStack , 1.23);
    push(myStack , 4.56);
    push(myStack , 7.890);

    StackPrint(myStack);
    printf("\nStack end");
    getch();
    return 0;
}
