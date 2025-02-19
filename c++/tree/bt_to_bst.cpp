#include<stdio.h>
#include<stdlib.h>
 #include<iostream>
 using namespace std;
/* A binary tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void putintoarray(int *a,struct node *root,int *index)
{
	if(root==NULL)
	return;
	a[(*index)++]=root->data;
	putintoarray(a,root->left,index);
	putintoarray(a,root->right,index);
}

int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

void makebst(int *a,struct node *root,int *index,int n)
{
	if(root==NULL)
	return;
	
	makebst(a,root->left,index,n);
	root->data=a[(*index)++];
	makebst(a,root->right,index,n);
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder (node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder (node->right);
}
 
struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
	struct node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    int a[5];
    int x=0;
    putintoarray(a,root,&x);
    
	qsort(a,5,sizeof(int),compare);
	
	x=0;
	makebst(a,root,&x,5);
	cout<<"lalal"<<endl;
	printInorder(root);
	
	return 0;
}

