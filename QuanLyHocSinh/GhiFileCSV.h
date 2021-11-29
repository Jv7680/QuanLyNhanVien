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
void GhiFileCSV(wstring duongDan, wstring tenDanhSach, int check)
{
	//=============Tạo file mới ===============\\

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	locale loc(std::locale(), new std::codecvt_utf8<wchar_t>); //định dạnh file utf 8 with bom

	wstring fullDuongDan = duongDan + tenDanhSach;

	wofstream fileCSV(fullDuongDan, std::ios::out);

	if (check == 1) //Chỉ tạo file
	{
		return;
	}
	else //Nếu khác 1 thì làm thêm việc sau khi tạo file, việc thêm sửa xóa mn tự điều chỉnh code ở đây, mỗi thuộc tính cách nhau bởi dấu ,
	{
		fileCSV.imbue(loc);
		fileCSV << L"4,12345,Tín,aaaaaa,Nam,30,0.5,0,200,4.15";
		fileCSV.close();
	}

	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);
}