#include<iostream>
#include <vector>

using namespace std;
bool finished=false;
void process_solution(vector<bool> &a,int k,int n);
bool is_a_solution(vector<bool> &a,int k,int n);
void generate_candidate_list(vector<bool> &a,int k,int n,vector<bool> &candidate_list,int *number_of_candidates);

void backtrack(vector<bool> &a,int k,int n)
{
	if(is_a_solution(a,k,n))
	{
		process_solution(a,k,n);
	}
	else
	{
		vector<bool>candidate_list;
		candidate_list.resize(2);
		int number_of_candidates;
		generate_candidate_list(a,k,n,candidate_list,&number_of_candidates);
		k++;
		
		for(int i=0;i<number_of_candidates;i++)
		{	
			
			a[k]=candidate_list[i];
			//make_move(a,k,n);
			backtrack(a,k,n);
			//unmake_move(a,k,n);
			if(finished==true)
			{
				return;
			}
		}
	}
}

void process_solution(vector<bool> &a,int k,int n)
{
	cout<<"{ ";
	for(int i=0;i<=k;i++)
	{
		if(a[i]==true)
		{
			cout<<i+1<<" ";
		}
	}
	cout<<"}"<<endl;
	
}

bool is_a_solution(vector<bool> &a,int k,int n)
{
	if(k==n-1)
	{
		return true;
	}
	return false;

}

void generate_candidate_list(vector<bool> &a,int k,int n,vector<bool> &candidate_list,int *number_of_candidates)		
{
	*number_of_candidates=2;
	candidate_list[0]=false;
	candidate_list[1]=true;
	
}

int main()
{

	int n;
	vector<bool>a;
	cout<<"enter n : ";
	cin>>n;
	a.resize(n);
	a.assign(n,false);
	backtrack(a,-1,n);
	return 0;
}
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
