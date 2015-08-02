#include<stdio.h>
int main()
{
int row,col,srow,scol,i,j,count=0,check=1,x=0,w;
char ch,dir;
scanf("%d %d %d %d %c %c %d",&row,&col,&srow,&scol,&dir,&ch,&w);
int a[row][col];
for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
		a[i][j]=(i*col)+j+1;
}
if(w==1)
{
if(ch=='S')
{
if(dir=='N' || dir=='S')//move north or south
{
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
}
if(dir=='W' || dir=='O')//move east or west
{
if(srow==1 && scol==1)
{
for(i=0;i<row;i++)//strt frm top left
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
}

if(srow==1 && scol==col)
{
for(i=0;i<row;i++)//strt frm top right
{
	if(count==1)
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
}

if(srow==row && scol==1)
{
for(i=row-1;i>=0;i--)//strt frm bottom left
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
}

if(srow==row && scol==col)
{
for(i=row-1;i>=0;i--)//strt frm bottom ryt
{
	if(count==1)
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
}
}


}



if(ch=='Z')
{
if(srow==1 && scol==1)
{
while(check<=col)//strt frm top left
{	
	if(count==0)
		i=x;
	else
		i=col-1-(x);
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
	if(check%2==0) x++;
	check++;
}
}

if(srow==1 && scol==col)
{
while(check<=col)//strt frm top right
{
		if(count==1)
		i=x;
		else
		i=col-1-(x);
	
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
	if(check%2==0) x++;
	check++;
}
}

if(srow==row && scol==1)
{
while(check<=col)//strt frm bottom left
{
		if(count==0)
		i=x;
	else
		i=col-1-(x);
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
	if(check%2==0) x++;
	check++;
}
}

if(srow==row && scol==col)
{
while(check<=col)//strt frm bottom ryt
{
		if(count==1)
		i=x;
	else
		i=col-1-x;
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
	if(check%2==0) x++;
	check++;
	
}
}
}



else//if width is 2
{
if(ch=='S')
{
if(dir=='N' || dir=='S')//move north or south
{
if(srow==1 && scol==1)
{
for(i=0;i<col;i=i+2)//strt frm top left
{
	if(count==0)
	{
		for(j=0;j<row;j++)
		{	
			
			if(i+1<col)
			printf("%d ",a[j][i+1]);
			printf("%d ",a[j][i]);
			
			
		}
	}
	else
	{
		for(j=row-1;j>=0;j--)
		{	
			printf("%d ",a[j][i]);
			if(i+1<col)
			printf("%d ",a[j][i+1]);
			
		}
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
		{	if(i+1<col)
			printf("%d ",a[j][i+1]);
			printf("%d ",a[j][i]);
			}
	}
	else
	{
		for(j=row-1;j>=0;j--)
			{printf("%d ",a[j][i]);
			if(i+1<col)
			printf("%d ",a[j][i+1]);}
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
		{		if(i+1<col)
			printf("%d ",a[j][i+1]);
			printf("%d ",a[j][i]);
			}
	}
	else
	{
		for(j=row-1;j>=0;j--)
		{	printf("%d ",a[j][i]);
			if(i+1<col)
			printf("%d ",a[j][i+1]);
			}
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
			{		if(i+1<col)
			printf("%d ",a[j][i+1]);
			printf("%d ",a[j][i]);
			}
	}
	else
	{
		for(j=row-1;j>=0;j--)
			{	printf("%d ",a[j][i]);
			if(i+1<col)
			printf("%d ",a[j][i+1]);
			}
	}
	count=1-count;
}
}
}
if(dir=='W' || dir=='O')//move east or west
{
if(srow==1 && scol==1)
{
for(i=0;i<row;i=i+2)//strt frm top left
{
	if(count==0)
	{
		for(j=0;j<col;j++)
			{	printf("%d ",a[i][j]);
			if(i+1<row)
			printf("%d ",a[i+1][j]);
			}
	}
	else
	{
		for(j=col-1;j>=0;j--)
			{		if(i+1<row)
			printf("%d ",a[i+1][j]);
			printf("%d ",a[j][i]);
			}
	}
	count=1-count;
}
}

if(srow==1 && scol==col)
{
for(i=0;i<row;i++)//strt frm top right
{
	if(count==1)
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
}

if(srow==row && scol==1)
{
for(i=row-1;i>=0;i--)//strt frm bottom left
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
}

if(srow==row && scol==col)
{
for(i=row-1;i>=0;i--)//strt frm bottom ryt
{
	if(count==1)
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
}
}


}



if(ch=='Z')
{
if(srow==1 && scol==1)
{
while(check<=col)//strt frm top left
{	
	if(count==0)
		i=x;
	else
		i=col-1-(x);
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
	if(check%2==0) x++;
	check++;
}
}

if(srow==1 && scol==col)
{
while(check<=col)//strt frm top right
{
		if(count==1)
		i=x;
		else
		i=col-1-(x);
	
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
	if(check%2==0) x++;
	check++;
}
}

if(srow==row && scol==1)
{
while(check<=col)//strt frm bottom left
{
		if(count==0)
		i=x;
	else
		i=col-1-(x);
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
	if(check%2==0) x++;
	check++;
}
}

if(srow==row && scol==col)
{
while(check<=col)//strt frm bottom ryt
{
		if(count==1)
		i=x;
	else
		i=col-1-x;
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
	if(check%2==0) x++;
	check++;
	
}
}
}

}




























return 0;
}
