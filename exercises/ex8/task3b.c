#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int key;
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

void search(struct TreeNode **root, int val)
{
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->left;
        else
            t = t->right;
    }
}