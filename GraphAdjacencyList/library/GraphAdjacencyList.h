/**
 * @file GraphAdjacencyList.h
 * @details ANSI-C  header
 * @details 
 *      ANSI-C GraphAdjacencyList header
 * 
 *      Data structures:
 *              -> Graph Adjacency List
 *                      @see http://en.wikipedia.org/wiki/Adjacency_list
 *                      This entire library
 *              -> Simply Linked list
 *                      @see http://en.wikipedia.org/wiki/Linked_list
 *                      Nodes used on the Graph
 *     
 * 
 * @version 0.1alpha
 * @date 2011-12-06
 * @author Emerson Rocha Luiz
 * @copyright 
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#ifndef GRAPHADJACENCYLIST_H
#define	GRAPHADJACENCYLIST_H

//#include "GraphAdjacencyList.c"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct sGALNode GALNode;
    typedef struct sGALGraph GALGraph;

    //void GALCreate(GALGraph* G, int n);
    //void GALFree(GALGraph* G);
    //void GALadd(GALGraph* G, int x, int y);
    //void GALdelete(GALGraph* G, int x, int y);

    /**
     *
     */
    typedef struct sGALNode {
        int v;
        struct sGALNode* next;
    } GALNode;

    /**
     *
     */
    typedef struct sGALGraph {
        int n;
        GALNode** list;
    } GALGraph;

    /**
     * 
     * @param G
     * @param n
     */
    void GALCreate(GALGraph* G, int n) {
        G->list = calloc(n, sizeof (GALNode*));
        G->n = n;
    }

    /**
     * 
     * @param G
     * @return void
     */
    void GALFree(GALGraph* G) {
        int i;
        for (i = 0; i < G->n; i++) {
            GALGraph* l = (GALGraph*) G->list[i]; // GALGraph
            while (l) {
                GALGraph* r = l; // GALGraph
                l = (GALGraph*) l->list;
                free(r);
            }
        }
        free(G->list);
    }

    /**
     * Tests whether there is an edge from node x to node y
     * 
     * @param G
     * @param x
     * @param y
     */
    void adjacent(int G, int x, int y);

    /**
     * Lists all nodes y such that there is an edge from x to y.
     * 
     * @param G
     * @param x
     */
    void neighbors(int G, int x);

    /**
     * Adds to G the edge from x to y, if it is not there.
     * 
     * @param G
     * @param x
     * @param y
     */
    void GALadd(GALGraph* G, int x, int y) {
        GALNode** ap_l = &G->list[x];
        while (*ap_l != NULL &&
                (*ap_l)->v < y)
            ap_l = &(*ap_l)->next;
        if (*ap_l == NULL || (*ap_l)->v != y) {
            GALNode* n = malloc(sizeof (GALNode));
            n->v = y;
            n->next = *ap_l;
            *ap_l = n;
        }
    }

    /**
     * Removes the edge from x to y, if it is there.
     * 
     * @param G
     * @param x
     * @param y
     */
    void GALdelete(GALGraph* G, int x, int y) {
        GALNode** ap_l = &G->list[x];
        while (*ap_l != NULL &&
                (*ap_l)->v < y)
            ap_l = &(*ap_l)->next;
        if (*ap_l != NULL && (*ap_l)->v == y) {
            GALNode* r = *ap_l;
            *ap_l = (*ap_l)->next;
            free(r);
        }
    }

    /**
     * Returns the value associated with the node x.
     * 
     * @param G
     * @param x
     */
    void get_node_value(int G, int x);

    /**
     * Sets the value associated to the edge (x,y) to v.
     * 
     * @param G
     * @param x
     * @param y
     * @param v
     */
    void set_edge_value(int G, int x, int y, int v);


#ifdef	__cplusplus
}
#endif

#endif	/* GRAPHADJACENCYLIST_H */

