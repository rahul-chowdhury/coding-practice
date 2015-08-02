#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *prev,*next;
};
struct node * fun(struct node *head_ref)
{
    struct node *temp = NULL;
    struct node *current = head_ref;
 
    while (current !=  NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    if(temp != NULL )
        return temp->prev;
}


int main()
{

int i=0;
struct node *head=NULL;
struct node *temp=(struct node *)malloc(sizeof(struct node));
struct node *temp1=(struct node *)malloc(sizeof(struct node));
struct node *temp2=(struct node *)malloc(sizeof(struct node));
struct node *temp3=(struct node *)malloc(sizeof(struct node));
struct node *temp4=(struct node *)malloc(sizeof(struct node));
struct node *temp5=(struct node *)malloc(sizeof(struct node));
temp->prev=NULL;
temp->next=temp1;
temp1->prev=temp;
temp1->next=temp2;
temp2->prev=temp1;
temp2->next=temp3;
temp3->prev=temp2;
temp3->next=temp4;
temp4->prev=temp3;
temp4->next=temp5;
temp5->prev=temp4;
temp5->next=NULL;
temp->data=i++;
temp1->data=i++;
temp2->data=i++;
temp3->data=i++;
temp4->data=i++;
temp5->data=i++;
head=temp;

head=fun(head);
while(head!=NULL)
{
printf("%d ",head->data);
head=head->next;
}
return 0;
}



















