/**
 * @file binarysearchtree.c
 * @details Binary Search Tree (BST)
 * @see http://en.wikipedia.org/wiki/Binary_search_tree
 * @version
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../library/binarysearchtree.h"


typedef char TipoInfo;
struct TX{
        TipoInfo data;
        struct TX *p1;        
};

typedef struct TX X;


/*
 * 
 */
int main(int argc, char** argv) {

    char palavra[20];
    NodeBSTType *arv = NULL, *procurado = NULL;
    X *l = NULL, *aux;
    int i;

    puts("digite a palavra");
    gets(palavra);

    for (i = 0; i < strlen(palavra); i++)
        arv = InsertNodeBST(arv, palavra[i]);

    // testando Caminhamentos  
    PrintNodeBSTBefore(arv);
    printf("----\n\n");
    PrintNodeBSTCenter(arv);
    printf("----\n\n");
    PrintNodeBSTAfter(arv);


    if (l == NULL) puts("nulo");
    for (aux = l; aux != NULL; aux = aux->p1)
        printf("%c ", aux->data);
    system("pause");

    return (EXIT_SUCCESS);
}

