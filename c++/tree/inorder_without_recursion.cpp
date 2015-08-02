#include<iostream>
#include<stack>
using namespace std;


struct node
{
	struct node *left,*right;
	int data;
};


void preorder(struct node *root)
{
	struct node *temp=root;
	stack<struct node *> s;
	s.push(temp);
	while(!s.empty())
	{
		temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
		if(temp->right!=NULL)
		s.push(temp->right); 
		if(temp->left!=NULL)
		s.push(temp->left);
		
	}
	cout<<endl;
}

void inorder(struct node *root)
{
	stack<struct node *> s;
	s.push(root);
	while(1)
	{
		
		while(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		if(s.empty())
			break;
		root=s.top();
		s.pop();
		cout<<root->data<<" ";
		root=root->right;
	}
	cout<<endl;
}

void postorder(struct node *root)
{
	stack<struct node *> s;
	s.push(root);
	while(1)
	{
		
		while(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		if(s.empty())
			break;
		root=s.top();
		s.pop();
		cout<<root->data<<" ";
		root=root->data;
	}
	cout<<endl;
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
    preorder(root);
     inorder(root);
      //postorder(root);
    return 0;
}
		
	
