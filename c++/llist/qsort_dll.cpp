#include<stdio.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next,*prev;
};
void printList(struct node *,struct node *);
struct node *head,*tail;
struct node * partition(struct node **head1,struct node **tail1)
{
	if(*head1==NULL)
	return 	NULL;
	if(*head1==*tail1)
	return NULL;
	int x=(*head1)->data,size=0,i,j;
	struct node *temp=*head1,*front=*head1,*rear=*tail1;
	while(temp!=*tail1){size++;temp=temp->next;}
	cout<<"part"<<endl;
	//struct node *i=head,*j=tail;
	j=size;
		i=0;
	while(true)
	{
		cout<<(*head1)->data<<endl;
		//cout<<(front->prev)->data<<endl;
		cout<<(front->next)->data<<endl;
		cout<<(*tail1)->data<<endl;
		printList(*head1,*tail1);
		//cout<<tail1->data<<endl;
		while(front!=*tail1 && front->data<x)
		{//cout<<i<<endl;
		front=front->next;i++;}
		cout<<"here"<<endl;
		while(rear!=*head1 && rear->data>=x)
		{rear=rear->prev;j--;}
		/*cout<<front->data<<endl;
		cout<<rear->data<<endl;
		cout<<head1->data<<endl;
		cout<<tail1->data<<endl;*/
		if(i<j)
		{
			cout<<"less"<<i<<j<<endl;
			if(front==head)
			head=rear;
			if(rear==tail)
			tail=front;
			struct node *temp1=front->prev,*temp2=rear->next,*temp3=rear->prev,*temp4=front->next;
			if(temp1!=NULL)
			temp1->next=rear;
			if(temp4!=NULL)
			temp4->prev=rear;
			if(rear!=NULL)
			rear->prev=temp1;
			if(rear!=NULL)
			rear->next=temp4;
			
			if(temp3!=NULL)
			temp3->next=front;
			
			front->prev=temp3;
			if(temp2!=NULL)
			temp2->prev=front;
			front->next=temp2;
			temp1=front;
			front=rear;
			rear=temp1;
			if(
			temp1=*head1;
			*head1=*tail1;
			*tail1=temp1;
			
			
		}
		else
		return rear;
		
	}
		
}


		
void quicksort(struct node *head1,struct node *tail1)
{
	cout<<"qsort"<<endl;
	if(head1==NULL || (head1)->next==NULL)
		return ;
	struct node *x;
	cout<<"lala"<<endl;
	x=partition(&head1,&tail1);
	
	cout<<"qsort"<<head1->data<<endl;
	if(x==NULL)
	return;
	quicksort(head1,x);
	quicksort(x->next,tail1);
	
}
		
void printList(struct node *head1,struct node *tail1)
{
    struct node *temp = head1;
    while(temp != tail1->next)
    {
    	
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
    cout<<endl;
} 



 
  void push( int new_data)
{
    /* allocate node */
    struct node* new_node = new node;
 
    /* put in the data  */
    new_node->data  = new_data;
 	new_node->prev=NULL;
    if(head==NULL)
    {
    	
    	new_node->next=NULL;
    	head=new_node;
    }
    else
    {
    	new_node->next=head;
    	head->prev=new_node;
    	head=new_node;
    }   	
    
}
 
int main()
{
	head=NULL;
    
    push( 5);
    push( 20);
    push( 4);
    push( 3);
    push( 30);
 tail=head;
    cout << "Linked List before sorting \n";
   printList(head,tail);
 	while(tail->next!=NULL){tail=tail->next;}
    quicksort(head,tail);
 
    cout << "Linked List after sorting \n";
    printList(head,tail);
 
    return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
