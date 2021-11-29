#pragma once
#include"Console.h"
#include<vector>
#include<string>
#include<iomanip>
#include<io.h>
#include<fcntl.h>
#include"HamTaoVaChonChucNang.h"
void SapXep()
{
	MaximizeWindow();
	DisableCtrButton(0, 0, 1);
	ShowCur(0);

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	GotoXY(69, 5);
	TextColor(6);
	wcout << L"\1###NHẬP LỰA CHỌN CỦA BẠN###\1";
	vector<wstring> danhSachChucNang = { L"1. Theo tên.", L"2. Theo lương", L"3. Theo thời gian trễ." };

	const int x = 130, y = 3, chieuDai = 24, chieuCao = 3, mauSac1 = 6, mauSac2 = 86;

	DaChucNang(x, y, chieuDai, chieuCao, mauSac1, danhSachChucNang);

	int xTenChucNang = x, yTenChucNang = y, chiSoDanhSach = 0;
	int minYTenChucNang = yTenChucNang;
	int maxYTenChucNang = y + danhSachChucNang.size() * 2 - 2;

	ChonChucNang(xTenChucNang, yTenChucNang, chieuDai, mauSac2, danhSachChucNang[chiSoDanhSach]);

	//Bắt sự kiện phím
	while (true)
	{
		if (_kbhit())
		{
			char luaChon = _getch();

			if (luaChon == -32) //Các phím lên xuống trái phải đi theo mã -32
			{
				luaChon = _getch();
				if (luaChon == 72) //Mũi tên lên
				{
					ChonChucNang(xTenChucNang, yTenChucNang, chieuDai, mauSac1, danhSachChucNang[chiSoDanhSach]);
					yTenChucNang -= 2;
					chiSoDanhSach--;
					if (yTenChucNang < minYTenChucNang)
					{
						yTenChucNang = maxYTenChucNang;
						chiSoDanhSach = danhSachChucNang.size() - 1;
					}
					ChonChucNang(xTenChucNang, yTenChucNang, chieuDai, mauSac2, danhSachChucNang[chiSoDanhSach]);
				}
				if (luaChon == 80) //Mũi tên xuống
				{
					ChonChucNang(xTenChucNang, yTenChucNang, chieuDai, mauSac1, danhSachChucNang[chiSoDanhSach]);
					yTenChucNang += 2;
					chiSoDanhSach++;
					if (yTenChucNang > maxYTenChucNang)
					{
						yTenChucNang = minYTenChucNang;
						chiSoDanhSach = 0;
					}
					ChonChucNang(xTenChucNang, yTenChucNang, chieuDai, mauSac2, danhSachChucNang[chiSoDanhSach]);
				}
			}
			if (luaChon == 27) //Phím esc, đang ở menu0 thì thoát
			{
				exit(0);
			}
			if (luaChon == 13) //Phím enter
			{
				int ketQuaLuaChon = (yTenChucNang - y + 2) / 2;

				if (ketQuaLuaChon == 1) //Đã có danh sách
				{

				}
				else  //Tạo danh sách mới
				{

				}
			}
		}
	}
}
