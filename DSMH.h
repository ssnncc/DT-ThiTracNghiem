	
#ifndef DanhSachMonHoc_H
#define DanhSachMonHoc_H

#include <iostream>
#include <string>
#include <string.h>
#include "Menu.h"
#include "KHUNG.h"
#include <fstream>
using namespace std;


struct mon_hoc
{
  char MAMH[20];
  char TENMH[40];
  
};
typedef struct mon_hoc MON_HOC;


void Nhap_Thong_Tin_Mon_Hoc(MON_HOC &mh)
{
    
    cout<<"\nNhap ma mon hoc:";
    cin>>mh.MAMH;
    cout<<"\nNhap ten mon hoc:";
    cin>>mh.TENMH;

}
 
 struct node
 {
    MON_HOC Data;
    struct node *pNext;
 };
 typedef struct node Node_MH;
 struct danh_sach_mon_hoc
 {
    Node_MH *pHead;
	Node_MH *pTail; 
	int soluongmh;
 };
 typedef struct danh_sach_mon_hoc DANH_SACH_MON_HOC;
 
void Khoi_Tao_Danh_Sach_Mon_Hoc(DANH_SACH_MON_HOC &dsmh)
     {
     	dsmh.pHead=NULL;
     	dsmh.pTail=NULL;
     	dsmh.soluongmh=0;
	 }
	 
Node_MH *Khoi_Tao_Node_MH(MON_HOC mh)
    {
    	Node_MH *p=new Node_MH;
	   if(p==NULL)
	      {
		    cout<<"\n\tKhong du bo nho!";
		    return NULL;
		  
		  }
		  p->Data=mh;
          p->pNext=NULL;
          return p;
	
	}
void Xuat_Danh_Sach_Mon_Hoc(DANH_SACH_MON_HOC mh)
  {
  	    vekhung(3,3,3,30);
  	    vekhung(33,3,3,30);
  	    vekhung(3,6,20,30);
  	    vekhung(33,6,20,30);
  	    gotoXY(24,2);
     	cout<<"DANH SACH MON HOC";
		gotoXY(10,4);
		cout<<"Ten mon hoc";
		gotoXY(40,4);
		cout<<"Ma mon hoc";  
		int j=7;
        for(Node_MH *k=mh.pHead;k!=NULL;k=k->pNext)
        {
	       TextColor(0x0004);
	       gotoXY(7,j);
	       cout<<k->Data.TENMH;
	       gotoXY(37,j++);
	       cout<<k->Data.MAMH;
	    }
  }	
  //Them danh sach mon hoc
  void Them_Vao_Dau(DANH_SACH_MON_HOC &ds,Node_MH *p)  //CHI CAN THEM VAO DAU LA DC MA, MON HOC CAN GI THEM CUOI VOI BAT KI
  {
    if (ds.pHead == NULL)
	{
		ds.pHead = ds.pTail = p;
	}
	else
	{
		p->pNext = ds.pHead; //Dung con tro cua p lien ket voi phead
		ds.pHead = p;
	}
	ds.soluongmh++;
  }
 

  void Xoa_Dau(DANH_SACH_MON_HOC &ds)
    {

	if (ds.pHead == NULL)
	{
		return;
	}
     Node_MH *p = ds.pHead; // node p là node se xóa
	ds.pHead = ds.pHead->pNext;// cap nhat lai phead la node ke tiep
	ds.soluongmh--;
	delete p;
    }


void Xoa_Cuoi(DANH_SACH_MON_HOC &ds) 
{
	if (ds.pHead == NULL)
	{
		return;
	}
	if (ds.pHead->pNext == NULL)
	{
		Xoa_Dau(ds);
		return;
	}
	for (Node_MH *k = ds.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == ds.pTail)
		{
			ds.soluongmh--;
			delete ds.pTail; 
			k->pNext = NULL; 
			ds.pTail = k; 
			return;
		}
	}
}

//Xoa mon hoc theo ten mon hoc(SUA LAI NE NGOAN)
void Xoa_mon_hoc_theo_ten(DANH_SACH_MON_HOC &ds, MON_HOC mh)
{
	if (ds.pHead == NULL)
	{
		return;
	}
	else if(stricmp((char *)ds.pHead->Data.TENMH,(char*) mh.TENMH) == 0)//stricmp((char *)k->Data.MAMH.c_str(), (char*)x.MAMH.c_str()) == 0
	{
		Xoa_Dau(ds);
		return;
	}
	
	else if (stricmp((char *)ds.pTail->Data.TENMH, (char*)mh.TENMH) == 0)
	{
		Xoa_Cuoi(ds);
		return;
	}
	Node_MH* a = new Node_MH;
	for (Node_MH *k = ds.pHead; k != NULL; k = k->pNext)
	{
		if (stricmp((char *)k->Data.TENMH, (char*)mh.TENMH) == 0)//k->Data.MAMH == x.MAMH
		{
			a->pNext = k->pNext; 
			ds.soluongmh--;
			delete k; 	
			return;
		}
		a = k; 
	}

}
bool KiemTraDuLieuRongCuaMenuMonHoc(int x,int y,string text[2])
  {
	if(text[0].length()==0)
	{
		gotoXY(x,y);
		cout<<"CHUA NHAP MA MON HOC!!";
	}
	else if(text[1].length()==0)
	{
		gotoXY(x,y+3);
		cout<<"CHUA NHAP TEN MON HOC!!";
	}
	return true;
}
MON_HOC *NhapThongTinMonHocVaoKungDangNhap(int x,int y)
   {
   	ShowCur(true);
	TextColor(0x0007);
	system("cls");
	gotoXY(x,y);
	cout<<"MA MON HOC:";
    vekhung(x+11,y-1,1,30);
	gotoXY(x,y+3);
	cout<<"TEN MON HOC:";
    vekhung(x+11,y+2,1,30);
	gotoXY(x,y+6);
	int key=0, dx = x +12,dy = y;
	int trangthai = 0;
	string text[2] = {"",""};
	gotoXY(dx,dy);
	do
	{
		key = getKey();
		switch(key)
		{
				case key_enter:
				{
					bool kt = KiemTraDuLieuRongCuaMenuMonHoc(x+11+35,y,text);
					if(kt)
					{
						MON_HOC * tam = new MON_HOC();
						 text[0].copy(tam->MAMH,20);
						 text[1].copy(tam->TENMH,40);
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
					if(text[trangthai].length()>0)
					{	
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
void QuanLyMonHoc(DANH_SACH_MON_HOC &ds)
{
	int soluongmenu = 4;
	char a[4][20] = 
	{
		"Them Mon Hoc",
		"Xoa Mon Hoc",
		"Sua mon hoc ",
		"Xuat danh sach",
	};
	int m ;
	do
	{
     system("cls");
	m= menu(10,10,a,soluongmenu);
	
	switch(m)
	{
		case 0:
		{
			MON_HOC* temp = NhapThongTinMonHocVaoKungDangNhap(1,1);
				if(temp != NULL)
				{
			      Them_Vao_Dau(ds,Khoi_Tao_Node_MH(*temp));
				}
				break;
		}
		case 1:
		{
			TextColor(0x0007);
			system("cls");
			MON_HOC mh;
			gotoXY(3,5);
			cout<<"Nhap ten mon hoc can xoa: ";
			gotoXY(30,5);
			gets(mh.TENMH);
			Xoa_mon_hoc_theo_ten(ds,mh);
			break;
		}
		case 2:
		{
			
			
			break;
		}
		case 3:
		{
			
			TextColor(0x0007);
			system("cls");
			Xuat_Danh_Sach_Mon_Hoc(ds);
			system("pause");
			break;
		}
	
	}
		}while(m!=-1);
		
}

void DocFile_Monhoc(DANH_SACH_MON_HOC &dsmh)
{
	
	fstream myfile("MonHoc.txt",ios::in|ios::binary);
	int n=0;
	myfile.read(reinterpret_cast<char*>(&n),sizeof(int));
	int kichthuocmotphantu = sizeof(MON_HOC);
	mon_hoc* temp=NULL;
	for(int i=0;i<n;i++)
	{
		temp=new mon_hoc();
	    myfile.read(reinterpret_cast<char*>(temp), kichthuocmotphantu);
	    Them_Vao_Dau(dsmh,Khoi_Tao_Node_MH(*temp));
    }
	myfile.close();
	
}
//ghi du lieu

void LuuFile_Monhoc(DANH_SACH_MON_HOC &dsmh)
{
	fstream myfile("MonHoc.txt",ios::out|ios::binary);
	myfile.write(reinterpret_cast<const char*>(&dsmh.soluongmh),sizeof(int));
	int kichthuocmotphantu = sizeof(MON_HOC);
	Node_MH *duyet=dsmh.pHead;
	while(duyet!=NULL)
	{
		myfile.write(reinterpret_cast<const char*>(&duyet->Data),kichthuocmotphantu);
		duyet=duyet->pNext;
	}
	myfile.close();
}
#endif
