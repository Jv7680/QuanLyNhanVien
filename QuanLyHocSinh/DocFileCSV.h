#pragma once
#pragma warning( disable : 6031)
#include<iostream>
#include<fstream>
#include<string>
#include <locale>
#include <codecvt>
#include"Menu0.h"

using namespace std;
void Menu0();

//Đọc và hiển thị dữ liệu trong file CSV vào chương trình
void DocFileCSV(string duongDan, int check, int& soLuongBanGhi, int x = 0, int y = 0, vector<wstring> danhSachCot = {})
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	locale loc(std::locale(), new std::codecvt_utf8<wchar_t>); //định dạnh file utf 8 with bom

	wifstream fileCSV(duongDan, std::ios::in);

	if (check == 1) //nếu check bật thì chỉ kiểm tra file đọc được ko
	{
		if (!fileCSV)
		{
			ChucNang(44, 15, 80, 3, 4, L"##ERROR: Mở tệp thất bại!! Xin kiểm tra lại đường dẫn hoặc định dạnh tệp.");

			//Bắt esc để quay lại menu0
			char luaChon;
			while (true)
			{
				if (_kbhit())
				{
					luaChon = _getch();
					if (luaChon == 27) //esc
					{
						system("cls");
						Menu0();
					}
				}
			}
		}
		else //Nếu không xuất hiện lỗi thì tiến hành đếm số lượng bản ghi
		{
			//Sử dụng loc ở trên
			fileCSV.imbue(loc);
			wstring line;
			//Đếm số lượng bản ghi, đặt bằng -1 để bỏ qua dòng đầu là tên các thuộc tính chứ ko phải bản ghi
			soLuongBanGhi = -1;
			while (getline(fileCSV, line))
			{
				soLuongBanGhi++;
			}
		}
	}
	else //Trường hợp không bật check lỗi thì tiến hành đếm số bản ghi và in dữ liệu ra màn hình
	{
		//Ghi file ra màn hình
		//Sử dụng loc ở trên
		fileCSV.imbue(loc);
		wstring line;

		//Đếm số lượng bản ghi, đặt bằng -1 để bỏ qua dòng đầu là tên các thuộc tính chứ ko phải bản ghi
		soLuongBanGhi = -1;
		int viTriY = 0;
		while (getline(fileCSV, line))
		{
			soLuongBanGhi++;
				int viTriX = 0;
			TextColor(7); //màu in bản ghi
			//Bắt đầu in ra màn hình
			if (soLuongBanGhi > 0)
			{
				for (int j = 0; j < danhSachCot.size(); j++) //10 cột
				{
					GotoXY(x + viTriX, y + viTriY);
					while (true)
					{
						int k = 0;
						for (k; k < danhSachCot[j].length();)
						{
							if (line[k] == ',')
							{
								line.erase(line.begin() + k);
								break;
							}
							if (line[k] == NULL)
							{
								break;
							}
							wcout << line[k];
							k = 0;
							line.erase(line.begin() + k);
						}
						break;
					}
					viTriX += danhSachCot[j].length() + 1;
				}
				viTriY += 2;
			}
			

			wcout << "\n";
		}
	}
	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);
}