/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;           // Value
    struct node *next; // Pointer
};

void printLinkedList(struct node *root)
{
    struct node *p;
    p = root;
    while (p != NULL)
    {
        printf("%d,", p->val);
        p = p->next;
    }
    printf("\n");
}

void countOcc(struct node *root, int x)
{
    int cnt = 0;
    struct node *p;
    p = root;

    while (p != NULL)
    {
        if (p->val == x)
        {
            cnt++;
        }
        p = p->next;
    }
    printf("%d appears %d time(s) \n", x, cnt);
}

int main()
{
    struct node *root;
    root = malloc(sizeof(struct node));
    root->val = 88;
    root->next = malloc(sizeof(struct node));

    struct node *p;
    p = root->next;
    p->val = 52;
    p->next = malloc(sizeof(struct node));

    p = p->next;
    p->val = 12;
    p->next = NULL;

    printLinkedList(root);
    //countOcc(root,878);

    // Inserting an Element at position 1
    p = malloc(sizeof(struct node));
    p->val = 11;
    p->next = root;
    root = p;

    printLinkedList(root);
    //Deleting element x from non-empty list
    int x = 52;
    p = root;
    if (p->val == x)
    {
        root = p->next;
        free(p);
    }
    else
    {
        while (p->next != NULL && p->next->val != x)
        {
            p = p->next;
        }
        struct node *tmp;
        tmp = malloc(sizeof(struct node));
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }

    printLinkedList(root);

    // recursive deletion of list
    p = root;
    struct node *q;
    q = malloc(sizeof(struct node));
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    //printLinkedList(root);
}

/* doubly linked list */

#include <stdlib.h>

struct doubleNode
{
    int value;
    struct doubleNode *prev;
    struct doubleNode *next;
};
int main()
{

    return 0;
}