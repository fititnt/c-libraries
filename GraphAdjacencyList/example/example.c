/**
 * @file example.c
 * @details ANSI-C GraphAdjacencyList example
 * @version 0.1alpha
 * @date 2011-12-06
 * @author Emerson Rocha Luiz
 * @copyright 
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include "../library/GraphAdjacencyList.h"

int main(int argc, char** argv) {

    printf("hi!");
    GALGraph G;
    GALCreate(&G, 6);
    GALadd(&G, 0, 1);

    return (EXIT_SUCCESS);
}

