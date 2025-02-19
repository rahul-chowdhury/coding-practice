#include<iostream>
#include<map>
using namespace std;



struct node
{
    int data;
    struct node* left, *right, *random;
};
 
/* Helper function that allocates a new Node with the
   given data and NULL left, right and random pointers. */
struct node* newNode(int key)
{
    struct node* temp = new struct node;
    temp->data= key;
    temp->random = temp->right = temp->left = NULL;
    return (temp);
}
 
/* Given a binary tree, print its Nodes in inorder*/
void printInorder(struct node* node1)
{
    if (node1 == NULL)
        return;
 
    /* First recur on left sutree */
    printInorder(node1->left);
 
    /* then print data of Node and its random */
    cout << "[" << node1->data << " ";
    if (node1->random == NULL)
        cout << "NULL], ";
    else
        cout << node1->random->data << "], ";
 
    /* now recur on right subtree */
    printInorder(node1->right);
}
multimap<struct node *,struct node *>m;
struct node * copyleftright(struct node *root)
{
	if(root==NULL)
		return root;
	struct node *newroot=new struct node;
	m.insert(pair<struct node *,struct node *>(root,newroot));
	newroot->data=root->data;
	newroot->left=copyleftright(root->left);
	newroot->right=copyleftright(root->right);
	//newnode->random=m[root->random];
	return newroot;
}

void copyrandom(struct node *newnode,struct node *root)
{
	if(root==NULL)
		return;
	multimap<struct node *,struct node *>::iterator i;
	i=m.find(root->random);
	newnode->random=i->second;
	copyrandom(newnode->left,root->left);
	copyrandom(newnode->right,root->right);
}

struct node *cloneTree(struct node *root)
{
	struct node *newnode=copyleftright(root);
	copyrandom(newnode,root);
	return newnode;
}

int main()
{
    //Test No 1
    struct node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;
 
    //  Test No 2
    //    tree = NULL;
 
    //  Test No 3
    //    tree = newNode(1);
 
    //  Test No 4
    /*    tree = newNode(1);
        tree->left = newNode(2);
        tree->right = newNode(3);
        tree->random = tree->right;
        tree->left->random = tree;
    */
 
    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);
 
    struct node *clone = cloneTree(tree);
 
    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);
 
    return 0;
}

