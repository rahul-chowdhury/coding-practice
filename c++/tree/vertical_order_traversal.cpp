#include<bits/stdc++.h>
using namespace std;
typedef unordered_multimap<int,int> treemap;

struct Node
{
    int data;
    Node *left, *right;
};
 
// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void store_in_hashmap(treemap &m,struct Node *root,int *min,int *max,int vertical)
{
	if(!root)
		return;
	if(vertical<*min)
		*min=vertical;
	if(vertical>*max)
		*max=vertical;	
	m.insert({vertical,root->data});
	store_in_hashmap(m,root->left,min,max,vertical-1);
	store_in_hashmap(m,root->right,min,max,vertical+1);
}

void print_elements_of_a_bucket(treemap::value_type& x)
{
	cout << " " << x.second;
}
void printVerticalOrder(struct Node *root)
{
	treemap m;
	int max=0,min=0;
	store_in_hashmap(m,root,&min,&max,0);
	for(int i=min;i<=max;i++)
	{
		auto range = m.equal_range(i); 
		for_each (
		    range.first,
		    range.second,
		    print_elements_of_a_bucket
		  );
		  cout<<endl;
	}
	cout<<endl;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
