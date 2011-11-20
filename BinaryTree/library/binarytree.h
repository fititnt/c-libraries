/**
 * @file binarytree.h
 * @details
 * @see http://en.wikipedia.org/wiki/Binary_tree
 * @version
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef BINARYTREE_H
#define	BINARYTREE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdlib.h>
    
    typedef struct NodeBS NodeBSType;

    struct NodeBS {
        char data;
        struct NodeBS *left;
        struct NodeBS *rigth;
    };

    NodeBSType* InsertNodeBT(NodeBSType *a, char data);
    NodeBSType* SearchNodeBS(NodeBSType *a, char chave);



    NodeBSType* InsertNodeBT(NodeBSType *node, char data) {
        if (node == NULL) {
            node = (NodeBSType*) malloc(sizeof (NodeBSType));
            node->data = data;
            node->left = NULL;
            node->rigth = NULL;
            return node;
        } else
            if (data < node->data)
            node->left = InsertNodeBT(node->left, data);
        else if (data > node->data)
            node->rigth = InsertNodeBT(node->rigth, data);
        return node;
    }

    NodeBSType* consultaABP(NodeBSType *node, char data) {

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

    void PrintNodeBTBefore(NodeBSType *node) {
        if (node != NULL) {
            printf("%c\n", node->data);
            PrintNodeBTBefore(node->left);
            PrintNodeBTBefore(node->rigth);
        }
    }

    void PrintNodeBTCenter(NodeBSType *node) {
        if (node != NULL) {
            PrintNodeBTCenter(node->left);
            printf("%c\n", node->data);
            PrintNodeBTCenter(node->rigth);
        }
    }

    void PrintNodeBTAfter(NodeBSType *node) {
        if (node != NULL) {
            PrintNodeBTAfter(node->left);
            PrintNodeBTAfter(node->rigth);
            printf("%c\n", node->data);
        }
    }





#ifdef	__cplusplus
}
#endif

#endif	/* BINARYTREE_H */

