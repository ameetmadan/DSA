// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *left;
    struct node *right;
};

// Inorder traversal
void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->item);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->item);
}

// Create a new Node
struct node *createNode(value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}

// Insert on the right of the node
struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}

// Height of a BT
int heightBT(struct node *p)
{
    if (p == NULL)
        return -1;
    return max(heightBT(p->left), heightBT(p->right)) + 1;
}

// C implementation to find leaf count of a given Binary tree
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Function to get the count of leaf nodes in a binary tree*/
unsigned int getLeafCount(struct node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left) +
               getLeafCount(node->right);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node *newNode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/*Driver program to test above functions*/
int main()
{
    /*create a tree*/
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    /*get leaf count of the above created tree*/
    printf("Leaf count of the tree is %d", getLeafCount(root));

    getchar();
    return 0;
}

// Count occurences of a integer X in BST
unsigned int countX(struct node *node, int x)
{
    // if (node == NULL)
    //     return 0;
    if (x < node->data)
        return countX(node->left, x);
    else if (x > node->data)
    {
        return countX(node->right, x)
    }
    else
    {
        return countX(node->left, x) + countX(node->right, x) + 1;
    }
}

// Count occurences in range [x, y] in BST
struct node
{
    int data;
    struct node *left, *right;
};

// Utility function to create new node
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

// Returns count of nodes in BST in range [low, high]
int getCount(node *root, int low, int high)
{
    // Base case
    if (!root)
        return 0;

    // Special Optional case for improving efficiency
    if (root->data == high && root->data == low)
        return 1;

    // If current node is in range, then include it in count and
    // recur for left and right children of it
    if (root->data <= high && root->data >= low)
        return 1 + getCount(root->left, low, high) +
               getCount(root->right, low, high);

    // If current node is smaller than low, then recur for right
    // child
    else if (root->data < low)
        return getCount(root->right, low, high);

    // Else recur for left child
    else
        return getCount(root->left, low, high);
}

// Driver program
int main()
{
    // Let us construct the BST shown in the above figure
    node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(50);
    root->left->left = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    /* Let us constructed BST shown in above example
          10
        /    \
      5       50
     /       /  \
    1       40   100   */
    int l = 5;
    int h = 45;
    printf("Count of nodes between [%d, %d] is %d", getCount(root, l, h));
    return 0;
}

/* */

int main()
{
    struct node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("Inorder traversal \n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);
}
