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
  while (current != NULL) {
    prev = current;
    if (val < current->val){
      current = current->left;
    } else{
      current = current->right;
    }      
  }
  if (prev == NULL) {
    *root = newTreeNode;
  } else if (val < prev->val) {
    prev->left = newTreeNode;
  } else {
    prev->right = newTreeNode;
  }
}

struct TreeNode* search(struct TreeNode* root, int val) {
  struct TreeNode* current = root;
  while (current != NULL && current->val != val) {
    if (val < current->val){
		current = current->left;
    } else{
    	current = current->right;
    }
  }
  return current;
}

void delete(struct TreeNode** root, int val) {
  struct TreeNode* x = search(*root, val);
  if (x == NULL){ //search did not find an element, hence do nothing.
  	return;
  }
  struct TreeNode* u = *root;
  struct TreeNode* prev = NULL; // parent of tree node with value = val
  while (u != x) {
    prev = u;
    if (x->val < u->val){
      u = u->left;	
    } else{
      u = u->right;
    }   
  }
  // Leaf and root case also handled in the no right or left branch. Since if it's leaf, its null anyway.
  if (u->right == NULL) { // there is no right branch
    if (prev == NULL){ // delete root
      *root = u->left;
    } else if (prev->left == u){ //if it's a left child, make left the new child
      prev->left = u->left;
    } else{
      prev->right = u->left;
    }	
  } else if (u->left == NULL) { // there is no left branch
    if (prev == NULL){ // delete root
      *root = u->right;
    } else if (prev->left == u){ //if it's a left child, make right the new child
      prev->left = u->right;
    } else{
      prev->right = u->right;
    } 	
  } else{
    struct TreeNode* p = x->left;
    struct TreeNode* q = p;
    while (p->right != NULL) { //whilst right is null
      q = p;
      p = p->right;
    }
    if (prev == NULL){ // if we are at root
      *root = p;
    } else if (prev->left == u){ // if its a left child
      prev->left = p;
    } else{ //if its a right child
      prev->right = p;
    }
    p->right = u->right;
    if (q != p) {
      q->right = p->left;
      p->left = u->left;
    }
  }
  free(u);
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

struct TreeNode* maximum(struct TreeNode* root) {
  struct TreeNode* current = root;
  while (current->right != NULL) { //keep going right until we find the maximum
		current = current->right;
  }
  return current;
}

struct TreeNode* minimum(struct TreeNode* root) {
  struct TreeNode* current = root;
  while (current->left != NULL) { //keep going left until we find the minimum
		current = current->left;
  }
  return current;
}

int distanceToRoot(struct TreeNode* root, int val) {
  if (root->val == val) return 0; // termination condition, else recursively search for solution
  else if (root->val>val) return 1+distanceToRoot(root->left,val);
  else return 1+distanceToRoot(root->right,val);
}

int main() {
  struct TreeNode* root= NULL;
  printf("Inserting: 4, 2, 3, 8, 6, 7, 9, 12, 1\n");
  insert(&root, 4);
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 8);
  insert(&root, 6);
  insert(&root, 7);
  insert(&root, 9);
  insert(&root, 12);
  insert(&root, 1);
  printTree(root);
  printf("Minimum Value: %d\n", minimum(root)->val);
  printf("Distance to root of node 7: %d\n",distanceToRoot(root,7));
  printf("Deleting: 4, 12, 2\n");
  delete(&root, 4);
  delete(&root, 12);
  delete(&root, 2);
  printTree(root);
  printf("Maximum Value: %d\n", maximum(root)->val);
  printf("Distance to root of node 6: %d\n",distanceToRoot(root,6));

  return 0;
}
// Linux, Mac: gcc task08_3.c -o task08_3; ./task08_3
// Windows: gcc task08_3.c -o task08_3; task08_3
