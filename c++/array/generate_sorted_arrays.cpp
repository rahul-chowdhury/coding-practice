#include<bits/stdc++.h>
using namespace std;

void print_array(int *a,int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void generate_arrays(int *a,int a_index,int *b,int b_index,int *result,int length,char turn,int len_a,int len_b)
{
	/*int len_a=sizeof(a)/sizeof(a[0]),len_b=sizeof(b)/sizeof(b[0]);*/
	//cout<<"a's length"<<len_a<<endl;
	if(length!=0 && length%2==0)
	{
		print_array(result,length);
	}
	if(length==(len_a+len_b))
	{
		return;
	}
	if(turn == 'a')
	{
		int last_element = result[length-1],i=a_index+1;
		
		while(i<len_a && a[i]<=last_element)
			i++;
		//cout<<"a:"<<i<<" "<<len_a<<endl;
		/*if(!(i<len_a))
			return;*/
		
		for(int j=i;j<len_a;j++)
		{
			result[length]=a[j];
			generate_arrays(a,j,b,b_index,result,length+1,'b',len_a,len_b);
		}
	}	
	if(turn == 'b')
	{
		int last_element = result[length-1],i=b_index+1;
		
		while(i<len_b && b[i]<=last_element)
			i++;
		//cout<<"b:"<<b[i]<<endl;
		/*if(!(i<len_b))
			return;*/
		
		for(int j=i;j<len_b;j++)
		{
			result[length]=b[j];
			generate_arrays(a,a_index,b,j,result,length+1,'a',len_a,len_b);
		}
	}
}


void generate(int *a,int *b,int len_a,int len_b)
{
	/*int len_a=sizeof(a)/sizeof(a[0]);
	int len_b=sizeof(b)/sizeof(b[0]);*/
	//cout<<"a's length"<<sizeof(a)<<endl;
	int result[len_a+len_b];
	for(int i=0;i<len_a;i++)
	{
		result[0]=a[i];
		generate_arrays(a,i,b,-1,result,1,'b',len_a,len_b);
	}
}

int main()
{
    int A[] = {10, 15, 25};
    int B[] = {5, 20, 30};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    //cout<<"a's length"<<sizeof(A)<<endl;
    generate(A, B,n,m);
    return 0;
}

			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
