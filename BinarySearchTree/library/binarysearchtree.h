/**
 * @file binarysearchtree.h
 * @details Binary Search Tree (BST)
 * @see http://en.wikipedia.org/wiki/Binary_search_tree
 * @version
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef BINARYSEARCHTREE_H
#define	BINARYSEARCHTREE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>

    typedef struct NodeBST NodeBSTType;

    struct NodeBST {
        char data;
        struct NodeBST *left;
        struct NodeBST *rigth;
    };

    NodeBSTType* InsertNodeBST(NodeBSTType *a, char data);
    NodeBSTType* SearchNodeBST(NodeBSTType *a, char chave);



    NodeBSTType* InsertNodeBST(NodeBSTType *node, char data) {
        if (node == NULL) {
            node = (NodeBSTType*) malloc(sizeof (NodeBSTType));
            node->data = data;
            node->left = NULL;
            node->rigth = NULL;
            return node;
        } else
            if (data < node->data)
            node->left = InsertNodeBST(node->left, data);
        else if (data > node->data)
            node->rigth = InsertNodeBST(node->rigth, data);
        return node;
    }

    NodeBSTType* consultaABP(NodeBSTType *node, char data) {

        while (node != NULL) {
            if (node->data == data)
                return node; //achou então retorna o ponteiro para o nodo
            else
                if (node->data > data)
                node = node->left;
            else
                node = node->rigth;
        }
        return NULL; //se não achou
    }

    void PrintNodeBSTBefore(NodeBSTType *node) {
        if (node != NULL) {
            printf("%c\n", node->data);
            PrintNodeBSTBefore(node->left);
            PrintNodeBSTBefore(node->rigth);
        }
    }

    void PrintNodeBSTCenter(NodeBSTType *node) {
        if (node != NULL) {
            PrintNodeBSTCenter(node->left);
            printf("%c\n", node->data);
            PrintNodeBSTCenter(node->rigth);
        }
    }

    void PrintNodeBSTAfter(NodeBSTType *node) {
        if (node != NULL) {
            PrintNodeBSTAfter(node->left);
            PrintNodeBSTAfter(node->rigth);
            printf("%c\n", node->data);
        }
    }



#ifdef	__cplusplus
}
#endif

#endif	/* BINARYSEARCHTREE_H */

