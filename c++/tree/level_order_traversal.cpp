#include<iostream>
#include<queue>
using namespace std;

struct node 
{
	int data;
	struct node *left,*right;
};

void printlevel(node *root,int low,int high)
{
	int level=0;
	node* marker=new node;
	queue <node *>q;
	q.push(root);
	q.push(marker);
	while(q.empty()==0)
	{
		node *x=q.front();
		q.pop();
		if(x==marker)
		{
			cout<<endl;
			level++;
			if(q.empty() || level>high)
				break;
			q.push(marker);
			continue;
		}
		
		if(level>=low)
		{
			cout<<x->data<<" ";
		}
		if(x->left!=NULL)q.push(x->left);
		if(x->right!=NULL)q.push(x->right);
		
	}
}

int count_nodes_in_range(struct node *root,int a,int b)
{
	if(root==NULL)
		return 0;
	if((root->data<=b) && root->data>=a)
	{
		return count_nodes_in_range(root->left,a,b)+count_nodes_in_range(root->right,a,b)+1;
	}
	else if (root->data>b)
	{
		return count_nodes_in_range(root->left,a,b);
	}
	else if(root->data<a)
	{
		return count_nodes_in_range(root->right,a,b);
	}
	
}

node *newNode(int x)
{
	node *node1=new node;
	node1->data=x;
	node1->left=NULL;
	node1->right=NULL;
	return node1;
}

int is_avl(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	cout<<"node is"<<root->data<<endl;
	int left_height=is_avl(root->left),right_height=is_avl(root->right);
	//cout<<"node is"<<root->data<<" left height is "<<left_height<<" right height is "<<right_height<<endl;
	if(left_height==-1 || right_height==-1)
		return -1;
	if((left_height-right_height)<=1 && (left_height-right_height)>=-1)
	{
		return max(left_height,right_height)+1;
	}
	else
		return -1;
}		


int main()
{
    // Let us construct the BST shown in the above figure
    node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    (root->left)->left         = newNode(4);
    (root->left)->right        = newNode(12);
    (root->left->right)->left  = newNode(10);
    (root->left->right)->right = newNode(14);
 
    cout << "Level Order traversal between given two levels is";
    //printlevel(root, 1, 2);
    if(is_avl(root)==-1)
    	cout<<"tree is not avl tree"<<endl;
    else
    	cout<<"tree is avl tree"<<endl;
    cout<<count_nodes_in_range(root,10,20)<<endl;
    return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
