#include<stdlib.h>
#include<stdio.h>

struct node { 
    int data; 
    struct node* next; 
}; 
  
struct queue { 
    struct node *head;
    struct node *tail; 
}; 

struct queue* initialize() {
	struct queue* q = malloc(sizeof(struct queue));

	q->head = NULL;
	q->tail = NULL;
	return q;
}
  
// Function to create Circular queue 
void enQueue(struct queue *q, int value) { 
    struct node *temp = malloc(sizeof(struct node));; 
    temp->data = value; 
    if (q->head == NULL) 
        q->head = temp; 
    else
        q->tail->next = temp; 
  
    q->tail = temp; 
    q->tail->next = q->head; 
} 
  
// Function to delete element from Circular Queue 
int deQueue(struct queue *q) { 
    if (q->head == NULL) { 
        printf ("Queue is empty\n"); 
        return -1; 
    } 
  
    // If this is the last node to be deleted 
    int value; // Value to be dequeued 
    if (q->head == q->tail) { 
        value = q->head->data; 
        free(q->head); 
        q->head = NULL; 
        q->tail = NULL; 
    } 
    // There are more than one nodes 
    else { 
        struct node *temp = q->head; 
        value = temp->data; 
        q->head = q->head->next; 
        q->tail->next= q->head; 
        free(temp); 
    } 
  
    return value ; 
} 
  
// Function displaying the elements of Circular Queue 
void displayQueue(struct queue *q) { 
    struct node *temp = q->head; 
    printf("[ "); 
    while (temp->next != q->head) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("%d ]\n", temp->data); 
} 
  
/* Driver of the program */
int main() { 
    // Create a queue and initialize front and rear 
    struct queue* q = initialize();
  
    // Inserting elements in Circular Queue 
    enQueue(q, 14); 
    enQueue(q, 22); 
    enQueue(q, 6); 
  
    // Display elements present in Circular Queue 
    displayQueue(q); 
  
    // Deleting elements from Circular Queue 
    printf("Deleted value = %d\n", deQueue(q)); 
    printf("Deleted value = %d\n", deQueue(q)); 
  
    // Remaining elements in Circular Queue 
    displayQueue(q); 
  
    enQueue(q, 9); 
    enQueue(q, 20); 
    displayQueue(q); 
  
    return 0; 
}
// Linux, Mac: gcc task07_2.c -o task07_2; ./task07_2
// Windows: gcc task07_2.c -o task07_2; task07_2
