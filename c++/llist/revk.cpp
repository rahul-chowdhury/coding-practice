#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void reverse(struct node **previous,struct node **head,int k)
{
	
	int count=0;
	struct node *temp=*head,*prev=*previous,*cur,*next=NULL;
	
	
	while(count!=k && temp!=NULL)	
	{
		
		cur=temp;
		if(cur==NULL)
		{
			break;
		}
		else
		{
			next=cur->next;
		}
		cur->next=prev;
		prev=cur;
		cur=next;
		if(cur!=NULL)
		next=cur->next;
		temp=cur;
		count++;
	}
	if(*previous!=NULL)
	(*previous)->next=prev;
	*previous=*head;
	(*head)->next=cur;
	*head=prev;
}
	
struct node *revk(struct node *head,int k)
{
	if(head==NULL || head->next==NULL)
	return head;
	int count=0;
	struct node *temp,*prev_tail=NULL;
	while(head!=NULL)
	{
		
		reverse(&prev_tail,&head,k);
		if(count==0)
			temp=head;
		head=prev_tail->next;
		count++;
		
	}
	return temp;
}	
			




void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}    
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8 */
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);           
 
     printf("\n Given linked list \n");
     printList(head);
     head = revk(head, 3);
 
     printf("\n Reversed Linked list \n");
     printList(head);
 
     return(0);
}
