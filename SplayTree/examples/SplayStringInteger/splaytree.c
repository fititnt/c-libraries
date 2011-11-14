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
    struct SplayTree *node = malloc(sizeof(SplayTreeInt));
    node = NULL;
    node = Initialize( 333 );
    node = Insert( node, 444);
    node = Insert( node, 555);
    node = Insert( node, 666);
    node = Insert( node, 111);
    node = Insert( node, 000);
    PrintSplayTree( node , 0 );
    if ( Search(node , 666) != NULL)
    {
        printf("\nNumero 666 encontrado");
    } else {
        printf("\nNumero 666 nao encontrado");
    }

    //PrintSplayTreeNode( node );
    getch();
    return 0;
}
