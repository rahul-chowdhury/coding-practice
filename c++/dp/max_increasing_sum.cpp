#include<iostream>
#include<limits.h>
using namespace std;
int max(int a,int b)
{
	return (a>b)?a:b;
}
int maxsum(int *a,int n)
{
	int sum[n],global_max=INT_MIN;
	sum[0]=a[0];
	global_max=a[0];
	for(int i=1;i<n;i++)
	{
		int temp=0;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				temp=max(temp,sum[j]);
			}
		}
		sum[i] =a[i]+temp;
		global_max=max(global_max,sum[i]);
	}
	return global_max;
}

int bitonic(int *a,int n)
{
	int length[n][2],globalmax=1;
	for(int i=1;i<n;i++)
	{
		length[i][0]=length[i][1]=-1;
	}
	length[0][0]=length[0][1]=1;
	for(int i=1;i<n;i++)
	{
		int maxinc=0;
		int maxdcr=0;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			maxinc=max(maxinc,length[j][0]);
			if(a[j]>a[i])
			maxdcr=max(maxdcr,max(length[j][1],length[j][0]));
		}
		length[i][0]=maxinc+1;
		length[i][1]=maxdcr+1;
		globalmax=max(length[i][0],max(globalmax,length[i][1]));
		
	}
	return globalmax;
	
}	
	
	
	
int lis( int arr[], int n )
{
   int lis[n], i, j, max = 0;
  
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
     { 
     for ( j = 0; j < i; j++ )
     
        { cout<<arr[i]<<" "<<arr[j]+1<<endl;
        if ( (arr[i] ==(arr[j]+1)) && lis[i] <( lis[j] + 1))
           lis[i] = lis[j] + 1;
           }
           }
    
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   /* Free memory to avoid memory leak */
   
 
   return max;
}	
	
	
	
	
	
	
int main()
{
  int arr[] ={0, 8, 4, 12, 13, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<lis(arr,n)<<endl;
 
  return 0;
}
