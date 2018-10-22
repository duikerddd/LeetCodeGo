#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
char chess_board[ROW][COL];
int PlayGame(int choice){
	printf("************************\n");
	printf("*  欢迎来到三子棋游戏  *\n");
	printf("*       请您选择       *\n");
	printf("*      1.开始游戏      *\n");
	printf("*      2.离开游戏      *\n");
	printf("************************\n");
	while (1){
		scanf("%d", &choice);
		if (choice == 1)
		{
			return 1;
			break;
		}
		else if (choice == 2)
		{
			return 0;
			break;
		}
		else
		{
			printf("输入非法,请重新输入!");
			continue;
		}
	}
}
int Init(char a[ROW][COL]){
	for (int row = 0; row <ROW; row++){
		for (int col = 0; col < COL; col++)
		{
			a[row][col] = '  ';
		}
	}
	return 0;
}
void Print(char a[ROW][COL]){
	printf("           \n");
	for (int i = 0; i < ROW; i++){
		printf("  %c | %c  | %c \n", a[i][0], a[i][1], a[i][2]);
		if (i != 3){
			printf("----|----|----\n");
		}
	}
}
void PlayerMove(char a[ROW][COL]){
	int row = -1;
	int col = -1;
	while (1){
		printf("请您选择落子点坐标:");
		scanf("%d %d", &row, &col);
		if (row<0 || row>2 || col<0 || col>2){
			printf("输入非法,请重新输入!");
			continue;
		}
		else if (a[row][col] == 'x' || a[row][col] == 'o')
		{
			printf("已有棋子,请重新选择坐标!");
			continue;
		}
		else
		{
			a[row][col] = 'o';
			break;
		}

	}
}
int IsFull(char a[ROW][COL]){
	int sum = 0;
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (a[row][col] != ' ')
			{

				sum++;
			}
		}
	}
	if (sum == 9){
		return 1;
	}
}
char Checkwinner(char a[ROW][COL]){
	//1.判断三子 横 竖 斜
	for (int row = 0; row < ROW; row++){
		if (a[row][0] == a[row][1] && a[row][0] == a[row][2] && a[row][0] != ' ')
		{
			return 'p';
		}
	}
	for (int col = 0; col < COL; col++){
		if (a[0][col] == a[1][col] && a[0][col] == a[2][col] && a[0][col] != ' ')
		{
			return 'p';
		}
	}
	if (a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] != ' ')
	{
		return 'p';
	}
	if (a[0][2] == a[1][1] && a[0][2] == a[2][0] && a[0][2] != ' '){
		return 'p';
	}
}




void ComputeMove(char a[ROW][COL]){
	printf("请电脑落子!\n");
	while (1){
		int col = rand() % 3;
		int row = rand() % 3;
		if (a[row][col] == ' ')
		{
			a[row][col] = 'x';
			break;
		}
		else continue;
	}
}
void Game(){
	Init(chess_board);//2.棋盘初始化
	Print(chess_board);//3.打印棋盘
	while (1){

		PlayerMove(chess_board);//4.用户落子
		Print(chess_board);
		if (Checkwinner(chess_board) == 'p')
		{
			printf("玩家获胜!\n");
			break;
		}
		if (IsFull(chess_board) == 1)//2.判断是否和棋
		{
			printf("平局!");
			break;
		}
		ComputeMove(chess_board);//6.电脑随机落子
		Print(chess_board);//3.打印棋盘
		if (Checkwinner(chess_board) == 'p')
		{
			printf("电脑获胜!\n");
			break;
		}

		if (IsFull(chess_board) == 1)//2.判断是否和棋
		{
			printf("平局!\n");
			break;
		}
	}
}


int main(){
	int choice = 0;
	if (PlayGame(choice) == 1) {   //1.选择是否开始游戏  a)开始  b)离开
		 Game();

	}
	system("pause");
}
