#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
};

void createNodeList(struct node ** stnode_p, int n);     				//function to create the list
void displayList(struct node * stnode);             				//function to display the list
struct node* addTwoNumbers(struct node* l1, struct node* l2);

void createNodeList(struct node ** stnode_p, int n)
{
    struct node *stnode, *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    *stnode_p = stnode;
    if(stnode == NULL) //check whether the stnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
			// reads data for the node through keyboard
			printf(" Input data for node 1 : ");
			scanf("%d", &num);
			stnode-> num = num;      
			stnode-> nextptr = NULL; //Links the address field to NULL
			tmp = stnode;
			//Creates n nodes and adds to linked list
			for(i=2; i<=n; i++)
			{
					fnNode = (struct node *)malloc(sizeof(struct node));
					if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
					{
							printf(" Memory can not be allocated.");
							break;
					}
					else
					{
							printf(" Input data for node %d : ", i);
							scanf(" %d", &num);

							fnNode->num = num;      // links the num field of fnNode with num
							fnNode->nextptr = NULL; // links the address field of fnNode with NULL

							tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
							tmp = tmp->nextptr;
					}
			}
    }
} 

void displayList(struct node * stnode)
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
} 

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    struct node *head = NULL, *tail = NULL;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->num : 0;
        int n2 = l2 ? l2->num : 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = malloc(sizeof(struct node));
            tail->num = sum % 10;
            tail->nextptr = NULL;
        } else {
            tail->nextptr = malloc(sizeof(struct node));
            tail->nextptr->num = sum % 10;
            tail = tail->nextptr;
            tail->nextptr = NULL;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->nextptr;
        }
        if (l2) {
            l2 = l2->nextptr;
        }
    }
    if (carry > 0) {
        tail->nextptr = malloc(sizeof(struct node));
        tail->nextptr->num = carry;
        tail->nextptr->nextptr = NULL;
    }
    return head;
}

int main()
{
    int n;
    struct node *l1, *l2, *l3;
	
    printf(" Input the number of nodes (3 or more) for l1 : ");
    scanf("%d", &n);
    createNodeList(&l1, n);
    printf("\n Data entered in the list l1 are : \n");		
    displayList(l1);

    printf(" Input the number of nodes (3 or more) for l2 : ");
    scanf("%d", &n);
    createNodeList(&l2, n);
    printf("\n Data entered in the list l2 are : \n");		
    displayList(l2);

    printf("\n Result of l1 adds l2 : \n");
    l3 = addTwoNumbers(l1, l2);
    displayList(l3);
    
    return 0;
}


