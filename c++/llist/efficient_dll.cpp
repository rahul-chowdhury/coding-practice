#include<iostream>
#include <stdint.h> 
using namespace std;

struct node
{
	int data;
	struct node *diff;
};

struct node *create(struct node *prev,int data)
{
	struct node *newnode=new struct node;
	newnode->data=data;
	newnode->diff=(struct node *)((uintptr_t)prev^(uintptr_t)NULL);
	if(prev!=NULL)
	prev->diff =(struct node *)((uintptr_t)prev->diff^(uintptr_t)newnode);
	return newnode;
}

void printlist(struct node *head)
{
	if(head==NULL)
	return;
	struct node *prev=NULL,*cur=head,*next;
	
	while(cur!=NULL)
	{
		next=(struct node *)((uintptr_t)prev^(uintptr_t)cur->diff);
		//cout<<"here"<<endl;
		cout<<cur->data<<" ";
		prev=cur;
		cur=next;
		
	}
	cout<<endl;
}

int main()
{
	struct node *node1,*node2,*node3;
	node1=create(NULL,1);
	node2=create(node1,2);
	node3=create(node2,3);
	printlist(node1);
	return 0;
}







