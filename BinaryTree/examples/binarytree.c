/* 
 * File:   binarytree.c
 * Author: fititnt
 *
 * Created on 20 de Novembro de 2011, 04:56
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../library/binarytree.h"

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
    NodeBSType *arv = NULL, *procurado = NULL;
    X *l = NULL, *aux;
    int i;

    puts("digite a palavra");
    gets(palavra);

    for (i = 0; i < strlen(palavra); i++)
        arv = InsertNodeBT(arv, palavra[i]);

    // testando Caminhamentos  
    PrintNodeBTBefore(arv);
    printf("----\n\n");
    PrintNodeBTCenter(arv);
    printf("----\n\n");
    PrintNodeBTAfter(arv);


    if (l == NULL) puts("nulo");
    for (aux = l; aux != NULL; aux = aux->p1)
        printf("%c ", aux->data);
    system("pause");

    return (EXIT_SUCCESS);
}

