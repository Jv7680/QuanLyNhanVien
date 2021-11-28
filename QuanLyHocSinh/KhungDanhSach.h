#pragma once
#include"HamTaoVaChonChucNang.h"
#include"DocFileCSV.h"

void InDanhSach(wstring duongDan, int soLuongBanGhi)
{
	MaximizeWindow();
	DisableCtrButton(0, 0, 1);
	ShowCur(0);
	
	//Ghi đường dẫn file để người xem biết
	wstring hienDuongDan = L" ##Vị Trí Tệp: " + duongDan;
	ChucNang(24, 1, 120, 3, 12, hienDuongDan);

	vector<wstring> danhSachCot = {
								L"STT", L"Mã NV", L"Họ Và Tên", L"Ngày Sinh", L"Giới Tính", L"Doanh Thu Tháng(Triệu Đồng)",
								L"Thưởng Thêm Theo Doanh Thu(%)", L"Tổng Thời Gian Đi Trễ(phút)", L"Tổng Số Giờ Làm",
								L"Tổng Lương(Triệu Đồng)"
	};

	const int x = 1, y = 5, chieuDai = 40, chieuCao = 3, mauSac1 = 13, mauSac2 = 86;

	for (size_t dong = 0; dong < soLuongBanGhi + 1; dong++)  //load theo dòng, dòng 0 là tên các thuộc tính
	{
		//Biến viTriCotKeTiep lưu vị trí cộng thêm, vị trí này sẽ bắt đầu in cột tiếp theo
		int viTriCotKeTiep = 0;
		for (size_t cot = 0; cot < danhSachCot.size(); cot++)  //load danh sách cột
		{
			if (cot == 0 && dong == 0) //Nếu dòng = 0 nghĩa là dòng đầu tiên sẽ load danh sách thuộc tính
			{
				ChucNang(x, y, danhSachCot[cot].length() + 2, chieuCao, mauSac1, danhSachCot[cot]);
				viTriCotKeTiep += x + danhSachCot[cot].length() + 1;
			}
			else if (cot == 0 && dong != 0) //Nếu dòng != 0 nghĩa là load các bản ghi
			{
				ChucNang(x, y + dong * 2, danhSachCot[cot].length() + 2, chieuCao, mauSac1, L" ");
				viTriCotKeTiep += x + danhSachCot[cot].length() + 1;
				GotoXY(x, y + dong * 2);
				cout << char(195);
			}
			else if (cot != 0 && dong == 0)
			{
				ChucNang(viTriCotKeTiep, y, danhSachCot[cot].length() + 2, chieuCao, mauSac1, danhSachCot[cot]);
				GotoXY(viTriCotKeTiep, y);
				cout << char(194);
				GotoXY(viTriCotKeTiep, y + 2);
				cout << char(193);
				viTriCotKeTiep += danhSachCot[cot].length() + 1;
			}
			else if (cot != 0 && dong != 0)  //Nếu dòng != 0 nghĩa là load các bản ghi
			{
				ChucNang(viTriCotKeTiep, y + dong * 2, danhSachCot[cot].length() + 2, chieuCao, mauSac1, L" ");
				GotoXY(viTriCotKeTiep, y + dong * 2);
				cout << char(197);
				GotoXY(viTriCotKeTiep, y + dong * 2 + 2);
				cout << char(193);
				viTriCotKeTiep += danhSachCot[cot].length() + 1;
				if (cot == danhSachCot.size() - 1)
				{
					GotoXY(viTriCotKeTiep, y + dong * 2);
					cout << char(180);
				}
			}
		}
	}
	DocFileCSV(duongDan, 0, soLuongBanGhi, x + 1, y + 3, danhSachCot);
}
