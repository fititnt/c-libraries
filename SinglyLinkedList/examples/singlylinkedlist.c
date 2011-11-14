/**
 * @file singlylinkedlist.c
 * @details Singly Linked List
 * @see http://en.wikipedia.org/wiki/Linked_list
 * @version
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

    struct Node* list = initialize();
    struct Data data;

    strcpy( data.item, "Fist");
    list = insertNode ( list, data );
    strcpy( data.item, "Second");
    list = insertNode ( list, data );
    strcpy( data.item, "Third");
    list = insertNode ( list, data );

    printList(list);

    if ( searchNode( list, data ) != NULL ){
        printf("\n%s found \n", data.item);
    }


    getch();
    return 0;
}
