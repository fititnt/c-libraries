/**
 * @file splaytree.h
 * @details ANSI-C Splay Tree Library
 *          Data: Integer
 * @version 0.1
 * @date 2011-11-13
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */
#ifndef SPLAYTREE_H_INCLUDED
#define SPLAYTREE_H_INCLUDED

///                             Includes                                     ///
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
///                             Constants                                    ///
///Definitions
#define STRMAX 255


///                             Definitions                                  ///

/**
 * Define node as same type of SplayTreeStr
 */
struct SplayTree
{
    int data;
    struct SplayTree *left;
    struct SplayTree *right;
} SplayTreeSN; //Splay Tree String Node

///                             Functions                                    ///
//Initialize a new Tree
struct SplayTree* Initialize(int data);
//Rotate to right tree
struct SplayTree* RotationLeft(struct SplayTree* node, struct SplayTree* root);
//Rotate to right tree
struct SplayTree* RotationRight(struct SplayTree* node, struct SplayTree* root);
//Insert (and also after organize) tree
struct SplayTree* Splay(struct SplayTree* root, int data);
//Search for one data inside tree
struct SplayTree* Search(struct SplayTree* root, int data);
//Destroy entire tree
struct SplayTree* Destroy(struct SplayTree* root);

///Debug functions
//void PrintSplayTreeNode(struct SplayTree* node));

/**
 * Initialize a new Tree
 *
 * @param[in] int data Value of root node
 * @return SplayTreeStr*
 */
struct SplayTree* Initialize(int data)
{
    struct SplayTree *node = malloc(sizeof(SplayTreeSN));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


///                             Debug functions                              ///
//Print one node value
int PrintSplayTreeNode(struct SplayTree* node)
{
    printf("%i", node->data);
    return node->data;
}


#endif // SPLAYTREE_H_INCLUDED
