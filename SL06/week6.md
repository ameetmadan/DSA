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

The task of searching in BST is also easier due to the property of the elements. While searching, if the found element is greater than what is searched, the algorithm should move further left. And on the other hand, when the found element is smaller than what is searched, move further right.

```C
void TreeSearchIterative(struct node* p,int value){
    while(t != NULL && p->key != NULL){
        if(v < p->key){
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return p;
}

void TreeSearchRecurisve(struct node* p, int value){
    if(p == NULL || p->key == value){
        return p;
    }

    if(v < p->key){
        return TreeSearchRecursive(p->left, value);
    } else {
        return TreeSearchRecursive(p>right, value);
    }
}
```

### Deletion

- Deletion case 1: Node $t$ has no children -> remove $t$
- Deletion case 2: Node $t$ has one child $x$ -> let parent of $t$ point to $x$ and then remove t
- Deletion case 3: Node $t$ has two children -> find largest (smallest) child $s$ in left (right) subtree of $t$, then replace $p→key$ with $s.key$ and remove $s$
(often this is done by changing pointers (makes it independent of node content))

```C
/* Node x is a pointer to the node to be deleted */
struct node* delete(struct node* root, struct node* x) {
    u = root;
    v = NULL;
    
    //we search x and the node above
    while (u != x) {
        v = u;
        if (x->key < u->key) u = u->lft;
        else u = u->rgt;
    }

    if (u->rgt == NULL) {
        if (v == NULL) root = u->lft;
        else if (v->lft == u) v->lft = u->lft; else v->rgt = u->lft;
    } else if (u->lft == NULL) {
        if (v == NULL) root = u->rgt;
        else if (v->lft == u) v->lft = u->rgt;
        else v->rgt = u->rgt;
    } else {
        p = x->lft;
        q = p;
        while (p->rgt != NULL) {
            q = p;
            p = p->rgt;
        }

        if (v == NULL) root = p;
        else if (v->lft == u) v->lft = p;
        else v->rgt = p;

        p->rgt = u->rgt;
        if (q != p) {
            q->rgt = p->lft;
            p->lft = u->lft;
        }
    }
    return root
```

### Printing

### Maximum and minimum

Finding the minimum

- Finds the minimum key in a tree rooted at p
- Running time is proportional to height of tree
- We do not have to compare keys.

```C
void TreeMin(struct node* p){
    while(p->left != NULL){
        p = p->left;
    }
    return p;
}
```

Same principle for maximum, just on the other side:


```C
void TreeMin(struct node* p){
    while(p->right != NULL){
        p = p->right;
    }
    return p;
}
```


### Distance to root

```C
int heightBT(struct node* p){
    if (p === NULL) return -1;
    return max(heightBT(p->left), heightBT(p->right)) + 1;
}
```

# Red-black trees

## What is a red-black tree?

## How and when is a red-black tree used?

### Insertion

### Searching

### Deletion

### Printing

### Maximum and minimum

### Distance to root