//rotation 90 degree clockwise

#include<stdio.h>
#include<string.h>
int main()
{
	int matrix[4][4];
	int i,j,layer,offset,temp,n=4,x=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			matrix[i][j]=x++;
		}
	}
	for(layer=0;layer<=n/2;layer++)
	{
		for(offset=layer;offset<=(n-2-layer);offset++)
		{
			temp=matrix[layer][offset];
			matrix[layer][offset]=matrix[n-1-offset][layer];
			matrix[n-1-offset][layer]=matrix[n-1-layer][n-1-offset];
			matrix[n-1-layer][n-1-offset]=matrix[offset][n-1-layer];
			matrix[offset][n-1-layer]=temp;
		}
	}
	printf("matrix\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	
	
	
	
	
