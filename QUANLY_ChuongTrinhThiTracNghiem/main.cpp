#include <iostream>
using namespace std;
#include"console.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// ham khoi tao khung dang nhap 
void Khoi_Tao_Khung_Dang_Nhap(int tdx, int tdy)
{
	gotoXY(tdx, tdy); // di chuyen den toa do x, y
	cout << "Ten tai khoan";
	gotoXY(tdx, tdy + 2);
	cout << "Mat khau";
}

// ham dang nhap
void DangNhap(string &tentk, string &mk, int x, int y)
{	
	TextColor(10);
	Khoi_Tao_Khung_Dang_Nhap(x, y);
	TextColor(7);
	
	bool KT_ESC = false;
	bool KT_ENTER = false;
	bool down = false;
	bool up = false;
	bool tab = false;


	// thiet lap 2 bien do dai toi da de kiem tra trong qua trinh nhap  
	int tentk_max = 10;
	int mk_max = 15;
	
	// 
	int VT = 1; // mac dinh dau tien la nhay vao truong du lieu ten tai khoan
	// vong lap se lap vo tan cho den khi nguoi dung nhap xong , nhan ENTER ket thuc qua trinh nhap lieu, nhan ESC huy khong nhap nua
	while (true)
	{
		// sau moi lan nhap du lieu thi reset cac bien kiem tra ve lai la false <=> chuyen qua thoi diem moi
		KT_ESC = false;
		KT_ENTER = false;
		down = false;
		up = false;
		tab = false;

		if (VT == 1)
		{	
			gotoXY(x + 15 + tentk.length(), y);
			Nhap_Du_Lieu_Chuoi_Dang_Nhap_Len_Xuong(tentk, tentk.length(), x + 15 + tentk.length(), y, tentk_max, KT_ESC, KT_ENTER, down, up, tab, true);
			gotoXY(x + 15 + mk.length(), y + 2); // di chuyen con tro chi vi den vi tri cua thuoc tinh tiep theo <=> di chuyen den thuoc tinh mat khau 
			if (down == true || up == true)
			{
				VT = 2;
			}
		}
		else if (VT == 2)
		{
			
			// di chuyen con tro chi vi den vi tri thuoc tinh mat khau
			gotoXY(x + 15 + mk.length(), y + 2);
			Nhap_Du_Lieu_Chuoi_Dang_Nhap_Len_Xuong(mk, mk.length(), x + 15 + mk.length(), y + 2, mk_max, KT_ESC, KT_ENTER, down, up, tab, false);
			gotoXY(x + 15 + tentk.length(), y); 

			if (down == true || up == true)
			{
				VT = 1;
			}
		}
		
		
		// neu nhan enter thi ket thuc qua trinh dang nhap
		if (KT_ENTER)
		{
			// da ton tai du lieu
			if (tentk.length() != 0 && mk.length() != 0)
			{
				if(tentk == "tamnguyen" && mk == "@1994")
				{
					clrscr();
					gotoXY(35, 5);
					TextColor(14);
					cout << "DANG NHAP THANH CONG !";
					return;
				}
				else
				{
					TextColor(12);
					gotoXY(15, y + 8);
					cout << "Tai khoan hoac mat khau khong hop le !";
					getch();
					gotoXY(15, y + 8); // quay lai vi tri thong bao loi xoa no di
					cout << "                                                      ";
					TextColor(7);
				}	
			}
			// neu thuoc tinh chua co du lieu thi bao loi
			else
			{
				TextColor(12);
				gotoXY(15, y + 8);
				cout << "Du lieu khong duoc de trong. Xin kiem tra lai !";
				getch();
				gotoXY(15, y + 8); // quay lai vi tri thong bao loi xoa no di
				cout << "                                                                ";
				TextColor(7);
			}
		}
		else if (KT_ESC) // huy viec thao tác
		{
			return; // ket thuc ham
		}
	}		
}

void Khung_Vien(string &tentk, string &mk)
{
	int x = 35;
	int y = 5;
	int with = 52;
	int height = 10;
	
	
	Ve_Khung(x, y, with, height);
	TextColor(14);
	gotoXY(x + 17, y + 1);
	cout << "DANG NHAP HE THONG";
	
	DangNhap(tentk, mk, x + 10, y + 3);
		
}


int main(int argc, char** argv) {
	

	string tentk;
	string mk;
//	DangNhap(tentk, mk, 0, 5);
	
	
	Khung_Vien(tentk, mk);	

	
	
	
	return 0;
}
