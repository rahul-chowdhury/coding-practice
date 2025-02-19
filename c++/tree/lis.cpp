
#include <stdio.h>
#include <stdlib.h>
 
// A utility function to find max of two integers
int max(int x, int y) { return (x > y)? x: y; }
 
/* A binary tree node has data, pointer to left child and a pointer to 
   right child */
struct node
{
    int data;
    int liss;
    struct node *left, *right;
};

int lis(struct node *root)
{
	int lis_incl
	if(root==NULL)
		return 0;
	if(root->liss!=0)
		return root->liss;
	if(root->left==NULL && root->right==NULL)
		return (root->liss=1);
	if(root->left!=NULL)
	{
		lis_incl +=lis(root->left->right)+lis(root->left->left);
	}
	if(root->right!=NULL)
	{
		root->liss =lis(root->right->right)+lis(root->right->left);
	}
	return root->liss;
}

struct node* newNode(int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->liss = 0;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printf ("Size of the Largest Independent Set is %d ", lis(root));
 
    return 0;
}
