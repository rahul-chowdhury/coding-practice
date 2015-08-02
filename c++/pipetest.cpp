#include<iostream>
#include<unistd.h>
#include<string>

using namespace std;

int main()
{

int read,write,pipefd[2],k;
pipe(pipefd);
read=pipefd[0];
write=pipefd[1];
int pid=fork();
if(pid<0)
{
	cout<<"error"<<endl;
}
else if(pid==0)
{
	cout<<"child"<<endl;
	dup2(write,1);
	string word;
	while(word!="stop")
	{cout<<"child"<<endl;
		cin>>word;
		cout<<word;
		sleep(1);
	}
}
else
{
	dup2(read,0);
	string word;
	cout<<"parent"<<endl;
	while(word!="stop")
	{cout<<"parent"<<endl;
		cin>>word;
		cout<<word;
		sleep(1);
	}
}
return 0;
}
	
	
	
	
	
