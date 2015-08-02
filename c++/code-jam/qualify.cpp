#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test,size,reserve,required;
	string s;
	scanf("%d",&test);
	int min[test];
	for(int i=1;i<=test;i++)
	{
		scanf("%d",&size);
		reserve=0;
		required=0;
		//tring s[size+1];
		cin>>s;
		if(s[0]-48>1)
			reserve +=s[0]-48;
		
		for(int j=1;j<=size;j++)
		{
			
			
			
			if(reserve<=0)
			{
					required++;
					reserve++;
			}
			reserve +=(s[j]-48);
			
			reserve--;
		}
		min[i-1]=required;
	}
	for(int i=1;i<=test;i++)
	{
		printf("Case #%d: %d\n",i,min[i-1]);
	}
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
				
		
