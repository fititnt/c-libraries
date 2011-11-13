/**
 * @file splaytree.c
 * @details ANSI-C Splay Tree Library
 *          Data: Integer
 * @version 0.1
 * @date 2011-11-13
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include "../../library/splaytree.h"

int main()
{
    printf("Splay Tree (Data type Integer) start \n");
    struct SplayTree *node = malloc(sizeof(SplayTreeSN));
    node = Initialize( 333 );
    PrintSplayTreeNode(node);
    getch();
    return 0;
}
