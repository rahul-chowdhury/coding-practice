#include<iostream>
#include <vector>

using namespace std;
bool finished=false;
void process_solution(vector<int> &a,int k,int n);
bool is_a_solution(vector<int> &a,int k,int n);
void generate_candidate_list(vector<int> &a,int k,int input,int n,vector<int> &candidate_list,int *number_of_candidates);

void backtrack(vector<int> &a,int k,int input,int n)
{
	if(is_a_solution(a,k,n))
	{
		process_solution(a,k,n);
	}
	else
	{
		vector<int>candidate_list;
		candidate_list.resize(n);
		int number_of_candidates;
		generate_candidate_list(a,k,input,n,candidate_list,&number_of_candidates);
		k++;
		
		for(int i=0;i<number_of_candidates;i++)
		{	
			
			a[k]=candidate_list[i];
			//make_move(a,k,n);
			backtrack(a,k,input,n);
			//unmake_move(a,k,n);
			if(finished==true)
			{
				return;
			}
		}
	}
}

void process_solution(vector<int> &a,int k,int n)
{
	//cout<<"{ ";
	for(int i=0;i<=k;i++)
	{
		cout<<a[i]<<" ";
		
	}
	cout<<endl;
}

bool is_a_solution(vector<int> &a,int k,int n)
{
	if(k==n-1)
	{
		return true;
	}
	return false;

}

void generate_candidate_list(vector<int> &a,int k,int input,int n,vector<int> &candidate_list,int *number_of_candidates)		
{
	*number_of_candidates=0;
	//cout<<"heere"<<endl;
	for(int i=0;i<n;i++)
	{
		int x=input%10;
		bool check=true;
		for(int j=0;j<=k;j++)
		{
			if(x==a[j])
			{
				check=false;
				break;
			}
		}
	//	cout<<"heere1"<<endl;
		if(check==true)
			candidate_list[(*number_of_candidates)++]=x;
		
		input=input/10;
	}

}

int main()
{

	int n=0,input,temp;
	vector<int>a;
	cout<<"enter number : ";
	cin>>input;
	temp=input;
	if(temp==0)
		n=1;
	while(temp!=0)
	{
		temp /=10;
		n++;
	}		
	a.resize(n);
	a.assign(n,-1);
	backtrack(a,-1,input,n);
	return 0;
}
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
