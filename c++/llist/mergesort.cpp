#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

void split(struct node *head,struct node **a,struct node **b)
{
	struct node *fast,*slow;
	if(head==NULL || head->next==NULL)
	{
		*a=head;
		*b=NULL;
		
	}
	else
	{
		fast=head->next;
		slow=head;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
			fast=fast->next;
			slow=slow->next;
			}
		}
	}
	*a=head;
	*b=slow;
	slow->next=NULL;
}

struct node * merge(struct node *a,struct node *b)
{
	struct node *temp;
	
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a->data<b->data)
	{
		temp=a;
		temp->next=merge(a->next,b);
	}
	else
	{
		temp=b;
		temp->next=merge(a,b->next);
	}
	
	return temp;
}
		
void mergesort(struct node **head)
{
	if(*head==NULL || (*head)->next==NULL)
		return;
	struct node *first,*second;
	split(*head,&first,&second);
	mergesort(&first);
	mergesort(&second);
	*head=merge(first,second);
}
		
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
    	cout<<"hee"<<endl;
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
} 


/* Function to push a node */
void push(int new_data,struct node **head)
{
    struct node *newnode=new struct node;
    newnode->data=new_data;
    
    	
    
    newnode->next=*head;
   *head=newnode;
    
    cout<<"here"<<endl;
}
 
  
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node *head = NULL;
   
     push(20,&head);
     //cout<<head->data<<endl;
     push( 4,&head);
     push( 15,&head); 
     push( 85,&head);      
     
     printList(head);    
    mergesort(&head);                     
     printf("\n Reversed Linked list \n");
     printList(head);    
    
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
