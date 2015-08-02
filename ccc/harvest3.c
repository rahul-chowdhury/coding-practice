#include<stdio.h>
int main()
{
int row,col,srow,scol,i,j,count=0;
scanf("%d %d %d %d",&row,&col,&srow,&scol);
int a[row][col];
for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
		a[i][j]=(i*col)+j+1;
}
if(srow==1 && scol==1)
{
for(i=0;i<col;i++)//strt frm top left
{
	if(count==0)
	{
		for(j=0;j<row;j++)
			printf("%d ",a[j][i]);
	}
	else
	{
		for(j=row-1;j>=0;j--)
			printf("%d ",a[j][i]);
	}
	count=1-count;
}
}

if(srow==1 && scol==col)
{
for(i=col-1;i>=0;i--)//strt frm top right
{
	if(count==0)
	{
		for(j=0;j<row;j++)
			printf("%d ",a[j][i]);
	}
	else
	{
		for(j=row-1;j>=0;j--)
			printf("%d ",a[j][i]);
	}
	count=1-count;
}
}

if(srow==row && scol==1)
{
for(i=0;i<col;i++)//strt frm bottom left
{
	if(count==1)
	{
		for(j=0;j<row;j++)
			printf("%d ",a[j][i]);
	}
	else
	{
		for(j=row-1;j>=0;j--)
			printf("%d ",a[j][i]);
	}
	count=1-count;
}
}

if(srow==row && scol==col)
{
for(i=col-1;i>=0;i--)//strt frm bottom ryt
{
	if(count==1)
	{
		for(j=0;j<row;j++)
			printf("%d ",a[j][i]);
	}
	else
	{
		for(j=row-1;j>=0;j--)
			printf("%d ",a[j][i]);
	}
	count=1-count;
}
}
return 0;
}
