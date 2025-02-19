#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }


int knapsack(int max_weight,int *wt,int *val,int n)
{
	int dp[n+1][max_weight+1];
	for(int item=0;item<=n;item++)
	dp[item][0]=0;
	
	for(int weight=0;weight<=max_weight;weight++)
	dp[0][weight]=0;
	
	for(int item=1;item<=n;item++)
	{
		for(int weight=1;weight<=max_weight;weight++)
		{
			if(wt[item-1]<=weight)
			dp[item][weight]=max(val[item-1]+dp[item-1][weight-wt[item-1]],dp[item-1][weight]);
			else
			dp[item][weight]=dp[item-1][weight];
		}
	}
	return dp[n][max_weight];
}
	


int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(W, wt, val, n)<<endl;
    return 0;
}
