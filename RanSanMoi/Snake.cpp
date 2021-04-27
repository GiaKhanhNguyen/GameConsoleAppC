#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include "console.h"
enum TrangThai{UP, DOWN, RIGHT, LEFT};
#define ChieuRong 80
#define ChieuDai 30
struct ViTri
{
	int x, y;
};
struct Snake
{
	ViTri Khuc[50];
	int N;
	TrangThai TT;
};
struct Thit
{
	ViTri TD;
};
void TaoSnake(Snake &Body, Thit &Chuot);
void HienThi(Snake Body, Thit Chuot, char S[]);
void DieuKhien_DiChuyen(Snake &Body);
int Game(Snake &Body, Thit &Chuot);
int ChonLevel(int z);
void main()
{
	srand(time_t(NULL));
	Snake Body;
	Thit Chuot;
	TaoSnake(Body, Chuot);
	char S[100];
	printf("Nhap Ten Nguoi Choi: ");
	gets_s(S);
	int Diem = 0;
	int z = 0;
	int l = ChonLevel(z);
	while (1)
	{
		HienThi(Body, Chuot, S);
		DieuKhien_DiChuyen(Body);
		int G = Game(Body, Chuot);
		if (G == -1)
		{
			gotoXY(ChieuRong + 2, ChieuDai / 2);
			printf("Game Over");
			break;
		}
		else
		{
			gotoXY(ChieuRong + 2, 1);
			Diem += G;
			printf("Diem %d", Diem);
		}
		Sleep(l);
	}
	_getch();
}
void TaoSnake(Snake &Body, Thit &Chuot)
{
	Body.N = 1;
	Body.Khuc[0].x = 0;
	Body.Khuc[0].y = 0;
	Body.TT = RIGHT;
	Chuot.TD.x = 10;
	Chuot.TD.y = 10;
}
void HienThi(Snake Body, Thit Chuot, char S[])
{
	clrscr();
	gotoXY(ChieuRong + 5, 6);
	puts(S);
	for (int i = ChieuRong + 1; i < 120; i++)
	{
		gotoXY(i, 3);
		putchar(178);
	}
	for (int i = ChieuRong + 1; i < 120; i++)
	{
		gotoXY(i, 10);
		putchar(178);
	}
	for (int i = 0; i <= ChieuDai; i++)
	{
		gotoXY(ChieuRong, i);
		putchar(12);
	}
	for (int j = 0; j <= ChieuRong; j++)
	{
		gotoXY(j, ChieuDai);
		putchar(12);
	}
	gotoXY(Chuot.TD.x, Chuot.TD.y);
	putchar(31);
	gotoXY(Body.Khuc[0].x, Body.Khuc[0].y);
	putchar(2);
	for (int i = 1; i < Body.N; i++)
	{
		gotoXY(Body.Khuc[i].x, Body.Khuc[i].y);
		putchar('*');
	}
	
}
void DieuKhien_DiChuyen(Snake &Body)
{
	for (int i = Body.N; i > 0; i--)
		Body.Khuc[i] = Body.Khuc[i - 1];
	if (_kbhit())
	{
		int k = _getch();
		if (k == 'A' || k == 'a')
			Body.TT = LEFT;
		else if (k == 'D' || k == 'd')
			Body.TT = RIGHT;
		else if (k == 'W' || k == 'w')
			Body.TT = UP;
		else if (k == 'S' || k == 's')
			Body.TT = DOWN;
	}
	if (Body.TT == UP)
		Body.Khuc[0].y--;
	else if (Body.TT == DOWN)
		Body.Khuc[0].y++;
	else if (Body.TT == RIGHT)
		Body.Khuc[0].x++;
	else if (Body.TT == LEFT)
		Body.Khuc[0].x--;
}
int Game(Snake &Body, Thit &Chuot)
{
	int Diem = 0;
	if (Body.Khuc[0].x == Chuot.TD.x && Body.Khuc[0].y == Chuot.TD.y)
	{
		for (int i = Body.N; i > 0; i--)
			Body.Khuc[i] = Body.Khuc[i - 1];
		Body.N++; 
		Diem = 1;
		if (Body.TT == UP)
			Body.Khuc[0].y--;
		else if (Body.TT == DOWN)
			Body.Khuc[0].y++;
		else if (Body.TT == RIGHT)
			Body.Khuc[0].x++;
		else if (Body.TT == LEFT)
			Body.Khuc[0].x--;
		Chuot.TD.x = rand() % ChieuRong;
		Chuot.TD.y = rand() % ChieuDai;
	}
	for (int i = 1; i < Body.N; i++)
	{
		if (Body.Khuc[0].x == Body.Khuc[i].x && Body.Khuc[0].y == Body.Khuc[i].y)
			return -1;
	}
	if (Body.Khuc[0].x < 0 || Body.Khuc[0].x >= ChieuRong || Body.Khuc[0].y < 0 || Body.Khuc[0].y >= ChieuDai)
		return -1;
	else
		return Diem;
}
int ChonLevel(int z)
{
	printf("Chon Level: ");
	scanf_s("%d", &z);
	switch (z)
	{
	case 1: return 200; 
	case 2: return 180;
	case 3: return 160;
	case 4: return 140;
	case 5: return 120;
	case 6: return 100;
	case 7: return 80;
	case 8: return 60;
	case 9: return 40;
	case 10: return 30;
	}
	return 0;
}
