struct trienode
{
	char data;
	bool end_of_string;
	struct trienode *child[26];
};

struct trienode * insert(struct trienode *root,string s,int i)
{
	if(s==NULL)
		return root;
	if(root==NULL)
	{
		struct trienode *newnode=new struct trienode;
		for(int i=0;i<26;i++)
		newnode->child[i]=NULL;
		newnode->data=s[i];
		if((s.length()-i)==1)
		{
			
			end_of_string=true;
		}
		else
		{
			end_of_string=false;
			newnode->child[s[i+1]]=insert(newnode->child[s[i+1]],s,i+1);
		}
		return newnode;
	}
	root->child[s[i]]=insert(newnode->child[s[i]],s,i+1);
	return root;
}
	
			
			
