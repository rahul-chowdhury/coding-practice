#include<stdio.h>

int cutRod(int *a,int size)
{
	int dp[size];
	dp[0]=a[0];
	for(int i=1;i<=size;i++)
	{
		int temp=0;
		for(int j=0;j<i;j++)
		{
			if(temp<dp[i-j-1]+a[j])
			temp=dp[i-j-1]+a[j];
		}
		dp[i]=temp;
	}
	return dp[size-1];
}













int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    getchar();
    return 0;
}
