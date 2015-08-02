#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
stack<int> s,s1;
int sum=0;
struct node
{
	int data;
	struct node *left,*right;
};

struct node* 	newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

void inorder(struct node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	s.push(root->data);
	inorder(root->right);
}

void rev_inorder(struct node *root)
{
	if(root==NULL)
	return;
	rev_inorder(root->right);
	sum +=root->data;
	root->data=sum;
	
	rev_inorder(root->left);
		
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

int main()
{
	
node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13);
    //inorder(root);
    rev_inorder(root);
    printInorder(root);
    /*cout<<s.size()<<s1.size()<<endl;
    while(s.size()!=0 && s1.size()!=0)
    {
    	int sum=s.top()+s1.top();
    	cout<<sum<<"="<<s.top()<<"+"<<s1.top()<<endl;
    	if(sum==target)
    	{
    		check=true;
    		break;
    	}
    	else if(sum<target)
    	{
    		s1.pop();
    	}
    	else
    	{
    		s.pop();
    	}
    }
    
    if(check)
    cout<<"sum="<<s.top()<<"+"<<s1.top()<<endl;*/
    return 0;
   }


















