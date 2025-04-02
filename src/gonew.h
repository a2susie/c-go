#ifndef GO_NAME
#define GO_NAME
//misc.
int board[21][21];
int visited[19][19];
int colour;
int p1x;
int p1y;
int p2x;
int p2y;
//declarations
int draw_board();
int inRange(int);
int input_and_deletep1();
int input_and_deletep2();
int delete_chain(int,int);
int is_surrounded(int,int);
//end
#endif
