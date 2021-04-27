#include<stdio.h>
#include<Windows.h>
#include "console.h"	
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
struct ViTri
{
	int y, x;
};
struct HinhDang
{
	char A[3][3];
};
struct XeDua
{
	ViTri VT;
	HinhDang HD;
};
struct KeThu
{
	ViTri VT;
	HinhDang HD;
};
#define ChieuDai 40
#define ChieuRong 120
#define DuongDua 25
void TaoHinh(XeDua &Car, KeThu &KT);
void HienThi(XeDua Car, KeThu KT, char S[]);
void DieuKhien_DiChuyen(XeDua &Car);
int Game(XeDua &Car, KeThu &KT, int &Diem);
int ChonLevel(int z);
void main()
{
	srand(time_t(NULL));
	int Diem = 0;
	char S[100];
	printf("Nhap Ten Nguoi Choi: ");
	gets_s(S);
	int z = 0;
	int l = ChonLevel(z);
	XeDua Car;
	KeThu KT;
	TaoHinh(Car, KT);
	int k;
	while (1)
	{
		HienThi(Car, KT, S);
		DieuKhien_DiChuyen(Car);
		k = Game(Car, KT, Diem);
		if (k == -1)
		{
			gotoXY(ChieuDai /2, ChieuRong / 6);
			printf("Game Over");
			break;
		}
		else
		{
			gotoXY(ChieuDai + 2, 1);
			printf("Diem %d", Diem);
		}
		Sleep(l);
	}

}
void TaoHinh(XeDua &Car, KeThu &KT)
{
	Car.VT.y = ChieuDai - 2;
	Car.VT.x = DuongDua / 2;
	Car.HD.A[0][0] = Car.HD.A[0][2] = Car.HD.A[2][2] = Car.HD.A[2][0] = '0';
	Car.HD.A[1][0] = Car.HD.A[1][2] = '|';
	Car.HD.A[0][1] = '*';
	Car.HD.A[2][1] = '_';
	Car.HD.A[1][1] = 'x';
	KT.VT.x = 2 + rand() % (DuongDua - 4);
	KT.VT.y = -2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			KT.HD.A[i][j] = 124;
	}
	
	
}
void HienThi(XeDua Car, KeThu KT, char S[])
{
	clrscr();
	gotoXY(ChieuDai + 5, 6);
	puts(S);
	for (int i = DuongDua + 1; i < 80; i++)
	{
		gotoXY(i, 3);
		putchar(178);
	}
	for (int i = DuongDua + 1; i < 80; i++)
	{
		gotoXY(i, 10);
		putchar(178);
	}
	for (int i = 0; i < ChieuDai; i++)
	{
		gotoXY(DuongDua, i);
		putchar(12);
	}
	for (int i = 0; i < ChieuDai; i++)
	{
		gotoXY(0, i);
		putchar(12);
	}
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int x = j + Car.VT.x;
			
			int y = i + Car.VT.y;
			
			gotoXY(x, y);
			putchar(Car.HD.A[i + 1][j + 1]);
		}
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int x = j + KT.VT.x;

			int y = i + KT.VT.y;
			if (y >= 0 && y < ChieuDai)
			{
				gotoXY(x, y);
				putchar(KT.HD.A[i + 1][j + 1]);
			}
		}
	}
	
}
void DieuKhien_DiChuyen(XeDua &Car)
{
	if (_kbhit())
	{
		int k = _getch();
		if (k == 'A' || k == 'a')
			Car.VT.x--;
		else if (k == 'D' || k == 'd')
			Car.VT.x++;
	}
}
int Game(XeDua &Car, KeThu &KT, int &Diem)
{
	KT.VT.y++;
	if (KT.VT.y > ChieuDai)
	{
		KT.VT.x = 2 + rand() % (DuongDua - 4);
		KT.VT.y = -2;
		Diem++;
	}
	int X = abs(Car.VT.x - KT.VT.x);
	int Y = abs(Car.VT.y - KT.VT.y);
	if (X < 3 && Y < 3)
		return -1;
	else
		return Diem;
}
int ChonLevel(int z)
{
	printf("Chon Level (1 -> 10): ");
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
