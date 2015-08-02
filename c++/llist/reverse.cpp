#include<stdio.h>

using namespace std;

struct node 
{
	int data;
	struct node *pointer;
};
struct node *head;
void reverse()
{
	if(head==NULL)
		return;
	if(head->pointer==NULL)
		return;
	struct node *prev,*cur,*next;
	cur=head->pointer;
	prev=head;
	next=(head->pointer)->pointer;
	prev->pointer=NULL;
	while(cur!=NULL)
	{
		cur->pointer=prev;
		prev=cur;
		cur=next;
		if(next!=NULL)
		next=next->pointer;
	}
	head=prev;
}

void printList()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->pointer;  
    }
} 


/* Function to push a node */
void push(int new_data)
{
    struct node *newnode=new struct node;
    newnode->data=new_data;
    if(head==NULL)
    {
    	head=newnode;
    	head->pointer=NULL;
    	return;
    }
    newnode->pointer=head;
    head=newnode;
    
    
}
 
  
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    head = NULL;
   
     push(20);
     push( 4);
     push( 15); 
     push( 85);      
     
     printList();    
     reverse();                      
     printf("\n Reversed Linked list \n");
     printList();    
    
}





















	
