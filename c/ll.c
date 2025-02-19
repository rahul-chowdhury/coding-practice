#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};




void SplitList(struct node *head,struct node **a,struct node **b)
{
	struct node *slow,*fast;
	fast=head->next;
	slow=head;
	if(head==NULL || head->next==NULL)
	{
		*a=head;
		*b=NULL;
	}
	else
	{	
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				fast=fast->next;
				slow=slow->next;
			}
		}
		*a=head;
		*b=slow->next;
		slow->next=NULL;
	}
}

struct node *Merge(struct node *a,struct node *b)
{
	struct node *result;
	
	//base case
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	
	if(a->data<b->data)
	{
		result=a;
		result->next=Merge(a->next,b);
	}
	else
	{
		result=b;
		result->next=Merge(a,b->next);
	}
	return result;
}
	
	

void MergeSort(struct node **head_ref)
{
	struct node *head=*head_ref;
	struct node *a=NULL,*b=NULL;
	if(head==NULL || head->next==NULL)
	{
	return;
	}
	
	SplitList(head,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	*head_ref=Merge(a,b);
}
































/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
 
/* Function to insert a node at the beginging of the linked list */
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
  
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;
  
  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 
  
  /* Sort the above created Linked List */
  MergeSort(&a);
  
  printf("\n Sorted Linked List is: \n");
  printList(a);           
  
  ;
  return 0;
}
