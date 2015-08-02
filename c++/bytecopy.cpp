#include<iostream>
#include <sys/types.h> 
#include <sys/stat.h> 
using namespace std;
#include <unistd.h>
 #include <fcntl.h>
 #include<stdio.h>
 

int main()
{
	int fd=open("test",O_RDONLY),fd1=open("test1",O_RDWR | O_CREAT);
	char buf[1000000];
	int count=10000;
	read( fd, buf,count);
	 write(fd1,buf,count); 
	 FILE *f=fopen("test.jpg","r"),*f1=fopen("test1.jpg","w");
	 fread(buf,1,1000000,f);
	 fwrite(buf,1,1000000,f1);
	return 0;
}
