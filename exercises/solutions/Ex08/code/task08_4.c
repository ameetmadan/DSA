#include <stdlib.h>
#include <stdio.h>

struct TreeNode{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

void insert(struct TreeNode** root, int val) {
  struct TreeNode* newTreeNode = NULL; 	
  struct TreeNode* prev = NULL; 	
  struct TreeNode* current = *root;
  newTreeNode = malloc(sizeof(struct TreeNode));
  newTreeNode->val = val;
  newTreeNode->left = NULL;
  newTreeNode->right = NULL;
  while (current != NULL) { //whilst we haven't reached the node.
    prev = current;
    if (val < current->val){
      current = current->left;
    } else{
      current = current->right;
    }      
  }
  if (prev == NULL) { //if the previous is null, this is a root
    *root = newTreeNode;
  } else if (val < prev->val) {
    prev->left = newTreeNode;
  } else {
    prev->right = newTreeNode;
  }
}

void printTreeRecursive(struct TreeNode *root) {
  if (root == NULL)
    return;
  if (root->left != NULL) {
    printf("  %d -- %d\n", root->val, root->left->val);
    printTreeRecursive(root->left);
  }
  if (root->right != NULL) {
    printf("  %d -- %d\n", root->val, root->right->val);
    printTreeRecursive(root->right);
  }
}

void printTree(struct TreeNode *root) {
  printf("graph g {\n");
  printTreeRecursive(root);
  printf("}\n");
}

struct TreeNode *lca(struct TreeNode *root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->val > n1 && root->val > n2)
        return lca(root->left, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->val < n1 && root->val < n2)
        return lca(root->right, n1, n2);

    return root;
}

int main() {
    int n1, n2;
    struct TreeNode *root = NULL;

    insert(&root, 7);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 1);
    insert(&root, 9);
    insert(&root, 10);
    insert(&root, 8);

    printTree(root);

    n1 = 8;
    n2 = 9;
    struct TreeNode *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->val);

    return 0;
}

// Linux, Mac: gcc task08_4.c -o task08_4; ./task08_4
// Windows: gcc task08_4.c -o task08_4; task08_4
