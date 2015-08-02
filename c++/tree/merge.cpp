#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};

struct node * merge(struct node *root1,struct node *root2)
{	
	
	if(root1==NULL && root2==NULL)
	{
		
		return 	NULL;
	}
	if(root1==NULL)
	{
		cout<<"root2="<<root2->data<<endl;
		node * root=new node;
		root->data=root2->data;
		root->left=merge(NULL,root2->left);
		root->right=merge(NULL,root2->right);
		return root;
	}
	
	if(root2==NULL)
	{
		cout<<"root1="<<root1->data<<endl;
		node * root=new node;
		root->data=root1->data;
		root->left=merge(root1->left,NULL);
		root->right=merge(root1->right,NULL);
		return root;
	}
	cout<<"root1="<<root1->data<<" root2= "<<root2->data<<endl;
	if(root1->data<root2->data)
	{
		node * root=new node;
		root->data=root1->data;
		root->left=merge(root1->left,root2->left);
		root->right=merge(root1->right,root2);
		return root;
	}
	else
	{
		node * root=new node;
		root->data=root2->data;
		root->left=merge(root1->left,root2->left);
		root->right=merge(root1,root2->right);
		return root;
	}
}
	
	
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
int main()
{
    /* Create following tree as first balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    struct node *root1  = newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);
 
    /* Create following tree as second balanced BST
            80
           /  \
         40   120
    */
    struct node *root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);
 	
    struct node *root = merge(root1, root2);
 
    printf ("Following is Inorder traversal of the merged tree \n");
    printInorder(root);
 
    
    return 0;
}
	
