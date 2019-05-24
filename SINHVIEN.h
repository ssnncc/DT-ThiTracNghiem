#ifndef DanhSachSinhVien_H
#define DanhSachSinhVien_H

#include <iostream>
#include <string.h>
#include<string>
#include"CAUHOITHI.h"
#include "Menu.h"
#include "KHUNG.h"

using namespace std;

     struct sinh_vien
     {
	    char MASV[20];
	    char HO[15];
	    char TEN[20];
	    char NgaySinh[20];
	    char GioiTinh[10];
	    char password[30];
	    DANH_SACH_DIEM_THI *Diem;
	 };
	 typedef struct sinh_vien SINH_VIEN;
	 
	 void Nhap_Thong_Tin_Sinh_Vien(SINH_VIEN &sv)
	 {
	    
	    cout<<"\nNhap ma sinh vien:";
	    cin>>sv.MASV;
	    cout<<"\nNhap Ho:";
	    cin>>sv.HO;
	    cout<<"\nNhap Ten:";
	    cin>>sv.TEN;
	    cout<<"\nNhap ngay thang nam sinh:";
	    cin>>sv.NgaySinh;
	    cout<<"\nNhap gioi tinh:";
	    cin>>sv.GioiTinh;
	    fflush(stdin);
	    cout<<"\nNhap Mat Khau:";
	    cin>>sv.password;
	    
	 }
	    void Xuat_Thong_Tin_Sinh_Vien(SINH_VIEN sv)
	    {
	    TextColor(0x0007);
		  cout<<"\nMa SV:"<<sv.MASV;
		  cout<<"\nNgay Sinh:"<<sv.NgaySinh;
		  cout<<"\nGioi Tinh:"<<sv.GioiTinh;
		  cout<<"\nMat Khau:"<<sv.password<<endl<<endl;
		
		}
		
struct node_sv
 {
   SINH_VIEN Data_SV;
  	struct node_sv *pNext_SV;
 };
 typedef  struct node_sv Node_SV;
 
 
 //Tao danh sach sinh vien
struct list_SV
  {
  	Node_SV *pHead_SV;
  	Node_SV *pTail_SV;
  	int soluongSV;
  };
typedef list_SV DANH_SACH_SINH_VIEN;

 void Khoi_Tao_DSSV(DANH_SACH_SINH_VIEN &ds)
  {
  	 ds.pHead_SV=NULL;
  	 ds.pTail_SV=NULL;
  	 ds.soluongSV=0;
  }
  
Node_SV *Khoi_Tao_Node_SV(SINH_VIEN sv)
  {
  Node_SV *p=new Node_SV;
  if(p==NULL)
  {
    cout<<"Dung luong bo nho khong du!Xin vui long kiem tra lai.";
    return  NULL;
  }
    p->Data_SV=sv;
    p->pNext_SV=NULL;
  return p;
  }
  
  
  
void Nhap_Danh_Sach_SV(DANH_SACH_SINH_VIEN &ds)
    {
	   for(Node_SV *k=ds.pHead_SV;k!=NULL;k=k->pNext_SV)
	   {
	      Nhap_Thong_Tin_Sinh_Vien(k->Data_SV);
	   }
	}
	
	
	
void Xuat_Danh_Sach_SV(DANH_SACH_SINH_VIEN ds)
  {
    vekhung(7,0,2,30);
    TextColor(0x0007);
  	gotoXY(8,1);
   	cout<<"DANH SACH SINH VIEN CUA LOP"; 
   	int i=0;
   	gotoXY(0,4);
    for(Node_SV *k=ds.pHead_SV;k!=NULL;k=k->pNext_SV)////KHI MA VIET" k=k->pNext_D" thi lai bi loi
       {
       	 TextColor(0x0007);
       	 cout<<++i<<"."<<k->Data_SV.HO<<" "<<k->Data_SV.TEN<<endl;
	     Xuat_Thong_Tin_Sinh_Vien(k->Data_SV);    
	   }
	   
  }
  
  //Them sinh vien
  
  void Them_Vao_Dau_DSSV(DANH_SACH_SINH_VIEN &ds,Node_SV *p)
  {
    if (ds.pHead_SV == NULL)
	{
		ds.pHead_SV = ds.pTail_SV = p;
	}
	else
	{
		p->pNext_SV = ds.pHead_SV; //Dung con tro cua p lien ket voi phead
		ds.pHead_SV = p;
	}
	ds.soluongSV++;
  }
  
  
  void Them_Vao_Cuoi_DSSV(DANH_SACH_SINH_VIEN &ds,Node_SV *p)
   {
        if (ds.pHead_SV == NULL)
	    {
		ds.pHead_SV = ds.pTail_SV = p;
	    }
    	else
	    {
		ds.pTail_SV->pNext_SV = p;
		ds.pTail_SV = p; 
	    }
	    ds.soluongSV++;
	    
   }
   
   
   
  //THEM BANG CACH SO SANH MA SINH VIEN
	
	void Them_Sinh_Vien_Theo_Ma_So(DANH_SACH_SINH_VIEN &ds, Node_SV *p)
	{
    	if (ds.pHead_SV == NULL)
     	{
	       	ds.pHead_SV = ds.pTail_SV = p;
	       	ds.soluongSV++;
    	}
		else if(p->Data_SV.MASV<ds.pHead_SV->Data_SV.MASV)
		{
			Them_Vao_Dau_DSSV(ds,p);
		}
    		else if(p->Data_SV.MASV>ds.pTail_SV->Data_SV.MASV)
     	{
    		Them_Vao_Cuoi_DSSV(ds,p);
      	}
	    else 
    	{
    		Node_SV *g=new Node_SV;
	    	for(Node_SV *k=ds.pHead_SV;k!=NULL;k=k->pNext_SV)
     		{
    			if(p->Data_SV.MASV<k->Data_SV.MASV)
    			{
    				Node_SV *h=Khoi_Tao_Node_SV(p->Data_SV);
    				h->pNext_SV=k;
    				g->pNext_SV=h;
    			}
    			g=k;
       		}
       		ds.soluongSV++;
    	}
    	
	}
	
	
	//Xoa sinh vien khoi danh sach sinh vien
	void Xoa_Dau_DSSV(DANH_SACH_SINH_VIEN &ds)
    {
	if (ds.pHead_SV == NULL)
	{
		return;
	}
     Node_SV *p = ds.pHead_SV; // node p là node se xóa
	ds.pHead_SV = ds.pHead_SV->pNext_SV;// cap nhat lai phead la node ke tiep
	delete p;
	ds.soluongSV--;
    }


void Xoa_Cuoi_DSSV(DANH_SACH_SINH_VIEN &ds)
{
	if (ds.pHead_SV == NULL)
	{
		return;
	}
	if (ds.pHead_SV->pNext_SV == NULL)
	{
		Xoa_Dau_DSSV(ds);
		return;
	}
	for (Node_SV *k = ds.pHead_SV; k != NULL; k = k->pNext_SV)
	{
		if (k->pNext_SV == ds.pTail_SV)
		{
			delete ds.pTail_SV;
			ds.soluongSV--; 
			k->pNext_SV = NULL; 
			ds.pTail_SV = k; 
			return;
		}
	}
	
}
void Xoa_Node_theo_MASV_Bat_Ky_Trong_DSSV(DANH_SACH_SINH_VIEN &ds,SINH_VIEN x)
{
	if (ds.pHead_SV == NULL)
	{
		return;
	}
	if(stricmp((char *)ds.pHead_SV->Data_SV.MASV, (char*)x.MASV) == 0)//stricmp((char *)k->Data.MAMH.c_str(), (char*)x.MAMH.c_str()) == 0
	{
		Xoa_Dau_DSSV(ds);
		return;
	}
	
	if (stricmp((char *)ds.pTail_SV->Data_SV.MASV, (char*)x.MASV) == 0)
	{
		Xoa_Cuoi_DSSV(ds);
		return;
	}
	Node_SV* a = new Node_SV;
	for (Node_SV *k = ds.pHead_SV; k != NULL; k = k->pNext_SV)
	{
		if (stricmp((char *)k->Data_SV.MASV, (char*)x.MASV) == 0)//k->Data.MAMH == x.MAMH
		{
			a->pNext_SV = k->pNext_SV; 
			delete k;
			ds.soluongSV--; 	
			return;
		}
		a = k; 
	}
	
}
bool KiemTraDuLieuRongCuaMenuSinhVien(int x,int y,string text[6])
{
	if(text[0].length()==0)
	{
		gotoXY(x,y);
		cout<<"\nCHUA NHAP MA SINH VIEN!!";
		return false;
	}
	else if(text[1].length()==0)
	{
		gotoXY(x,y+3);
		cout<<"CHUA NHAP HO CUA SINH VIEN!!";
		return false;
	} 
	else if(text[2].length()==0)
	{
		gotoXY(x,y+6);
		cout<<"CHUA NHAP TEN CUA SINH VIEN!!";
		return false;
	}
	else if(text[3].length()==0)
	{
		gotoXY(x,y+9);
		cout<<"CHUA NHAP NGAY SINH!!";
		return false;
	}
	else if(text[4].length()==0)
	{
		gotoXY(x,y+12);
		cout<<"CHUA NHAP GIOI TINH !!";
		return false;
	}
	else if(text[5].length()==0)
	{
		gotoXY(x,y+15);
		cout<<"CHUA NHAP PASSWORD!!";
		return false;
	}
	return true;
}


SINH_VIEN *NhapSinhVienVaoKungDangNhap(int x,int y)
{
	ShowCur(true);
	TextColor(0x0007);
	system("cls");
	gotoXY(x,y);
	cout<<"MSSV:"; vekhung(x+11,y-1,1,30);
	gotoXY(x,y+3);
	cout<<"HO:"; vekhung(x+11,y+2,1,30);
	gotoXY(x,y+6);
	cout<<"TEN:"; vekhung(x+11,y+5,1,30);
	gotoXY(x,y+9);
	cout<<"NGAY SINH:"; vekhung(x+11,y+8,1,30);	// y ko doi
	gotoXY(x,y+12);
	cout<<"GIOI TINH:"; vekhung(x+11,y+11,1,30);
	gotoXY(x,y+15);
	cout<<"PASSWORD:"; vekhung(x+11,y+14,1,30);	
	int key=0, dx = x +12,dy = y;
	int trangthai = 0;
	string text[6] = {"","","","","",""};
	gotoXY(dx,dy);
	do
	{
		key = getKey();
		switch(key){
				case key_enter:
				{
					bool kt =KiemTraDuLieuRongCuaMenuSinhVien(x+11+35,y,text);
					if(kt)
					{
						SINH_VIEN * temp = new SINH_VIEN();
						text[0].copy(temp->MASV,20);
						text[1].copy(temp->HO,15);
						text[2].copy(temp->TEN,20);
					    text[3].copy(temp->NgaySinh,20);
					    text[4].copy(temp->GioiTinh,10);
					    text[5].copy(temp->password,30);
						return temp;
					}else
					{
						gotoXY(dx,dy);
						cout<<text[trangthai];
					}
					break;
				}
			case key_back:
			{
					if(text[trangthai].length()>0)
					{	
						text[trangthai].erase(text[trangthai].length()-1,1);
						cout<<"\b \b";
					}
					break;
				}
				case key_tab:
				{
					trangthai = ++trangthai%6;//xoay vong
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
						if(trangthai == 5 ){
							cout.fill('*');
							cout<<setw(text[trangthai].length())<<'*';
						}
						else
						{
							cout<<text[trangthai];
						}
						
					}
					break;
				}	
		}
	}while(key!=27);
	ShowCur(false);
	return NULL;
}


#endif

