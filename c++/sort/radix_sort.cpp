#include <bits/stdc++.h>
using namespace std;

int * counting_sort(int *a,int low,int high,int k,int *original,int *sorted)//n=no. of elements in the array ; k=max possible no. of values in the array
{
	int c[k];
	
	for(int i=0;i<k;i++)
		c[i]=0;

	for(int i=low;i<=high;i++)
		c[a[i]]++;
		
	for(int i=1;i<k;i++)
		c[i]=c[i]+c[i-1];
		
	for(int i=high;i>=low;i--)//to make this stable sort
	{
		//b[c[a[i]]-1]=a[i];
		sorted[low+c[a[i]]-1]=original[i];
		c[a[i]]--;
	}
	
	
}


int * radix_sort(int *a,int n,int b,int d)//n=no. of elements in the array ; b=base of the numbers; d=max no. of digits
{
	int next_positive=0,next_negative=n-1;
	while(next_positive<next_negative)
	{
		while(next_positive<n && a[next_positive]<0)
			next_positive++;
		while(next_negative>=0 && a[next_negative]>=0)
			next_negative--;
		if(next_positive<next_negative)
		{
			int temp=a[next_positive];
			a[next_positive]=a[next_negative];
			a[next_negative]=temp;
		}
		else
			break;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	cout<<"next_negative:"<<next_negative<<endl;
	//sort the negative numbers in descending order
	if(next_negative>0)
	{
		for(int digit=1;digit<=d;digit++)
		{
			int digit_array[next_negative+1],new_a[next_negative+1];
			
			for(int i=0;i<=next_negative;i++)
			{
				digit_array[i]=abs((a[i]%(int)(pow(10,digit)))/(int)(pow(10,digit-1)));
			}
			for(int i=0;i<=next_negative;i++)
	{
		cout<<digit_array[i]<<" ";
	}
	
	cout<<endl;			
			counting_sort(digit_array,0,next_negative,b,a,new_a);
			for(int i=0;i<=next_negative;i++)
			{
				a[i]=new_a[i];
			}
			
		}
		for(int i=0;i<n;i++)
		{
		cout<<a[i]<<" ";
		}
	
	cout<<endl;
		for(int i=0;i<=next_negative/2;i++)//sorting the negative numbers in ascending order
		{
			int temp=a[i];
			a[i]=a[next_negative-i];
			a[next_negative-i]=temp;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	
	for(int digit=1;digit<=d;digit++)//sorting the positive numbers
	{
		int digit_array[n-next_negative-1],new_a[n-next_negative-1];
			
		for(int i=next_negative+1;i<n;i++)
		{
			digit_array[i]=(a[i]%(int)(pow(10,digit)))/(int)(pow(10,digit-1));
		}			
		counting_sort(digit_array,next_negative+1,n-1,b,a,new_a);
		for(int i=next_negative+1;i<n;i++)
		{
			a[i]=new_a[i];
		}
		
	}
	
}

int main()
{
	clock_t t1=clock();
	int a[]={2,4,56,77,8,99,0,12};
	int n=sizeof(a)/sizeof(int);
	int b[n],d,max_d,temp;
	for(int i=0;i<n;i++)
	{
		d=1;
		temp=a[i];
		temp=temp/10;
		while(temp!=0)
		{
			d++;
			temp=temp/10;
		}
		if(d>max_d)
			max_d=d;
	}
	radix_sort(a,n,10,max_d);
	cout<<clock()-t1<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}
