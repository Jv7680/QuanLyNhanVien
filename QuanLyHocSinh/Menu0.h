#pragma once
#pragma warning( disable : 6031)
#include<vector>
#include"Console.h"
#include"HamTaoVaChonChucNang.h"
#include"Menu1.h"

//Menu mở đầu
void Menu0()
{
	MaximizeWindow();
	DisableCtrButton(0, 0, 1);
	ShowCur(0);

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	GotoXY(69, 5);
	TextColor(6);
	wcout << L"\1###NHẬP LỰA CHỌN CỦA BẠN###\1";
	vector<wstring> danhSachChucNang = { L"1. Đã có danh sách.", L"2. Tạo danh sách mới"};

	const int x = 64, y = 15, chieuDai = 40, chieuCao = 3, mauSac1 = 6, mauSac2 = 86;

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
				if (ketQuaLuaChon == 1)
				{
					TextColor(6);					
					wcout << L" "; 
					system("cls");
					wstring duongDan;
					wstring nhapDuongDan = L"##Hãy nhập đường dẫn nơi chứa tệp danh sách cần mở(Ví dụ: C:\\danhsach.csv)##";
					int soLuongBanGhi;
					ChucNang(24, 15, 120, 5, mauSac1, nhapDuongDan);

					_setmode(_fileno(stdin), _O_U16TEXT);
					_setmode(_fileno(stdout), _O_U16TEXT);

					GotoXY(27, 18);
					ShowCur(1);
					TextColor(6);
					getline(wcin, duongDan); //màu nhập đường dẫn
					ShowCur(0);
					system("cls"); 
					_setmode(_fileno(stdin), _O_TEXT);
					_setmode(_fileno(stdout), _O_TEXT);

					//kiểm tra file có mở đc ko rồi ms load vào menu1
					DocFileCSV(duongDan, 1, soLuongBanGhi);
					//Mở được thì load menu1
					Menu1(duongDan, soLuongBanGhi);
					break;
				}
				else
				{
					//chưa xử lý
				}
			}
		}
	}
}
