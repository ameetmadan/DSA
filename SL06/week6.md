# Binary trees

## What is a binary tree?

A binary tree, contrary to real trees, grows upside down. The top of the tree is the root. Under the root, you have child nodes. These child nodes further have children. Node D in the following picture is a parent of nodes G and H. At the same time, it is a sibling of nodes B and C. Nodes in the last row are called leaf nodes. If binary tree has height h, maximum number of nodes will be when all levels are completely full. Total number of nodes will be $2^{h+1}-1$. 
![](11_05_2021_21.12.png){ width=450px }

## How and when is a binary tree used?

- Binary search
- Represent search array as binary tree
- Fast addition and removal of data

### Tree walks

![](11_05_2021_21.50.png){ width=250px }

- Inorder: [10, 14, 19, 27, 31, 35, 42] 
- Preorder: [27, 14, 10, 19, 35, 31, 42]
- Postorder: [10, 19, 14, 31, 42, 35, 27]
- Levelorder: [27, 14, 35, 10, 19, 31, 42

```C
// We first go to the left -> middle -> right
void InorderTreeWalk(struct node* p){
    if (p != NULL){
        InorderTreeWalk(p->left);
        VisitNode(p);
        InorderTreeWalk(p->right);
    }
}

void VisitNode(struct node* p){
    printf("%d ", p->value);
}
```

### Insertion

```C
struct node* TreeInsert(
struct node* p, struct node* r)
{
    struct node* y = NULL;
    struct node* x = r;
    while (x != NULL) {
        y := x;
        if (x->key < p->key) x = x->rgt
        else x = x->lft;
    }
    if (y == NULL) r = p;
    else if (y->key < p->key) y->rgt = p;
    else y->lft = p;
    return r;
}
```

To insert an element into a binary search tree, we first need to know if it's empty or not. With an empty tree, it is easy. We add the first number to the root. In a binary search tree, we have a special rule. This asks us to keep all elements which are smaller than a node, should be on the left side of the node. Everthing that is greater than root should go to the right of the binary search tree. If we already have elements in our BST, we find the correct place for the value and then add it there. 

### Searching

### Deletion

### Printing

### Maximum and minimum

### Distance to root

# Red-black trees

## What is a red-black tree?

## How and when is a red-black tree used?

### Insertion

### Searching

### Deletion

### Printing

### Maximum and minimum

### Distance to root