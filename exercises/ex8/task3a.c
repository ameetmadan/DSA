struct TreeNode
{
    int val;
    struct TreeNode∗ left;
    struct TreeNode∗ right;
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
    while (t != NULL;)
    {
        r = t;
        if (val < t->data)
            t = t->left;
        else if (val > t->data)
            t = t->right;
        else
            return;
    }
    p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    p->left = p->right = NULL;
    if (key < r->data)
        r->left = p;
    else
        r->right = p;
}