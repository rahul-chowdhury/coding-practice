#include<iostream>
#include <string.h>
#include <string>
using namespace std;
 

const char hash[10][5] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
 
void  print(int number[], int curr_digit, char output[], int n);
 
void print_words(int number[], int n)
{
    char output[n+1];
    output[n] ='\0';
    print(number, n, output,0 );
}


void  print(int number[],int n , char output[],int digit )
{
   
    
    if (digit == n)
    {
        cout<<output<<" ";
        return ;
    }
 
    for (int i=0; i<strlen(hash[number[digit]]); i++)
    {
        output[digit] = hash[number[digit]][i];
        print(number,  n, output,digit+1);
        if (number[digit]==0 || number[digit]==1)
            return;
    }
}

int main()
{
	string s;
	cout<<"enter input number:"<<endl;
	cin>>s;
	int n=s.length();
	int num[s.length()];
	for(int i=0;i<s.length();i++)
	num[i]=(int)s[i]-48;
	print_words(num, n);
	cout<<endl;
	return 0;
}
