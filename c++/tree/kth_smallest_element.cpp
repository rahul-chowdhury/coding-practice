#include<iostream>
#include<climits>
using namespace std;
 
// A BST node
struct node
{
    int data;
    node *left, *right;
};

void find_kth_smallest_element(struct node *root,bool *check,int *count,int k,int *element)
{
	if(root==NULL)
		return;
	find_kth_smallest_element(root->left,check,count,k,element);
	(*count)++;
	//cout<<root->data<<" ";
	if(*count==k)
	{
		*element=root->data;
		*check = true;
		return;
	}
	if(*check)
		return;
	
	find_kth_smallest_element(root->right,check,count,k,element);
}
	
	

node *newNode(int item)
{
    node *temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with given data in BST */
node* insert(node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int kth_smallest_element,count;
    bool check;
    for (int k=1; k<=7; k++)
    {
    	check=false;
    	count =0;
    	find_kth_smallest_element(root,&check,&count,k,&kth_smallest_element);
	cout<<endl;
       cout << kth_smallest_element << endl;
     }
 
    return 0;
}	
		
		
