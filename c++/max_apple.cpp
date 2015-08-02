#include<iostream>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;
int apple[50][50],total[50][50],m,n,apple_left[50][50];
string path[50][50];
//int startx,starty,endx,endy,clock1;
void traverse(int x,int y)
{
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			cout<<total[i][j]<<"\t";
		}
		cout<<"\t\t";
		for(int j=0;j<n;j++)
		{
			
			cout<<apple[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;*/
	//clock1++;
	char temp[10];
	if(x==m-1 && y==n-1)
		return;
		
	
	if(x+1<m && total[x+1][y]>=total[x][y]+apple_left[x+1][y])
		{apple_left[x+1][y] +=apple[x+1][y];}
	else if(x+1<m )
	{
		if(apple_left[x+1][y]!=apple[x+1][y])
		apple_left[x+1][y] =apple[x+1][y];
		total[x+1][y]=total[x][y]+apple_left[x+1][y];
		apple_left[x+1][y] -=apple[x+1][y];
		path[x+1][y]=path[x][y];
		path[x+1][y].append("-->");
		sprintf(temp,"%d",x+1);
		path[x+1][y].append(temp);
		path[x+1][y].append(",");
		sprintf(temp,"%d",y);
		path[x+1][y].append(temp);
		
		traverse(x+1,y);
	}
	if(y+1<n && total[x][y+1]>=total[x][y]+apple_left[x][y+1])
		{apple_left[x][y+1] +=apple[x][y+1];}
	else if(y+1<n )
	{
		if(apple_left[x][y+1]!=apple[x][y+1])
		apple_left[x][y+1] =apple[x][y+1];
		total[x][y+1]=total[x][y]+apple_left[x][y+1];
		apple_left[x][y+1] -=apple[x][y+1];
		path[x][y+1]=path[x][y];
		path[x][y+1].append("-->");
		sprintf(temp,"%d",x);
		path[x][y+1].append(temp);
		path[x][y+1].append(",");
		sprintf(temp,"%d",y+1);
		path[x][y+1].append(temp);
		traverse(x,y+1);
	}
	/*if(y-1>=0 && total[x][y-1]>=total[x][y]+apple[x][y-1])
		{}
	else if(y-1>=0 && (x!=startx || y-1!=starty))
	{
		total[x][y-1]=total[x][y]+apple[x][y-1];
		path[x][y-1]=path[x][y];
		path[x][y-1].append("-->");
		sprintf(temp,"%d",x);
		path[x][y-1].append(temp);
		path[x][y-1].append(",");
		sprintf(temp,"%d",y-1);
		path[x][y-1].append(temp);
		
		traverse(x,y-1);
	}
	if(x-1>=0 && total[x-1][y]>=total[x][y]+apple[x-1][y])
		{}
	else if(x-1>=0 && (x-1!=startx || y!=starty))
	{
		total[x-1][y]=total[x][y]+apple[x-1][y];
		path[x-1][y]=path[x][y];
		path[x-1][y].append("-->");
		sprintf(temp,"%d",x-1);
		path[x-1][y].append(temp);
		path[x-1][y].append(",");
		sprintf(temp,"%d",y);
		path[x-1][y].append(temp);
		
		traverse(x-1,y);
	}*/
}
int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
int main()
{
	int all_total;
	
	srand(time(NULL));
	char temp[10];
	cout<<"enter the number of rows :";
	cin>>m;
	cout<<"enter the number of columns :";
	cin>>n;
	cout<<"enter no. of apples:"<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			total[i][j]=-1;
			apple[i][j]=rand()%100;
			apple_left[i][j]=apple[i][j];
			
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			cout<<apple_left[i][j]<<"\t";
		}
		cout<<endl;
	}
	/*cout<<"enter start vertex :\nenter x:";
	cin>>startx;
	cout<<"enter y:";
	cin>>starty;
	cout<<"enter end vertex :\nenter x:";
	cin>>endx;
	cout<<"enter y:";
	cin>>endy;
	total[startx][starty]=apple[startx][starty];
	path[startx][starty]="";
	sprintf(temp,"%d",startx);
	path[startx][starty].append(temp);
	path[startx][starty].append(",");
	sprintf(temp,"%d",starty);
	path[startx][starty].append(temp);*/
	total[0][0]=apple[0][0];
	apple[0][0]=apple_left[0][0]=0;
	traverse(0,0);
	
	all_total=total[m-1][n-1];
	cout<<"path : "<<path[m-1][n-1]<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			apple[i][j]=apple_left[i][j];
			
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			cout<<apple_left[i][j]<<"\t";
		}
		cout<<endl;
	}
	traverse(0,0);
	 all_total +=total[m-1][n-1];
	 cout<<"path : "<<path[m-1][n-1]<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			apple[i][j]=apple_left[i][j];
			
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			cout<<apple_left[i][j]<<"\t";
		}
		cout<<endl;
	}
	traverse(0,0);
	 all_total +=total[m-1][n-1];
	 cout<<"path : "<<path[m-1][n-1]<<endl;
	
	cout<<"max no of apples recusion="<<all_total<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			cout<<apple_left[i][j]<<"\t";
		}
		cout<<endl;
	}
		
		/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			total[i][j]=-1;
			
			
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>0 && j>0)
			{
				total[i][j]=apple[i][j]+max(total[i-1][j],total[i][j-1]);
				if(total[i-1][j]>total[i][j-1])
				{
					path[i][j]=path[i-1][j];
					path[i][j].append("-->");
					sprintf(temp,"%d",i);
					path[i][j].append(temp);
					path[i][j].append(",");
					sprintf(temp,"%d",j);
					path[i][j].append(temp);
				}
				else
				{
					path[i][j]=path[i][j-1];
					path[i][j].append("-->");
					sprintf(temp,"%d",i);
					path[i][j].append(temp);
					path[i][j].append(",");
					sprintf(temp,"%d",j-1);
					path[i][j].append(temp);
				}
			}
				
				
			else if (i>0)
			{
			total[i][j]=apple[i][j]+total[i-1][j];
			path[i][j]=path[i-1][j];
			path[i][j].append("-->");
			sprintf(temp,"%d",i);
			path[i][j].append(temp);
			path[i][j].append(",");
			sprintf(temp,"%d",j);
			path[i][j].append(temp);
			}
			else if (j>0)
			{
			total[i][j]=apple[i][j]+total[i][j-1];
			path[i][j]=path[i][j-1];
			path[i][j].append("-->");
			sprintf(temp,"%d",i);
			path[i][j].append(temp);
			path[i][j].append(",");
			sprintf(temp,"%d",j-1);
			path[i][j].append(temp);
			}
			
			else
			total[i][j]=apple[i][j];
			/*cout<<"total array i="<<i<<"j="<<j<<endl;
			for(int x=0;x<m;x++)
	{
		for(int y=0;y<n;y++)
		{
			
			cout<<total[x][y]<<"\t";
		}
		cout<<"\t\t";
		for(int y=0;y<n;y++)
		{
			
			cout<<apple[x][y]<<"\t";
		}
		cout<<endl;
	}*//*
		}
	}
	cout<<"max no of apples ="<<total[m-1][n-1]<<endl;	
	cout<<"path : "<<path[m-1][n-1]<<endl;*/
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
