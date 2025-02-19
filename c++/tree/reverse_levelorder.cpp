#include<iostream>
#include<stack>
#include<queue>
#include<limits.h>
using namespace std;


struct node
{
	struct node *left,*right;
	int data;
};

int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
	
int height(struct node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

int level(struct node *root)
{
	int ilevel=0;
	if(root==NULL)
		return 0;
	queue<struct node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		if(root==NULL)
		{
			if(q.empty())
				break;
			q.push(NULL);
			ilevel++;
		}
		else
		{
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
		}
	}
	return ilevel;
}
int diameter_helper(struct node *root)
{
	if(!root)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return max(diameter_helper(root->left),diameter_helper(root->right))+1;
}
int diameter(struct node *root)
{

	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	return diameter_helper(root->left)+diameter_helper(root->right)+1;
}
	

void reverse_levelorder(struct node *root)
{
	queue<struct node *> q;
	stack<struct node *> s;
	q.push(root);
	while(!q.empty())
	{
		struct node *temp=q.front();
		q.pop();
		if(temp->right!=NULL)
		q.push(temp->right);
		if(temp->left!=NULL)
		q.push(temp->left);
		s.push(temp);
	}
	while(!s.empty())
	{
		cout<<(s.top())->data<<" ";
		s.pop();
	}
}
int max_level_sum(struct node *root)
{
	int sum=0,max=INT_MIN,maxlevel=0,level=0;
	queue<struct node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		if(!root)
		{
			if(sum>max)
			{
				max=sum;
				maxlevel=++level;
			}
			if(q.empty())
				break;
			sum=0;
			q.push(NULL);
		}
		else
		{
			sum +=root->data;
			if(root->left!=NULL)
				q.push(root->left);
			if(root->right!=NULL)
				q.push(root->right);
		}
	}
	return maxlevel;
}

void all_root_to_leaf_paths(struct node *root,int *a,int x)
{
	if(root==NULL)
		return;
	a[x++]=root->data;
	if(root->left==NULL && root->right==NULL)
	{
		for(int i=0;i<x;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
	all_root_to_leaf_paths(root->left,a,x);
	all_root_to_leaf_paths(root->right,a,x);
}		

struct node * create_tree(int *preorder,int *levelorder,int n)
{
	if(n==0)
		return NULL;
	
	struct node *root=new struct node;
	root->data=levelorder[0];
	queue<struct node *> q;
	q.push(root);
	while(!q.empty())
	{
		
	
					
		
int count_leaves(struct node *root)
{
	int count=0;
	queue<struct node *> q;
	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		cout<<root->data<<endl;
		q.pop();
		if( ((root->left!=NULL) && (root->right==NULL)) || ((root->left==NULL) && (root->right!=NULL)) )
		{	
			count++;
			//cout<<root->left->data<<endl;
		}
		
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
		
	}
	return count;
}
		
bool identical(struct node *root1,struct node *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	else if(root1==NULL)
		return false;
	else if(root2==NULL)
		return false;
	return (identical(root1->left,root2->left) && identical(root1->right,root2->right));
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
     root->left->right = newNode(40);
      root->right->left = newNode(25);
    root->right->right = newNode(5);
    cout<<height(root)<<endl;
     cout<<count_leaves(root)<<endl;
      //postorder(root);
      
      struct node * root1 = newNode(10);
    root1->left = newNode(30);
    root1->right = newNode(15);
    root1->left->left = newNode(550);
     root1->left->right = newNode(40);
      root1->right->left = newNode(25);
    root1->right->right = newNode(5);
    
    if(identical(root,root1))
    cout<<"identical"<<endl;
    else
    	 cout<<"not identical"<<endl;
    cout<<diameter(root)<<endl;
    cout<<max_level_sum(root)<<endl;
    int *a=new int[100];
    all_root_to_leaf_paths(root,a,0);
    return 0;
}
		
	
