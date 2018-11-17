#include <stdio.h>
#include <windows.h>

#define N 25
#define Road 1
#define Wall 0

int map[N][N];

void gotoxy(int x, int y) //�ƶ�����
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidden()//���ع��
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;//��1Ϊ��ʾ����0Ϊ����
	SetConsoleCursorInfo(hOut, &cci);
}

void paint()
{
	int i, j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(map[i][j]==Wall) 
				printf("�~");
			else 
				printf("  ");
			if (j == N-1) printf("\n");
		}
	
}

void main()
{
	int i, j;
	hidden();
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i % 2 == 0 || j % 2 == 0) map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	paint();
	gotoxy(0, 24);
}