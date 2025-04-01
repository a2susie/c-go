#include <stdio.h>
#include "gonew.h"
// function definitions to be used in game loop
int inRange(int n){
	if ((0 < n) && (n < 20)) {return 1;}
	return 0;
}
int is_surrounded(int x,int y){
    visited[x][y] = 1;
    if (board[x+1][y] == 0 || board[x-1][y] == 0 || board[x][y+1] == 0 || board[x][y-1] == 0) { return 2; }
    else if (board[x+1][y] == board[x][y] && visited[x+1][y] != 1) { if (is_surrounded(x+1,y) == 2) {return 2;} }
    else if (board[x-1][y] == board[x][y] && visited[x-1][y] != 1) { if (is_surrounded(x-1,y) == 2) {return 2;} }
    else if (board[x][y+1] == board[x][y] && visited[x][y+1] != 1) { if (is_surrounded(x,y+1) == 2) {return 2;} }
    else if (board[x][y-1] == board[x][y] && visited[x][y-1] != 1) { if (is_surrounded(x,y-1) == 2) {return 2;} }
    return 1;
}	
int delete_chain(int x,int y){
	colour = board[x][y];
	board[x][y]=0;
	if (board[x+1][y] == colour){
		delete_chain(x+1, y);
	}
	if (board[x-1][y] == colour){
		delete_chain(x-1, y);
	}
	if (board[x][y+1] == colour){
		delete_chain(x, y+1);
	}
	if (board[x][y-1] == colour){
		delete_chain(x, y-1);
	}
	return 0;
}
int draw_board(){
	unsigned char x=0;
	unsigned char y=0;
	for (x=0; x < 20; x++)
	{
		for (y=0; y < 21; y++)
		{
			if (board[x][y] == 0 && x > 0 && y > 0 && x < 20 && y < 20)  { printf("╋━"); }
			if (x < 1 && y > 0) { 
				if (y < 11) printf("%d ",y-1); 
				if (y == 11 || y > 11) printf("%d",y-1);
			}
			if (x > 0 && y < 1) { 
				if (x < 10) printf("%d ",x); 
				if (x == 10 || x > 10) printf("%d",x);
			}
			if (board[x][y] == 1) { printf("◯━"); }
			if (board[x][y] == 2) { printf("●━"); }
		}
		printf("\n");
	}
	return 0;
}
int input_and_deletep1(){
	p1x = 0;
	p1y = 0;
	while (1){
		while (1){
			scanf("%d",&p1y);
			scanf("%d",&p1x);
			if (inRange(p1x) && inRange(p1y)) { break; }
		}
		if (board[p1x][p1y] != 1 && board[p1x][p1y] != 2 && board[p1x][p1y] != 3) break;
	}
	board[p1x][p1y] = 1;
	if (is_surrounded(p1x+1,p1y) == 1 && board[p1x+1][p1y] == 2) { delete_chain(p1x+1, p1y); }
	if (is_surrounded(p1x-1,p1y) == 1 && board[p1x-1][p1y] == 2) { delete_chain(p1x-1, p1y); }
	if (is_surrounded(p1x,p1y+1) == 1 && board[p1x][p1y+1] == 2) { delete_chain(p1x, p1y+1); }
	if (is_surrounded(p1x,p1y-1) == 1 && board[p1x][p1y-1] == 2) { delete_chain(p1x, p1y-1); }
	return 0;
}
int input_and_deletep2(){	
	p2x = 0;
	p2y = 0;
	while (1){
		while (1){
			scanf("%d",&p2y);
			scanf("%d",&p2x);
			if (inRange(p2x) && inRange(p2y)) break;
		}
		if (board[p2x][p2y] != 1 && board[p2x][p2y] != 2 && board[p2x][p2y] != 3) break;
	}	
	board[p2x][p2y] = 2;
	if (is_surrounded(p2x+1,p2y) == 1 && board[p2x+1][p2y] == 1) { delete_chain(p2x+1, p2y); }
	if (is_surrounded(p2x-1,p2y) == 1 && board[p2x-1][p2y] == 1) { delete_chain(p2x-1, p2y); }
	if (is_surrounded(p2x,p2y+1) == 1 && board[p2x][p2y+1] == 1) { delete_chain(p2x, p2y+1); }
	if (is_surrounded(p2x,p2y-1) == 1 && board[p2x][p2y-1] == 1) { delete_chain(p2x, p2y-1); }
	return 0;
}
int main(){
	int x;
	int y;
	for (y=0; y < 21; y++)
	{
		board[0][y] = 3;
		board[20][y] = 3;
	}
	for (x=0; x < 21; x++)
	{
		board[x][0] = 3;
		board[x][20] = 3;
	}
	x = 0;
	y = 0;
	printf ("Go! By a2sys");
	printf ("\n");
	printf ("Input X, Y for Player 1 & 2");
	printf ("\n");
	printf ("\n");
	while (1){
		draw_board();
		input_and_deletep1();
		for (x=1; x < 19; x++)
		{
			for (y=1; y < 19; y++)
			{
				visited[x][y] = 0;
			}
		}
		input_and_deletep2();
		for (x=1; x < 19; x++)
		{
			for (y=1; y < 19; y++)
			{
				visited[x][y] = 0;
			}
		}
	}
	return 0;
}
