#include<iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

bool is_safe(int board[9][9],int choice,int row,int column)
{
	//check row
	for(int j=0;j<9;j++)
	{
		if(choice==board[row][j])
			return false;
	}
	for(int i=0;i<9;i++)
	{
		if(choice==board[i][column])
			return false;
	}
	if(board[row-1][column-1]==choice)
		return false;
	if(board[row+1][column+1]==choice)
		return false;
	if(board[row-1][column+1]==choice)
		return false;
	if(board[row+1][column-1]==choice)
		return false;
	return true;
}

void generate_sudoku_board(int board[9][9],int filled)
{
	int x=0,i,j,temp;
	bool safe;
	srand(time(NULL));
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			board[i][j]=-1;
		}
	}
	while(x!=filled)
	{
		safe=false;
		i=rand()%9;
		j=rand()%9;
		while(safe==false)
		{
			temp=rand()%9+1;
			safe=is_safe(board,temp,i,j);
		}
		board[i][j]=temp;
		x++;
		
	}
}

void print_board(int board[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(board[i][j]==-1)cout<<" |  ";
			else cout<<" |"<<board[i][j]<<" ";
		}
		cout<<"\n-----------------------------------";
		cout<<endl;
	}
}
int main()
{
int board[9][9];
generate_sudoku_board(board,15);
print_board(board);
return 0;
}

