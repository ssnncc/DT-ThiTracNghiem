#include "SINHVIEN.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include "Menu.h"
#include "KHUNG.h"
#include "LOPHOC.h"
#include "DSMH.h"
#include "CAUHOITHI.h"
#include  <fstream>
#include <time.h>
#include "timer.h"
#include <stdlib.h>
#include <thread>
using namespace std;

SINH_VIEN *svlogin;

int DangNhap(int x,int y,danh_sach_lop ds)
{

	TextColor(9);
	vekhung(x-3,y-5,10,60);
	TextColor(15);
	gotoXY(x+22,y-3);
	cout<<"DANG NHAP";
	TextColor(11);
	gotoXY(x,y);
	cout<<"Tai khoan:"; vekhung(x+11,y-1,1,30);
	gotoXY(x,y+3);
	cout<<"Mat khau:"; vekhung(x+11,y+2,1,30);
		
	int key=0, dx = x +12,dy = y;
	int trangthai = 0;//con tro dangnhap cho tai khoan hay mat khau
	string text[2] = {"",""};
	gotoXY(dx,dy);
	do
	{
		key = getKey();//doi nhap mot phim
		switch(key)
		{
			case key_enter:
			{
				if(text[0]=="GV"&&text[1]=="GV")
				{	
					return 1;
				}else{
					node_sv *duyet;
					for(int i=0;i<ds.soluong;++i){
						if(ds.dslop[i].DSSV!=NULL){
							
							duyet = ds.dslop[i].DSSV->pHead_SV;
							
							while(duyet!=NULL){
								
								if(text[0]== duyet->Data_SV.MASV
									&& text[1]==duyet->Data_SV.password){
										svlogin=&duyet->Data_SV;
										return 2;
									}
									
								duyet=duyet->pNext_SV;
							}
						}
						
					}
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
					if(trangthai == 1){
						trangthai = 0;
						dy = y;
						gotoXY(dx,dy);
						cout<<text[trangthai];
					}
					else
					{
						trangthai = 1;
						dy= y+3;
						gotoXY(dx,dy);
						cout<<text[trangthai];
					}					
					break;
				}
			default:
				{
					if((key>47&&key<123) &&text[trangthai].length()<30)
					{
						gotoXY(dx,dy);
						text[trangthai]+=char(key);
						if(trangthai ==1 )
						{
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
	return 0;
}
bool KiemTraDuLieuRongCuaTTT(int x,int y,string text[3],DANH_SACH_MON_HOC dsmh)
{
	if(text[0].length()==0)
	{
		gotoXY(x,y);
		cout<<"\nCHUA NHAP MA MON HOC!!";
		return false;
	}
	else if(text[1].length()==0)
	{
		gotoXY(x,y+3);
		cout<<"CHUA NHAP SO LUONG CAU HOI!!";
		return false;
	} 
	else if(text[2].length()==0)
	{
		gotoXY(x,y+6);
		cout<<"CHUA NHAP THOI GIAN!!";
		return false;
	}
	Node_MH * duyet = dsmh.pHead;
	while(duyet!=NULL){
		if(stricmp((char*)duyet->Data.MAMH,text[0].c_str())==0){
			return true;
		} 
		duyet = duyet->pNext;
	}
	gotoXY(x,y);
	cerr<<"Mon hoc khong ton tai!!";
	return false;
}

bool Thong_tin_thi(char mmh[],int &soluongch,int &thoigianthi,int x,int y,DANH_SACH_MON_HOC dsmh)
   {
     ShowCur(true);
	TextColor(0x0007);
	system("cls");
	gotoXY(x,y);
	cout<<"MA MON HOC:"; vekhung(x+11,y-1,1,30);
	gotoXY(x,y+3);
	cout<<"SO LUONG CAU HOI:"; vekhung(x+11,y+2,1,30);
	gotoXY(x,y+6);
	cout<<"THOI GIAN THI:"; vekhung(x+11,y+5,1,30);
	int key=0, dx = x +12,dy = y;
	int trangthai = 0;
	string text[3] = {"","",""};
	gotoXY(dx,dy);
	do
	{
		key = getKey();
		switch(key){
				case key_enter:
				{
					bool kt =KiemTraDuLieuRongCuaTTT(x+11+35,y,text,dsmh);
					if(kt)
					{
						text[0].copy(mmh,20);
						soluongch =atoi(text[1].c_str());//atoi la ep kieu chu thanh so
						thoigianthi=atoi(text[2].c_str());
						return true;
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
					trangthai = ++trangthai%3;//xoay vong
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
	return false;
   }
//phan danh cho sinh vien
CauHoi *Random_Cau_hoi(CauHoi ch[],int n,int soluongcanlay)//n so luong cau hoi vua loc. dung
{
	cout<<n;
	if(n<1) return NULL;
    	//so luong cau hoi hien co luon luon lon hon so luong cau hoi can co
    	srand(time(NULL));//bo nho ngau nhien
    	CauHoi *ds_cauHoi = new CauHoi[soluongcanlay];
    	bool tham[100] = {0};
    	int index = 0,i=0;//index de chua chi so random dc
    	
    	while(i<soluongcanlay)
    	   {
    	   		index = rand()%n;  //so cau hoi random luon luon nho hon so cau hoi co trong cay
			   if(!tham[index])
    	   	  {
    	   	  	ds_cauHoi[i++]=ch[index];// lay cau hoi can lay
    	   	  	tham[index]=true;//danh dau vi tri da lay
				}
		   }
		   return ds_cauHoi;
}
void LocMonHoc(TREE tree,char mmh[],CauHoi ch[],int &n)// n so luong cau hoi
{
	if (tree != NULL)
	{
		if(stricmp((char *)mmh,(char*)tree->cauhoi.MaMH)==0)
		{
			ch[n++]=tree->cauhoi;
		}
		LocMonHoc(tree->pLeft,mmh,ch,n);
		LocMonHoc(tree->pRight,mmh,ch,n);
	}
}
void incauhoi(int x,int y,CauHoi ch, int cauhoihientai, int soluong, char dapanhientai ){
	gotoXY(x,y);
	cout<<" cau "<<cauhoihientai+1<<"/"<<soluong;
	gotoXY(x,++y);
	cout<<"Noi dung:"<<ch.noidung;
	gotoXY(x,++y);
	cout<<"A:"<<ch.DapAnA;
	gotoXY(x,++y);
	cout<<"B:"<<ch.DapAnB;
	gotoXY(x,++y);
	cout<<"C:"<<ch.DapAnC;
	gotoXY(x,++y);
	cout<<"D:"<<ch.DapAnD;
	gotoXY(x,y+=4);
	cout<<" Chon: "<<(dapanhientai < 65 ?' ':dapanhientai);
}

float Cham_diem(CauHoi *danhsachcauhoi , int soluong, int *traloi)
{
	float diemmotcau = 10/soluong;
	float tongdiem = 0;
	for(int i=0;i<soluong;++i)
	{
		if(danhsachcauhoi[i].DapAn==traloi[i]) tongdiem+=diemmotcau;
	}
	return tongdiem;
}
float batdauthi(CauHoi cauhoithi[],int soluong, int timethi){
	system("cls");
	int cauhoihientai = 0;
	int *traloi = new int[soluong];
	//khoi gan mang tra loi
	for(int i=0;i<soluong;++i) traloi[i]=0;
	if(cauhoihientai<soluong){
		//stop=1;
		thread clock;
		ThoiGian tg;
		tg._gio=timethi/60;
		tg._phut=timethi%60;
		tg._giay=0;
		clock=thread(printclock,tg);
		int key;
		do{
			incauhoi(30,10,cauhoithi[cauhoihientai],cauhoihientai, soluong, traloi[cauhoihientai]+64);
			key=getKey();
			switch(key){
				case key_left: {
					if(cauhoihientai>0) cauhoihientai--;
					break;
				}
				case key_right: {
					if(cauhoihientai<soluong-1) cauhoihientai++;
					break;
				}
				default:{
					if(key>'0'&&key<'5')
					{
						traloi[cauhoihientai]=key-48;
						gotoXY(30,19);
						cout<<" Chon: "<<char(key+16);
					}
					break;
				}
			}
		}while(char(key)!='s' && char(key)!='S');
		stop=0;// dung dong ho
		//Tinh diem thi
	
		clock.join();
		float diem = Cham_diem(cauhoithi,soluong,traloi);
		delete [] traloi;
		system("pause");
	    return diem;
	}
}

void docdiemsinhvien(DANH_SACH_LOP &dsl){
	fstream myfile("diemthi.txt",ios::in|ios::binary);
	int kichthuoc = sizeof(DIEM_THI);
	int n=0;
	for(int i=0;i<dsl.soluong;++i){
		if(dsl.dslop[i].DSSV==NULL) continue;
		node_sv *dssv = dsl.dslop[i].DSSV->pHead_SV;
		while(dssv!=NULL){
			n=0;
			dssv->Data_SV.Diem = new danh_sach_diem_thi();
			Khoi_Tao_Danh_Sach_Diem(*dssv->Data_SV.Diem);
			myfile.read(reinterpret_cast<char *>(&n),sizeof(int)); 
			if(n>0){
				for(int i=0;i<n;i++){
					Diem_Thi * diem = new Diem_Thi();
					myfile.read(reinterpret_cast<char*>(diem),kichthuoc); 
					Them_Vao_Cuoi_DSdiem(dssv->Data_SV.Diem,Khoi_Tao_Node_Diem(*diem));
					
				}
			}
			dssv = dssv->pNext_SV;
		}	
	}
	myfile.close();
}
void luudiemsinhvien(DANH_SACH_LOP dsl){
	fstream myfile("diemthi.txt",ios::out|ios::binary);
	int kichthuoc = sizeof(DIEM_THI);
	node_sv *trav;
	int n=0;
	for(int i=0;i<dsl.soluong;++i){
		if(dsl.dslop[i].DSSV==NULL) continue;
		node_sv *dssv = dsl.dslop[i].DSSV->pHead_SV;
		while(dssv!=NULL){
			if(dssv->Data_SV.Diem==NULL||dssv->Data_SV.Diem->pHead_Diem==NULL)
				myfile.write(reinterpret_cast<const char*>(&n),sizeof(int));
			else{
				myfile.write(reinterpret_cast<const char*>(&dssv->Data_SV.Diem->lanthi),sizeof(int));
				if(dssv->Data_SV.Diem->lanthi > 0){
					Node_DIEM * dssdiem = dssv->Data_SV.Diem->pHead_Diem;
					while(dssdiem!=NULL){
						
						myfile.write(reinterpret_cast<const char*>(&dssdiem->DIEM),sizeof(Diem_Thi));
						cout<<dssdiem->DIEM.Diem;
						system("pause");
						dssdiem =dssdiem->pNext_D;
					}
				}
			 
				
			}
			dssv = dssv->pNext_SV;
		}	
	}
	myfile.close();
	
}
void Sap_xep_danh_sach_diem(danh_sach_diem_thi *dsDiem)
{
	node_diem *min=dsDiem->pHead_Diem;
	for(node_diem *k=dsDiem->pHead_Diem;k!=NULL;k=k->pNext_D)
	{
		for(node_diem *j=dsDiem->pHead_Diem;j!=NULL;j=j->pNext_D)
		{
			if(stricmp(min->DIEM.MAMH,j->DIEM.MAMH)>0)
			  {
			  	min=j;
			  }
		}
		DIEM_THI a;
		a=min->DIEM;
		min->DIEM=k->DIEM;
		k->DIEM=a;
	}
	
}

void PhanThi(DANH_SACH_MON_HOC dsmh,TREE caycauhoi){
	int soluong=0,timethi=0;
	char mmh[20];
	CauHoi dscauhoi1mon[100];
	CauHoi *cauhoithhi = NULL;
	int n = 0;
	Thong_tin_thi(mmh,soluong,timethi,10,10,dsmh);
	LocMonHoc(caycauhoi,mmh,dscauhoi1mon,n);
	
	cauhoithhi = Random_Cau_hoi(dscauhoi1mon,n,soluong);
	if(cauhoithhi!=NULL)
	{
		float diem=batdauthi(cauhoithhi,soluong, timethi);
		cout<<"\nKet qua thi: "<<diem;
		if(svlogin->Diem==NULL)
		   {
		   	svlogin->Diem= new DANH_SACH_DIEM_THI();
		   	Khoi_Tao_Danh_Sach_Diem(*svlogin->Diem);
		   }
		   Diem_Thi DIEM;
		   strcpy(DIEM.MAMH, mmh);
		   DIEM.Diem=diem;
		   
		  Them_Vao_Cuoi_DSdiem(svlogin->Diem, Khoi_Tao_Node_Diem(DIEM));
		  Sap_xep_danh_sach_diem(svlogin->Diem);
	}

	system("pause");

}

void xuatdanhdiem(SINH_VIEN *sv){
	node_diem *duyet=sv->Diem->pHead_Diem;
	TextColor(0x0007);
    	vekhung(3,3,3,30);
	  	vekhung(33,3,3,30);
  	    vekhung(3,6,20,30);
  	    vekhung(33,6,20,30);
  	    gotoXY(29,2);
     	cout<<"DIEM THI";
		gotoXY(10,4);
		cout<<"Ma mon hoc";
		gotoXY(40,4);
		cout<<"Diem";
	    int j=7;
        while(duyet!=NULL)
        {
            TextColor(0x0004);
            
	        gotoXY(7,j);
	         cout<<duyet->DIEM.MAMH;
    	    gotoXY(38,j++);
    	    cout<<duyet->DIEM.Diem;
        	duyet=duyet->pNext_D;
     	}
	system("pause");
}

void PhanSinhVien(DANH_SACH_MON_HOC dsmh,TREE caycauhoi){
	
	system("cls");
	char a[2][20] =  // khai bao mang co 4 hang va moi hang co 20 ky tu
	{
		"THI",
		"XEM DIEM"
		
	};        
	int soluongmenu = 2;
	int m = -1;
	do{
		m = menu(10,10,a,soluongmenu);
		
		switch(m){
			case 0:{
				
				PhanThi(dsmh,caycauhoi);
				break;
			}
			case 1:{
				TextColor(0x0004);
				system("cls");
			    xuatdanhdiem(svlogin);
				break;
			}
		}
	}while(m!=-1);
} 


int main()
{
	DANH_SACH_MON_HOC ds_MH;
	Khoi_Tao_Danh_Sach_Mon_Hoc(ds_MH);
	TREE CayCauHoi = NULL;
	DANH_SACH_LOP ds_LOP;
	khoi_tao_danh_sach_lop(ds_LOP);
	DocFile_Monhoc(ds_MH);
	DocFile_LOP(ds_LOP);
	DocFile_SinhVien(ds_LOP);
	Doc_cau_hoi(CayCauHoi);
	docdiemsinhvien(ds_LOP);
	int tmp = DangNhap(15,8,ds_LOP);
	switch(tmp){
		case 0:{			
			return 0;
		}	
		case 2:{//sinh vien
			PhanSinhVien(ds_MH,CayCauHoi);
			luudiemsinhvien(ds_LOP);
			return 0;
		}
	}
	
	ShowCur(false);
	
	
	
//-----tao ra danhTREE sach menu-----
	int soluongmenu = 4;// so luong menu
	
	char a[4][20] =  // khai bao mang co 4 hang va moi hang co 20 ky tu
	{
		
		"QUAN LY LOP HOC",
		"QUAN LY SINH VIEN",
		"QUAN LY MON HOC",
		"QUAN LY CAU HOI THI"
	};                                   
	// goi ham menu trong menu.h
	int m;
	do
	{
		TextColor(0x0004);
		system("cls");
		m = menu(30,10,a,soluongmenu);
		
		switch (m)
		{
			case  0 ://xu ly quan ly lop hoc
				{
					
					TextColor(0x0004);
					system("cls");
					QuanLyLopHoc(ds_LOP);
					break;
				}
			case 1://xu ly quan ly sinh vien
				{
					TextColor(0x0004);
					system("cls");
					QuanLySinhVien(ds_LOP);
					break;
				}
			case 2://xu ly quan ly mon hoc
				{
					TextColor(0x0004);
					system("cls");
					QuanLyMonHoc(ds_MH);
				//	system("pause");
					break;			
				}
			case 3:
				{
					TextColor(0x0004);
					system("cls");
					QuanLyCauHoi(CayCauHoi,ds_MH);
					break;
					system("pause");
				}	
			
		}
	}while(m!=-1); // khi nhan esc menu tra ve -1 va thoat
	 LuuFile_LOP(ds_LOP);
	 LuuFile_SinhVien(ds_LOP);
	 LuuFile_Monhoc(ds_MH);
	 Luu_nhieu_cau_hoi(CayCauHoi);
	
	return 0;
}


