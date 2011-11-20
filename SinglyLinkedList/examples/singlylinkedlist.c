/**
 * @file singlylinkedlist.c
 * @details Singly Linked List
 * @see http://en.wikipedia.org/wiki/Linked_list
 * @version 0.1beta
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../library/singlylinkedlist.h"

int main()
{
    printf("Singly Linked List start \n");

    struct NodeSLL* list = initializeSLL();
    struct DataSLL data;

    strcpy( data.item, "Fist");
    list = insertSLLNode ( list, data );
    strcpy( data.item, "Second");
    list = insertSLLNode ( list, data );
    strcpy( data.item, "Third");
    list = insertSLLNode ( list, data );
    strcpy( data.item, "33");
    list = insertSLLNode ( list, data );
    strcpy( data.item, "Thi444rd");
    list = insertSLLNode ( list, data );

    list = removeSLLNode( list, data );

    printSLLList(list);

    if ( searchSLLNode( list, data ) != NULL ){
        printf("\n%s found \n", data.item);
    }


    getch();
    return 0;
}
