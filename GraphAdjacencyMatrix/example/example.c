/**
 * @file example.c
 * @details ANSI-C GraphAdjacencyMatrix example
 * @version 0.1alpha
 * @date 2011-12-06
 * @author Emerson Rocha Luiz
 * @copyright 
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 * @todo change graph[7][7] to one flexible size
 */

#include <stdio.h>
#include <stdlib.h>
#include "../library/GraphAdjacencyMatrix.h"

//int alcance(int *graph[], int start, int end );

/**
 * Tests whether there is an edge from node x to node y, even if is indirectly
 * Return 1 for TRUE, and 0 for FALSE
 *
 *
 * @param[in] **graph Matrix with the graph
 * @param[in] start De onde
 * @param[in] end Para aonde apontar
 * @return possivel
 */
int GAMadjacent(int graph[7][7], int start, int end)
{
    int i, j, ok = 0;
    int possivel = 0;

    if (graph[start][end] == 1) {
        possivel = 1;
    } else {
        for (i = 1; i < 7; ++i) {
            if (graph[i][end] == 1) {
                for (j = 1; j < 6; ++j) {
                    if (graph[i][j] == 1) {
                        ok = 1;
                    }
                }
                if (ok == 1) {
                    possivel = GAMadjacent(graph, i, end);
                }
            }
            ok = 0;
        }
    }

    return possivel;
}

/**
 * Test example
 */
int main(int argc, char** argv) {
    int i;
    int j;
    int max = 6;
    int graph[7][7];

    ///Now will initialize the matrix of graph
    //Fist, all fields with zeros
    for(i=1; i<=max; i++)
    {
        for(j=1; j<=max; j++)
        {
            graph[i][j]=0;
        }
    }
    //Populate matrix with the specific info
    graph[1][2]=1;
    graph[1][4]=1;
    graph[1][6]=1;
    graph[2][3]=1;
    graph[2][4]=1;
    graph[4][3]=1;
    graph[4][5]=1;
    graph[5][4]=1;
    graph[5][6]=1;
    graph[6][2]=1;
    graph[6][4]=1;

    ///Print list
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | \n ----------------------- \n" );
    for(i=1; i<=max; i++)
    {
        printf("|");
        for(j=1; j<=max; j++)
        {
            printf(" %i |", graph[i][j]);
        }
        printf("\n");
    }
    printf("\nIndirect\n");
    printf("GAMadjacent: 2 to 5: %i \n", GAMadjacent(graph, 2, 5));//TRUE
    printf("GAMadjacent: 4 to 1: %i \n", GAMadjacent(graph, 4, 1));//FALSE
    printf("GAMadjacent: 3 to 4: %i \n", GAMadjacent(graph, 3, 4));//FALSE @todo fix false positive here
    printf("GAMadjacent: 2 to 5: %i \n", GAMadjacent(graph, 5, 3));//TRUE

    printf("Direct \n");
    printf("GAMadjacent: 1 to 2: %i \n", GAMadjacent(graph, 1, 2));//TRUE
    printf("GAMadjacent: 1 to 6: %i \n", GAMadjacent(graph, 1, 6));//TRUE
    printf("GAMadjacent: 2 to 4: %i \n", GAMadjacent(graph, 2, 4));//TRUE

    return 0;
}




