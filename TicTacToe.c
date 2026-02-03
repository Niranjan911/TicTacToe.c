#include<stdio.h>

void printboard(char board[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c ",board[i][j]);
			if(j<2) printf("|");
		}
	   if(i<2) printf("\n---+---+---\n");
	}
	
	
}

int wincheck(char board[3][3])
{
	int i;
	//Rows
	for(i=0;i<3;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		return 1;
	}	
	
	//Columns
	for(i=0;i<3;i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		return 1;
	}	
	
	//Diagonals
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	return 1;
	
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	return 1;
	
	return 0;

}


int main()
{
char board[3][3] ={
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '}
	
	};
int row,col,pos,moves = 0;
char player = 'X';
while(1)
{
printboard(board);
printf("\n");
printf("Player %c Enter Your Position (1-9):\n",player);
scanf("%d",&pos);
row = (pos-1)/3;
col = (pos-1)%3;
	
if(board[row][col] == ' ')
{
	board[row][col] = player;
	moves++;
	
}
else
{
    printf("Invalid Move! Try Again.\n");
    continue;
}
	
if(wincheck(board))
{
	printboard(board);
	printf("\n");
	printf("The player %c has won the MATCH!\n",player);
    
	break;
}
	
if(moves == 9)
{
	printboard(board);
	printf("The match is a DRAW!\n");
	break;
}
	
if(player == 'X')
{
	player = 'O';
}
else
{
    player = 'X';
}
	
	
}
	
	
	return 0;
	
	
   }
