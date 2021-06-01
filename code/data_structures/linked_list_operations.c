// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node
{
    int item;
    struct Node *next;
};

void insertAtBeginning(struct Node **ref, int data)
{
    // Allocate memory to a node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // insert the item
    new_node->item = data;
    new_node->next = (*ref);

    // Move head to new node
    (*ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node *node, int data)
{
    if (node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->item = data;
    new_node->next = node->next;
    node->next = new_node;
}

// Insert a new node at specific position
void append(struct list *listA, int val)
{
    struct node *curr;
    struct node *new = malloc(sizeof(struct node));
    new->val = val;
    new->next = NULL;
    if (listA->head == NULL)
        listA->head = new;
    else
    {
        curr = listA->head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new;
    }
}
void insertAtEnd(struct Node **ref, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *ref;

    new_node->item = data;
    new_node->next = NULL;

    if (*ref == NULL)
    {
        *ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void deleteNode(struct Node **ref, int key)
{
    struct Node *temp = *ref, *prev;

    if (temp != NULL && temp->item == key)
    {
        *ref = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->item != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL)
        return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}

// Print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->item);
        node = node->next;
    }
}

// rotate elements inside a linked list
void rotateList1(int m)
{
    int i;
    int n;
    struct list *previous;
    struct list *current;
    current = head;
    n = 0;
    while (current != NULL)
    {
        n++;
        current = current->next;
    }
    m = m % n;
    for (i = 0; i < m; i++)
    {
        current = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        tail->next = head;
        tail = previous;
        head = previous->next;
        previous->next = NULL;
    }
}

// Driver program
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAfter(head->next, 5);

    printf("Linked list: ");
    printList(head);

    printf("\nAfter deleting an element: ");
    deleteNode(&head, 3);
    printList(head);

    rotateList1(5);
}
