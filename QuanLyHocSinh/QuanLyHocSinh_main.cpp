#include<iostream>
#include"Console.h"
#include"HamTaoVaChonChucNang.h"
#include"Menu0.h"
#include"Menu1.h"

using namespace std;
int main()
{
	Menu0();	
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	locale loc(std::locale(), new std::codecvt_utf8<wchar_t>); //định dạnh file utf 8 with bom

	wfstream fileCSV;
	fileCSV.imbue(loc);
	fileCSV.open("utf8bom.csv", std::ios::out);

	if (!fileCSV)
	{
		ChucNang(44, 15, 80, 3, 4, L"##ERROR: Ghi tệp thất bại!! Xin kiểm tra lại đường dẫn hoặc định dạng tệp.");

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
	else
	{
		fileCSV.imbue(loc);
		fileCSV << L"4,12345,Tín,aaaaaa,Nam,30,0.5,0,200,4.15";
		fileCSV.close();
	}
	//cout << "\n\n\n\n\n";
	system("pause");
}

