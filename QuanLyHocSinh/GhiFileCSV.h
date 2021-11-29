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

//Tạo và ghi file CSV vào chương trình
void GhiFileCSV(string duongDan, string tenDanhSach)
{ 
	cout << duongDan;
	
	///=============Tạo file mới ===============\\\
	
	//Đổi tên lại theo tên người dùng đặt
	string doiTen1 = "cd NewFile\\ && ren DanhSachMau.csv " + tenDanhSach;
	string doiTen2 = "cd /d " + duongDan + " && ren DanhSachMau.csv " + tenDanhSach;

	if (duongDan.empty()) //Nếu đường dẫn trống thì copy vào thư mục NewFile
	{
		system("copy DanhSachMau.csv NewFile\\");
		system(doiTen1.c_str());
	}
	else //Nếu có đường dẫn thì copy vô đường dẫn đó
	{
		string copy = "copy DanhSachMau.csv " + duongDan;
		system(copy.c_str());
		system(doiTen2.c_str());
	}

	//==============Ghi dữ liệu người dùng nhập vào file==============\\
	//Chưa xử lý

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	//Sau đó đổi tên lại theo tên người dùng đặt
	//string doiTen = "ren DanhSachMau.csv " + tenDanhSach;
	

	//locale loc(std::locale(), new std::codecvt_utf8<wchar_t>); //định dạnh file utf 8 with bom

	//wstring fullDuongDan = duongDan + tenDanhSach;

	//wofstream fileCSV(fullDuongDan, std::ios::out);

	//if (!fileCSV)
	//{
	//	ChucNang(44, 15, 80, 3, 4, L"##ERROR: Ghi tệp thất bại!! Xin kiểm tra lại đường dẫn hoặc định dạnh tệp.");

	//	//Bắt esc để quay lại menu0
	//	char luaChon;
	//	while (true)
	//	{
	//		if (_kbhit())
	//		{
	//			luaChon = _getch();
	//			if (luaChon == 27) //esc
	//			{
	//				system("cls");
	//				Menu0();
	//			}
	//		}
	//	}
	//}
	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);
}