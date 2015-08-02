#include<bits/stdc++.h>
#include<heap_sort.cpp>

int winner_of_the_vote(int votes[],int n)
{
	heap_sort(votes,n);
	int max_votes=0,winner=a[0],candidate,i=0;
	while(i<n)
	{
		
		candidate=a[i];
		while(a[i]==candidate)
		{
			i++;
		}
		if(i>max_votes)
		{
			max_votes=i;
			winner=candidate;
		}
	}
	return winner;
}

int main()
{
	int a[]={1,4,5,5,6,1,12,5,6,1,6,1,6,1};
	int n=sizeof(a)/sizeof(int);
	cout<<winner_of_the_vote(a,n)<<endl;
}
