#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insert(struct TreeNode **root, int val)
{
    struct TreeNode *t = root;     /* pointer used to traverse through BST starting at root */
    struct TreeNode *r = NULL, *p; /* pointer used to traverse through BST starting at root */
    if (root == NULL)
    {
        p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        p->data = val;             /* assign value to root */
        p->left = p->right = NULL; /* root init */
        root = p;
    }
    while (t != NULL) /* this is what we do when the binary tree already has elements */
    {
        r = t;
        if (val < t->data) /* here we apply what happens when the value is smaller than root */
            t = t->left;
        else if (val > t->data) /* same as above just when value is greater we go right*/
            t = t->right;
        else
            return;
    }
    p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    p->left = p->right = NULL;
    if (val < r->data)
        r->left = p;
    else
        r->right = p;
}