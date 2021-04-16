/* Copied from https://github.com/JeromeHadorn/UZH_CS_Bachelor_Neuroinformatics/ */

#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node **init()
{
    struct node **l;
    l = malloc(sizeof(struct node **));
    *l = NULL;
    return l;
}

int first(struct node **l)
{
    if (*l == NULL)
        return -1;
    else
        return (*l)->val;
}

void insert(struct node **l, int x)
{
    struct node *p;
    struct node *q;
    if (*l == NULL || (*l)->val > x)
    {
        p = malloc(sizeof(struct node));
        p->val = x;
        p->next = *l;
        *l = p;
    }
    else
    {
        p = *l;
        while (p->next != NULL && p->next->val < x)
        {
            p = p->next;
        }
        q = malloc(sizeof(struct node));
        q->val = x;
        q->next = p->next;
        p->next = q;
    }
}

int main()
{
    struct node *root1;
    struct node *root2;
    return 0;
}