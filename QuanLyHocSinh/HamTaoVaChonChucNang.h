#pragma once
#include"Console.h"
#include<vector>
#include<string>
#include<iomanip>
#include<io.h>
#include<fcntl.h>

//Chức năng đơn lẻ
void ChucNang(int x, int y, int chieuDai, int chieuCao, int mauSac, wstring tenChucNang)
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	TextColor(mauSac);
	GotoXY(x + ((chieuDai - tenChucNang.length())/2), y + 1);
	wcout << tenChucNang;

	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);

	//Màu khung
	TextColor(11);

	for (int iStartX = x; iStartX <= x + chieuDai - 1; iStartX++)
	{
		GotoXY(iStartX, y);
		cout << char(196);
		GotoXY(iStartX, y + chieuCao - 1);
		cout << char(196);
	}

	for (int iStartY = y; iStartY <= y + chieuCao - 1; iStartY++)
	{
		GotoXY(x, iStartY);
		cout << char(179);
		GotoXY(x + chieuDai - 1, iStartY);
		cout << char(179);
	}

	GotoXY(x, y); 
	cout << char(218);
	GotoXY(x + chieuDai - 1, y); 
	cout << char(191);
	GotoXY(x, y + chieuCao - 1); 
	cout << char(192);
	GotoXY(x + chieuDai -1, y + chieuCao - 1); 
	cout << char(217);
}

//Nhiều chức năng dính liền theo chiều dọc
void DaChucNang(int x, int y, int chieuDai, int chieuCao, int mauSac, vector<wstring> danhSachChucNang)
{
	for (size_t i = 0; i < danhSachChucNang.size(); i++)
	{
		ChucNang(x, y + i * 2, chieuDai, chieuCao, mauSac, danhSachChucNang[i]);
		if (i != 0)
		{
			GotoXY(x, y + (i * 2)); 
			cout << char(195);
			GotoXY(x + chieuDai - 1, y + (i * 2)); 
			cout << char(180);
		}
	}
}

//Chọn chức năng
void ChonChucNang(int x, int y, int chieuDai, int mauSac, wstring tenChucNang)
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	TextColor(mauSac);
	GotoXY(x + ((chieuDai - tenChucNang.length()) / 2), y + 1);
	wcout << tenChucNang;

	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);
}