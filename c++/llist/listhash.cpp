#include<iostream>

#include<map>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

map<struct node *,int>m;
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
    	cout<<"hee"<<endl;
        cout<< temp->data<<" ";    
        temp = temp->next;  
    }
} 


/* Function to push a node */
void push(struct node **head,int new_data)
{
    struct node *newnode=new struct node;
    newnode->data=new_data;
    
    	
    
    newnode->next=*head;
   *head=newnode;
  
}

	

int main()
{
	struct node *head = NULL,*temp,*prev=NULL;
   
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
 
    /* Create a loop for testing */
    head->next->next->next->next= head->next->next; 
     temp=head;
     bool loop=false;
     cout<<m[temp]<<endl;
     while(temp!=NULL)
     {
     	if(m[temp]==0)
     	m[temp]=temp->data;
     	else
     	{
     		loop=true;
     		break;
     	}
     	prev=temp;
     	temp=temp->next;
     }
	if(loop==true)
	{
	cout<<"loop there at "<<prev->data<<endl;
	prev->next==NULL;
	}
	else
	{
	cout<<"no loop"<<endl;
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
