#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*stnode;

void createNodeList(int n);     				//function to create the list
void displayList();             				//function to display the list
void insertNode(int num, int pos);	    //function to insert node at the middle
void deleteNode(int pos);	//function to delete a node from middle

void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
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

void displayList()
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

void insertNode(int num, int pos)
{
    int i;
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num; //Links the data part
        fnNode->nextptr = NULL;
        tmp = stnode;
        for(i=2; i<=pos-1; i++)
        {
            tmp = tmp->nextptr;
 
            if(tmp == NULL)
                break;
        }
        if(tmp != NULL)
        {
            fnNode->nextptr = tmp->nextptr;  //Links the address part of new node
            tmp->nextptr = fnNode;   
        }
        else
        {
            printf(" Insert is not possible to the given position.\n");
        }
    }
}

void deleteNode(int pos)
{
    int i;
    struct node *toDelMid, *preNode;
 
    if(stnode == NULL)
    {
        printf(" There are no nodes in the List.");
    }
    else
    {
        toDelMid = stnode;
        preNode = stnode;
 
        for(i=2; i<=pos; i++)
        {
            preNode = toDelMid;
            toDelMid = toDelMid->nextptr;
 
            if(toDelMid == NULL)
                break;
        }
        if(toDelMid != NULL)
        {
            if(toDelMid == stnode)
                stnode = stnode->nextptr;
 
            preNode->nextptr = toDelMid->nextptr;
            toDelMid->nextptr = NULL;
            free(toDelMid);
        }
        else
        {
            printf(" Deletion can not be possible from that position.");
        }
    }
}

int FindElement(int FindElem)
{
	int ctr=1;
	struct node* ennode = stnode;
	while(ennode->nextptr!=NULL)
	{
		if(ennode->num==FindElem)
			break;
		else
			ctr++;
			ennode=ennode->nextptr;
	}
	return ctr;
}

int main()
{
    int n,num,pos;
	
    printf(" Input the number of nodes (3 or more) : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list are : \n");		
    displayList();
    printf("\n Input data to insert in the middle of the list : ");
    scanf("%d", &num);
    printf(" Input the position to insert new node : " );
    scanf("%d", &pos);

		if(pos<=1 || pos>=n)
    {
     printf("\n Insertion can not be possible in that position.\n ");
    }

		if(pos>1 && pos<n)      
		{
			insertNode(num, pos);
			printf("\n Insertion completed successfully.\n ");
		}

    printf("\n The new list are : \n");		
    displayList();
		printf("\n Input the position of node to delete : ");
    scanf("%d", &pos);

    if(pos<=1 || pos>=n)
    {
     printf("\n Deletion can not be possible from that position.\n ");
    }

	  if(pos>1 && pos<n)
		{
			printf("\n Deletion completed successfully.\n ");
			deleteNode(pos);
		}

	  printf("\n The new list are  : \n");	
    displayList();

    int FindElem, FindPlc;
		printf("\n");
		printf(" Input the element to be searched : ");
		scanf("%d",&FindElem);
		FindPlc = FindElement(FindElem);
		if(FindPlc<=n)
			printf(" Element found at position %d \n\n",FindPlc);
		else
			printf(" This element does not exists in linked list.\n\n");

    return 0;
}