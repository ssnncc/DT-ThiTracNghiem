#ifndef DanhSachLopHoc_H
#define DanhSachLopHoc_H




#include <iostream>
#include <string.h>
#include<string>
#include"SINHVIEN.h"
#define MAX 500
#include "Menu.h"
#include "KHUNG.h"
#include  <fstream>
using namespace std;

struct lop
{
   char MALOP[50];
   char TENLOP[30];
   DANH_SACH_SINH_VIEN* DSSV;
   
};
typedef struct lop LOP;
struct  danh_sach_lop
   {
     LOP dslop[MAX];
     int soluong;
   };
//new
void khoi_tao_danh_sach_lop(danh_sach_lop &ds){
	ds.soluong = 0;
	for(int i=0;i<MAX;++i){
		ds.dslop[i].DSSV = NULL;
	}
}
   typedef danh_sach_lop DANH_SACH_LOP;

   
   	 void Xuat_Danh_Sach_LOP(DANH_SACH_LOP &ds)
     {
     	TextColor(0x0007);
     	vekhung(3,3,3,30);
  	    vekhung(33,3,3,30);
  	    vekhung(3,6,20,30);
  	    vekhung(33,6,20,30);
  	    gotoXY(24,2);
     	cout<<"DANH SACH LOP HOC";
		gotoXY(10,4);
		cout<<"Ten lop ";
		gotoXY(40,4);
		cout<<"Ma lop";  
		int j=7;         
	   	for(int i=0;i<ds.soluong;i++)
	     {
		   TextColor(0x0004);
	       gotoXY(7,j);
	       cout<<ds.dslop[i].TENLOP;
	       gotoXY(37,j++);
	       cout<<ds.dslop[i].MALOP;
		 }
	 }
	 
	 
	 
	//Them lop vao danh sach lop   // SUA LAI SAP SEP NAM DAU VAO CUA NGAY VI DU 2015 D15 TRUOC 2016 D16 SAU  //DA SUA NGOAN XEM NHA
	void Them_lop(DANH_SACH_LOP ds,LOP x)//k la vi tri can them
   {
   		int j=ds.soluong-1;
	    for(;j>=0;j--)
	    {
	    	if((stricmp((char *)x.MALOP, (char*)ds.dslop[j].MALOP) < 0))
	    	ds.dslop[j+1]=ds.dslop[j];
		}
				
		ds.dslop[j+1] = x; 
		ds.soluong++;
   }
   
   
   
   
   //Xoa lop hoc theo ma lop 
  void Xoa_lop(DANH_SACH_LOP &ds, LOP x)
   {
	for(int i = 0; i < ds.soluong; i++)
	{
		if((stricmp((char *)x.MALOP, (char*)ds.dslop[i].MALOP) == 0)) //MOI SUA LAI NGOAN XEM NHA :)))
		{
			for(int j=i+1;j<ds.soluong;j++)
			{
		        ds.dslop[j-1] = ds.dslop[j];
			}
			ds.soluong--;
			break;
        }
    }
   
  }
  
  
//Tim kiem thong tin sinh vien theo ma sinh vien VA THEO LOP HOC

void Tim_kiem_thong_tin_sinh_vien(DANH_SACH_LOP &ds,DANH_SACH_SINH_VIEN &dssv, LOP x, SINH_VIEN sv)
{
	
	for(int i = 0; i < ds.soluong; i++)
	{
		if((stricmp((char *)x.MALOP, (char*)ds.dslop[i].MALOP)) == 0)
		{
	        for (Node_SV *k = dssv.pHead_SV; k != NULL; k = k->pNext_SV)
          	{
		        if ((stricmp((char *)sv.MASV, (char *)k->Data_SV.MASV)) == 0)//k->Data.MAMH == x.MAMH
	        	{
	        		cout<< "Thong tin sinh vien ban can tim kiem: \n"<<k;
        			return;
	         	}
	        }
		}
    }           
}
LOP *TimKiemTheoMa(DANH_SACH_LOP &ds,char Ma[])
   {
      for(int i=0;i<ds.soluong;i++)
      {
	  if(stricmp(Ma,ds.dslop[i].MALOP) == 0)
	      {
		    return &ds.dslop[i];
		  }
	  }
	  return NULL;
   }
bool KiemTraDuLieuRongCuaMenuLopHoc(int x,int y,string text[2])
{
	
	if(text[0].length()==0)
	{
		gotoXY(x,y);
		cout<<"CHUA NHAP MA LOP!!";
		return false;
	}
	else if(text[1].length()==0)
	{
		gotoXY(x,y+3);
		cout<<"CHUA NHAP TEN LOP!!";
		return false;
	}
	return true;
}
LOP *NhapLopVaoKungDangNhap(int x,int y)
   {
   	ShowCur(true);
   	
	TextColor(0x0007);
	system("cls");
	gotoXY(x,y);
	cout<<"MA LOP:"; vekhung(x+11,y-1,1,30);
	gotoXY(x,y+3);
	cout<<"TEN LOP:"; vekhung(x+11,y+2,1,30);
	gotoXY(x,y+6);
	int key=0, dx = x +12,dy = y;
	int trangthai = 0;
	string text[2] = {"",""};
	gotoXY(dx,dy);
	do{
		key = getKey();
		switch(key)
		{
				case key_enter:
				{
					bool kt = KiemTraDuLieuRongCuaMenuLopHoc(x+11+35,y,text);
					if(kt)
					{
						LOP * tam = new LOP();
						 text[0].copy(tam->MALOP,20);
						 text[1].copy(tam->TENLOP,30);
						return tam;
					}
					else
					{
						gotoXY(dx,dy);
						cout<<text[trangthai];
					}
					break;
				}
			case key_back:
			{
					if(text[trangthai].length()>0){	
						text[trangthai].erase(text[trangthai].length()-1,1);
						cout<<"\b \b";
					}
					break;
				}
				case key_tab:
				{
					
					trangthai = ++trangthai%2;//xoay vong
					dy = y+trangthai*3;
					gotoXY(dx,dy);
					cout<<text[trangthai];
							
					break;
				}
			default:
				{
					if((key>47&&key<123) &&text[trangthai].length()<30)
					{
						gotoXY(dx,dy);
						text[trangthai]+=char(key);
						cout<<text[trangthai];
					}
					break;
				}	
		}
	}while(key!=27);
	ShowCur(false);
	return NULL;
   	
   }

void QuanLyLopHoc(DANH_SACH_LOP &ds)
{
	int soluongmenu = 4;
	char a[4][20] = 
	{
		"Them Lop hoc",
		"Xoa lop hoc",
		"Sua lop hoc ",
		"Xuat danh sach lop"
	};
	int m;
	do
	{
     system("cls");
     m = menu(10,10,a,soluongmenu);
	 switch(m)
	 {
		case 0:
		{
			{
				LOP* temp = NhapLopVaoKungDangNhap(1,1);
				if(temp != NULL)
				{
			      ds.dslop[ds.soluong++] = *temp;
				}
				break;
		   }
	   }
		case 1:
		{
			TextColor(0x0007);
			system("cls");
			LOP lop;
			gotoXY(3,5);
			cout<<"Nhap ma lop can xoa: ";
			gotoXY(25,5);
			gets(lop.MALOP);
			Xoa_lop(ds,lop);
			break;
		}
		case 2:
		{
			TextColor(0x0004);
			system("cls");
			LOP lop;
			cout<<"Nhap ma lop can sua: "<<lop.MALOP;
			break;
		}
		case 3:
		{
			TextColor(0x0007);
			system("cls");
			Xuat_Danh_Sach_LOP(ds);
			system("pause");
			break;
		}
	}
		}while(m!=-1);
}

   void QuanLySinhVien(DANH_SACH_LOP &ds)
{
		
	if(ds.soluong==0)
	  {
	    cout<<"\nKhong co lop hoc\n!";
	    system("pause");
	    return ;
	  }
	Xuat_Danh_Sach_LOP(ds);
	LOP* lop;
	
		cout<<"\n\n\tNhap ma lop can quan ly:" ;
	     char ma_lop[50];
	    cin.getline(ma_lop,50);
	     lop = TimKiemTheoMa(ds,ma_lop);
	     if(lop==NULL){
	     	cout<<"Ma khong trung, vui long kiem tra lai!!";
	     	system("pause");
	     	return;
		 }
		 if(lop->DSSV==NULL){
		 	lop->DSSV = new DANH_SACH_SINH_VIEN;
		 	Khoi_Tao_DSSV(*lop->DSSV);
		 }
		DANH_SACH_SINH_VIEN *dssv = lop->DSSV;
	
	int soluongmenu = 4;
	char a[4][20] = 
	{
		"Them sinh vien",
		"Xoa sinh vien",
		"Sua sinh vien",
		"Xuat danh sach",
	
	};

	int m = -1;
	do{
		TextColor(0x0007);
		system("cls");
		m = menu(10,10,a,soluongmenu);
	
	switch(m)
	{
		case 0:
		{
			SINH_VIEN *temp= NhapSinhVienVaoKungDangNhap(1,1);
			if(temp!= NULL)
			{
			Them_Vao_Dau_DSSV(*dssv,Khoi_Tao_Node_SV(*temp));
	       	}
			break;		
		}
		case 1:{    
		                        //su ly them sinh vien co ma bat ky
		    TextColor(0x0007);
			system("cls");
			SINH_VIEN sv;
		    gotoXY(3,5);
		    cout<<"Nhap ma so sinh vien can xoa: ";
		    gotoXY(35,5);
	    	gets(sv.MASV);
	   	 	Xoa_Node_theo_MASV_Bat_Ky_Trong_DSSV(*dssv,sv);
		    break;
		}
		case 2:
		{                            //su ly xoa sinh vien co ma sinh vien bat ky
			break;
		}
		case 3:
		{     
		       TextColor(0x0007);
		       system("cls");
		       Xuat_Danh_Sach_SV(*dssv);
		       system("pause");
		       break;
		}
	}
	}while(m!=-1);
}
void DocFile_LOP(DANH_SACH_LOP &ds)
{
	
	fstream myfile("LopHoc.txt",ios::in|ios::binary);
	myfile.read(reinterpret_cast<char*>(&ds.soluong),sizeof(int));
	int kichthuocmotphantu = sizeof(LOP)-sizeof(DANH_SACH_SINH_VIEN*);
	myfile.read(reinterpret_cast<char*>(ds.dslop), kichthuocmotphantu*ds.soluong);
	myfile.close();
	
}
//ghi du lieu

void LuuFile_LOP(DANH_SACH_LOP &ds)
{
	fstream myfile("LopHoc.txt",ios::out|ios::binary);
	myfile.write(reinterpret_cast<const char*>(&ds.soluong),sizeof(int));
	int kichthuocmotphantu = sizeof(LOP)-sizeof(DANH_SACH_SINH_VIEN*);
	myfile.write(reinterpret_cast<const char*>(ds.dslop),kichthuocmotphantu*ds.soluong);
	myfile.close();
	}
	
	
void DocFile_SinhVien(DANH_SACH_LOP &ds)
  {
   fstream myfile("SinhVien.txt",ios::in|ios::binary);
   int KichThuocMotPhanTuCua_SV=sizeof(SINH_VIEN)-sizeof(DANH_SACH_DIEM_THI*);
   SINH_VIEN *temp;
   for(int i=0;i<ds.soluong;i++)//duyet ds lop
      {
      	ds.dslop[i].DSSV= new DANH_SACH_SINH_VIEN();
      	Khoi_Tao_DSSV(*ds.dslop[i].DSSV);
      	int n=0;
		myfile.read(reinterpret_cast<char*>(&n),sizeof(int));	
    	if(n>0)
		for(int j=0;j<n;j++)
		  {
		  	temp= new SINH_VIEN;
		  	myfile.read(reinterpret_cast<char*>(temp),KichThuocMotPhanTuCua_SV);
		    Them_Vao_Dau_DSSV(*ds.dslop[i].DSSV,Khoi_Tao_Node_SV(*temp));
		  }	  
		
	  }
  myfile.close();
  }	
void LuuFile_SinhVien(DANH_SACH_LOP &ds)
  {
  
   fstream myfile("SinhVien.txt",ios::out|ios::binary);
   int KichThuocMotPhanTuCua_SV=sizeof(SINH_VIEN)-sizeof(DANH_SACH_DIEM_THI*);
   Node_SV *temp;
   int n = 0;
   for(int i=0;i<ds.soluong;i++)//duyet ds lop
      {
      	  
      	  if(ds.dslop[i].DSSV==NULL)
      	    {
      	      myfile.write(reinterpret_cast<const char*>(&n),sizeof(int));
			}
			else
			{
			
				myfile.write(reinterpret_cast<const char*>(&ds.dslop[i].DSSV->soluongSV),sizeof(int));
				temp=ds.dslop[i].DSSV->pHead_SV;
				while(temp!=NULL)
			  {
			  	myfile.write(reinterpret_cast<const char*>(&temp->Data_SV),KichThuocMotPhanTuCua_SV);
			  	temp = temp->pNext_SV;
			  }	 
			}
		 
	  }
	   myfile.close();
  }



#endif
