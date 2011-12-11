/**
 * @file example.c
 * @details ANSI-C Directed Acyclic Word Graph example
 * @version 0.1alpha
 * @date 2011-12-12
 * @author Emerson Rocha Luiz
 * @copyright Copyright (C) 2011 Webdesign Assessoria em Tecnologia da Informação. All rights reserved.
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../library/DirectedAcyclicWordGraph.h"

int main(int argc, char** argv) {
    printf("ANSI-C Directed Acyclic Word Graph example");

    DAWGNode* N;
    N = newDAWG(N);
    if (N == NULL) {
        printf("Memory for root was not alocated");
        return 0;
    }
    newDAWGWord(N, "abcTesteAAAAABCDE", 1); 
  
 
    printf("\n");
    /*
    char str[20] = {"tABCDE fghi"};
    char *ptr = NULL;

    ptr = str;

    for (ptr = str; *ptr; ptr++) {
        if (*ptr >= 65 && *ptr <= 90) { //A-Z
            *ptr += 32;
        }
    }
    printf("%s\n", str);
    */

    return (EXIT_SUCCESS);
}
