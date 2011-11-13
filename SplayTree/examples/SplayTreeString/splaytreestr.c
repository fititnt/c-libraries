/**
 * @file splaytreestr.c
 * @details ANSI-C Splay Tree Library
 *          String (255 chacaters, via STRMAX constant)
 * @version 0.1
 * @date 2011-11-13
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../library/splaytreestr.h"

int main()
{
    printf("Splay Tree (Data type String) start \n");
    struct SplayTreeStr *node = malloc(sizeof(SplayTreeSN));
    node = Initialize((char*)"Fist node string");
    PrintSplayTreeStrNode(node);
    getch();
    return 0;
}
