#include <sys/types.h>
#include <unistd.h>
#include<iostream>
using namespace std;
int main()
{
	cout<<getpid()<<endl;
	cout<<getppid()<<endl;
	//cout<<fork()<<endl;
	fork();
	
	return 0;
}
