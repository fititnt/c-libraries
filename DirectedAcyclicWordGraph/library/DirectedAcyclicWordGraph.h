/**
 * @file DirectedAcyclicWordGraph.h
 * @details 
 *      ANSI-C Directed Acyclic Word Graph
 * 
 *      Data structures:
 *              -> Directed Acyclic Word Graph
 *                      @see http://en.wikipedia.org/wiki/Directed_acyclic_word_graph
 *                      This entire library
 *              -> Stack
 *     
 * 
 * @version 0.1alpha
 * @date 2011-12-12
 * @author Emerson Rocha Luiz
 * @copyright Copyright (C) 2011 Webdesign Assessoria em Tecnologia da Informação. All rights reserved.
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */


#ifndef DIRECTEDACYCLICWORDGRAPH_H
#define	DIRECTEDACYCLICWORDGRAPH_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

    //typedef struct sDAWG DAWGNode;

    /**
     * letter: Letter of this node
     * end: bit 1 if this node represent one end, 0 if not
     * next: pointer for next DAWG node
     * @todo change 'int end' to bit
     */
    typedef struct sDAWGNode {
        char letter;
        int end; //unsigned end : 1;
        struct sDAWGNode* next;
    } DAWGNode;

    /**
     * Allocate memory of the root of DAWGNode
     * @param 
     */
    DAWGNode* newDAWG(DAWGNode* N) {
        N = (DAWGNode*) malloc(sizeof (DAWGNode));
        if (N == 0) {
            return NULL; //Cannot allocate memory
        } else {
            N->end = 1;
            N->letter = 0; //@todo turn it a NULL or something
            N->next = NULL;
        }
    }

    /**
     * 
     * @param Root
     * @param Word
     * @param CaseSensitive 1 for yes, 0 for no (and insert all as lowercase)
     * @return result -1 for error of int
     */
    int newDAWGWord(DAWGNode* Root, char *Word, int CaseSensitive) {
        /*
        char *ptr = NULL;
        for (ptr = (char*)&Word; *ptr; ptr++) {
            if (*ptr >= 65 && *ptr <= 90) { //A-Z
                *ptr += 32;
            }
        }
        print  
                
        f("\n\n%s\n", Word);
        */   
        int i;
        for (i = 0; i < strlen(Word); i++) {
            
            if (CaseSensitive && Word[i] >= 65 && Word[i] <= 90) {
                //st[i] = tolower(st[ i ]);
                //Word[i] = tolower(Word[i]);
                //Word[i] = Word[i];
                
                (*Word+i) = tolower( (*Word+i) );
                //break;
            }
            //Word[i] = tolower(Word[i]);
            //strcpy((char*)Word[i], (char*)tolower(Word[i]) );
            //(char*)Word[i] = tolower(Word[i]);
            //printf("\n %c, %c", (*Word+i), tolower(Word[i]));
             
        }
        printf("\n %s", Word);
    }

    /**
     * Add a new node
     * @protected Cannot be accessed out of this file
     * 
     * @param Node Pointer for new node to allocate memomy and insert data
     * @param c Letter to Insert
     * @param end Integer 1 for end of word, 0 for not
     * @return Node
     */
    static DAWGNode * newDAWGNode(DAWGNode* Node, char c, int end) {
        Node = (DAWGNode*) malloc(sizeof (DAWGNode));
        if (Node == 0) {
            return NULL; //Cannot allocate memory
        } else {
            Node->end = end;
            Node->letter = c; //@todo turn it a NULL or something
            Node->next = NULL;
        }
        return Node;
    }



#ifdef	__cplusplus
}
#endif

#endif	/* DIRECTEDACYCLICWORDGRAPH_H */

