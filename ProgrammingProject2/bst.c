#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add(bst_node **root, char *word)
{
    // we chec whether the root is null or not
    if ((*root) == NULL)
    {
        *root = (bst_node*)malloc(sizeof(bst_node));
        (*root)->data = word;
    
        return;
    }
    // if not, we compare the magnitude of two numbers
    char *temp = (*root)->data;
    int i = strcmp(temp, word);
 
    // if the word is smaller than the node->data
    // we put it on the left side
    if (i > 0)
    {
        add(&((*root)->left),word);
    }
    // else
    // we put it to the right
    else
    {
      
        add(&((*root)->right),word);
    }
}

/* Prints the values stored in the bst according to
 * the inorder traversal. The values should be separated 
 * by a single space. 
 * Parameters: 
 *  root - the root of the tree
 * Return value:
 *  none
 */ 
void inorder(bst_node * root)
{
    // check for the base case of recursion
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    // print the data
    printf("%s ",root->data);
    inorder(root->right);
}
/* Removes the node with the smallest value
 * in the tree. 
 * Parameters: 
 *  root - the pointer to the root of the tree
 * Return value:
 *  the string from the removed node or 
 *  NULL if no node was removed. 
 */ 
char * removeSmallest (bst_node ** root )
{
    // handle the the empty tree case
    if (*root == NULL)
    {
        return NULL;
    }
    // use 'deleted' to return the value of the deleted node
    char* deleted;
    // if there is only one node, we remove the root
    if ((*root)-> left == NULL && (*root)-> right==NULL)
    {
        deleted = (*root)->data;
        (*root) = NULL;
        return deleted;
    }

    bst_node *temp = *root;
    // use 'prev' to keep track of the prev nodes for removal
    bst_node *prev= *root;
    
    while (temp->left !=NULL)
    {
        prev = temp;
        temp = temp->left;
    }

    // remove the smallest node
    deleted = temp->data;
    prev->left = temp->right;
    return deleted;
}

char * removeLargest (  bst_node ** root )
{
    // handle the the empty tree case
    if (*root == NULL)
    {  
        return NULL;
    }
    // use 'deleted' to return the value of the deleted node

    char* deleted;

    // if there is only one node, we remove the root
    if ((*root)-> left == NULL && (*root)-> right==NULL)
    {
        deleted = (*root)->data;
        (*root) = NULL;
        return deleted;
    }

    bst_node *temp = *root;
    // use 'prev' to keep track of the prev nodes for removal
    bst_node *prev= *root;
    
    while (temp->right !=NULL)
    {
        prev = temp;
        temp = temp->right;
    }

    // remove the largest node
    deleted = temp->data;
    prev->right = temp->left;
    return deleted;
}




