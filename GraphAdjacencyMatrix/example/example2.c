/**
 * @file example.c
 * @details ANSI-C GraphAdjacencyMatrix example
 * @version 1.0beta1
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

/**
 * 
 */
int main(int argc, char** argv) {
    GAMGraph *Graph;
    newGMA(Graph, 5);
    
    //Set edges
    setGMANode(Graph, 1, 2);
    setGMANode(Graph, 3, 5);
    setGMANode(Graph, 5, 1);
    
    //Get one node value
    printf("%i \n", getGMANode(Graph, 1, 2)); //1
    
    //Delete oedge
    delGMANode(Graph, 1, 2); 
    
    //Print edges
    printGMA(Graph);//<3,5> <8,1>
    
    //Free memory usage
    freeGMA(Graph);
    
    return 0;
}




