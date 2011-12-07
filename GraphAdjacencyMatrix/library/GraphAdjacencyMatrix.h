/**
 * @file GraphAdjacencyMatrix.h
 * @details 
 *      ANSI-C GraphAdjacencyMatrix header
 * 
 *      Data structures:
 *              -> Graph Adjacency Matrix
 *                      @see http://en.wikipedia.org/wiki/Adjacency_list
 *                      This entire library
 *     
 * 
 *      Important: this presumes that the matrix start at 1 and not 0. If you
 *      do not use as this way, it could lead you to some execution errors
 * 
 * @version 1.0beta1
 * @date 2011-12-06
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#ifndef GRAPHADJACENCYMATRIX_H
#define	GRAPHADJACENCYMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct sGAMGraph {
        int n; //Node numbers
        int **matrix; //Dynamic matrix
    } GAMGraph;

    /**
     * Dynamic create one matrix of n cols, with int type
     *
     * @param G GAMGraph element
     * @param n Number of nodes
     * @return void
     */
    void newGMA(GAMGraph * G, int n) {
        int i;
        G->matrix = (int **) calloc(n, sizeof (int*));
        G->matrix[0] = NULL; //Please do not try access G->matrix[0][]
        for (i = 1; i <= n; i++) {
            G->matrix[i] = (int *) calloc(i, sizeof (int));
        }
        G->n = n;
        //return G;
    }

    /**
     * Free memory used by GAMGraph
     *
     * @param G GAMGraph element
     * @return void
     */
    void freeGMA(GAMGraph * G) {
        int i;
        for (i = G->n; i >= 0; --i) {
            free(G->matrix[i]);
        }
    }

    /**
     *
     *
     * @param G
     * @param x
     * @param y
     */
    void setGMANode(GAMGraph * G, int x, int y) {
        G->matrix[x][y] = 1;
        //if (x > y) {
        //    G->matrix[x][y] = 1;
        //} else {
        //    G->matrix[y][x] = 1;
        //}
    }

    /**
     * Get if has one edge between nodes
     *
     * @example
     * @code
     *          GAMGraph *Graph;
     *          newGMA(Graph, 10);
     *          setNodeGMA(Graph, 1, 2);
     *          printf("%i \n", getGMANode(Graph, 1, 2));//print 1
     * @endcode
     * 
     * @param G GAMGraph element
     * @param x
     * @param y
     * @return isSet
     */
    int getGMANode(GAMGraph * G, int x, int y) {
        int isSet;
        isSet = G->matrix[x][y];
        //if (x > y) {
        //    isSet = G->matrix[x][y];
        //} else {
        //    isSet = G->matrix[y][x];
        //}
        return isSet;
    }

    /**
     *
     * @param G GAMGraph element
     * @param x
     * @param y
     * @return void
     */
    void delGMANode(GAMGraph * G, int x, int y) {
        G->matrix[x][y] = 0;
        //if (x > y) {
        //    G->matrix[x][y] = 0;
        //} else {
        //    G->matrix[y][x] = 0;
        //}
    }

    /**
     * 
     * @example
     * @code
     *          GAMGraph *Graph;
     *          newGMA(Graph, 10);
     *          setNodeGMA(Graph, 1, 2);
     *          printf("%i \n", getNodeGMA(Graph, 1, 2));//print 1
     * @endcode
     * 
     * @param G GAMGraph element
     * @return void
     */
    void printGMA(GAMGraph * G) {
        int i, j;
        for (i = 1; i <= G->n; i++) {
            for (j = 1; j <= G->n; j++) {
                if (G->matrix[i][j] == 1) {
                    printf("<%i,%i> ", i, j);
                }
                //if (getGMANode(G, i, j) == 1) {
                //    printf("<%i,%i> ", i, j);
                //}
            }
        }
    }


#ifdef	__cplusplus
}
#endif

#endif	/* GRAPHADJACENCYMATRIX_H */

