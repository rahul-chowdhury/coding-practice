#include<stdio.h>
int main()
{
int row,col,i,j,count=0;
scanf("%d %d",&row,&col);
int a[row][col];
for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
		a[i][j]=(i*col)+j+1;
}
for(i=0;i<row;i++)
{
	if(count==0)
	{
		for(j=0;j<col;j++)
			printf("%d ",a[i][j]);
	}
	else
	{
		for(j=col-1;j>=0;j--)
			printf("%d ",a[i][j]);
	}
	count=1-count;
}
return 0;
}
