#pragma once
#pragma warning( disable : 6031)
#include<vector>
#include"Console.h"
#include"HamTaoVaChonChucNang.h"
#include"DocFileCSV.h"
#include"Menu0.h"
#include"KhungDanhSach.h"
#include"SapXep.h"
//Trả về số của chức năng
int Menu1(wstring duongDan, int soLuongBanGhi)
{	
	MaximizeWindow();
	DisableCtrButton(0, 0, 1);
	ShowCur(0);

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	GotoXY(59, 5);
	TextColor(6);
	wcout << L"\1===================MAIN MENU===================\1";
	vector<wstring> danhSachChucNang = { L"1. Xem danh sách.", L"2. Thêm nhân viên", L"3. Xóa nhân viên", L"4. Sắp xếp", L"5. Tìm kiếm.", L"6. Sửa."};
	
	const int x = 64, y = 15, chieuDai = 40, chieuCao = 3, mauSac1 = 6, mauSac2 = 86;

	DaChucNang(x, y, chieuDai, chieuCao, mauSac1, danhSachChucNang);

	int xTenChucNang = x, yTenChucNang = y, chiSoDanhSach = 0;
	int minYTenChucNang = yTenChucNang;
	int maxYTenChucNang = y + danhSachChucNang.size() * 2 - 2;

	ChonChucNang(xTenChucNang, yTenChucNang, chieuDai, mauSac2, danhSachChucNang[chiSoDanhSach]);

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
			if (luaChon == 27) //Phím esc, đang ở menu1 thì load menu0
			{
				TextColor(6);
				wcout << L" ";
				system("cls");
				Menu0();
			}
			if (luaChon == 13) //Phím enter
			{
				int ketQuaLuaChon = (yTenChucNang - y + 2) / 2;

				if (ketQuaLuaChon == 1)
				{
					TextColor(6);
					wcout << L" ";
					system("cls");
					InDanhSach(duongDan ,soLuongBanGhi);
					break;
				}
				else if(ketQuaLuaChon == 2)
				{
					TextColor(6);
					wcout << L" ";
					system("cls");
					SapXep();
				}
			}
		}
	}

	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);

	return 0;
}
