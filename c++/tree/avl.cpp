#include<stdio.h>
struct node
{
	int data,height;
	struct node *left,*right;
};


int max(int a,int b)
{
	if(a>b)return a;
	return b;
}

int height(struct node *root)
{
	if(root==NULL)
		return -1;
	else
		return root->height;
}
struct node *single_rotate_left(struct node *x)
{
	struct node *temp=x->left;
	x->left=temp->right;
	temp->right=x;
	x->height=max((x->left)->height,(x->right)->height)+1;
	temp->height=max((temp->left)->height,(temp->right)->height)+1;
	return temp;
}

struct node *single_rotate_right(struct node *x)
{
	struct node *temp=x->right;
	x->right=temp->left;
	temp->left=x;
	x->height=max((x->left)->height,(x->right)->height)+1;
	temp->height=max((temp->left)->height,(temp->right)->height)+1;
	return temp;
}

struct node *left_right_rotate(struct node *x)
{
	x->left=single_rotate-right(x->left);
	return single_rotate_left(x);
}

struct node *right_left_rotate(struct node *x)
{
	x->right=single_rotate-left(x->right);
	return single_rotate_right(x);
}
	
struct node *insert(struct node *root,int x)
{
	if(root==NULL)
	{
		root=new struct node;
		root->data=x;
		root->left=root->right=NULL;
	}		
	else
	{
		if(x<root->data)
		{
			root->left=insert(root->left,x);
			if((height(root->left)-height(root->right))==2)//left subtree is longer
			{
				if(x<(root->left)->data)
				{
					root=single_rotate_left(root);
				}
				else
				{
					root=left_right_rotate(root);
				}
			}
		}
		
		if(x>=root->data)
		{
			root->right=insert(root->right,x);
			if((height(root->left)-height(root->right))==-2)//right subtree is longer
			{
				if(x>(root->right)->data)
				{
					root=single_rotate_right(root);
				}
				else
				{
					root=right_left_rotate(root);
				}
			}
		}
	}
	root->height=max(height(root->left),height(root->right))+1;
	return root;
}


int is_avl(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int left_height=is_avl(root->left),right_height=is_avl(root_right);
	if(left_height==-1 || right_height==-1)
		return -1;
	if((left_height-right_height)<=1 && (left_height-right_height)>=-1)
	{
		return max(left_height,right_height)+1;
	}
	else
		return -1;
}		


































