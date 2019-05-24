#ifndef DanhSachDiemThi_H
#define DanhSachDiemThi_H
#include <iostream>
#include <string.h>
#include <fstream>
#include "Menu.h"
#include "KHUNG.h"
#include "DSMH.h"

using namespace std;

int countkey;
struct Diem_Thi
    {
	   char MAMH[20];
	   float Diem;
	};
	typedef struct Diem_Thi DIEM_THI;
  struct node_diem
 {
    DIEM_THI DIEM;
    struct node_diem* pNext_D;
 };
 typedef struct node_diem Node_DIEM;
 
 struct danh_sach_diem_thi 
 {
    Node_DIEM *pHead_Diem;
	Node_DIEM *pTail_Diem; 
	int lanthi;
 };
 typedef struct danh_sach_diem_thi DANH_SACH_DIEM_THI;
void Khoi_Tao_Danh_Sach_Diem(DANH_SACH_DIEM_THI &dsdiem)//dsd: danh sach diem
 {
 	dsdiem.pHead_Diem=NULL;
 	dsdiem.pTail_Diem=NULL;
 	dsdiem.lanthi=0;
 }
	 
Node_DIEM *Khoi_Tao_Node_Diem(DIEM_THI diem)
    {
    	Node_DIEM *a=new Node_DIEM;
	   if(a==NULL)
	      {
		    cout<<"\n\t Bo nho khong du dung luong! Xin vui long kiem tra lai.";
		    return NULL;
		  
		  }
		  a->DIEM=diem;
          a->pNext_D=NULL;
          return a;
	}
	 void Them_Vao_Cuoi_DSdiem(DANH_SACH_DIEM_THI *dsdt,node_diem *p)
   {
        if (dsdt->pHead_Diem == NULL)
	    {
		dsdt->pHead_Diem = dsdt->pTail_Diem = p;
	    }
    	else
	    {
		dsdt->pTail_Diem->pNext_D= p;
		dsdt->pTail_Diem = p; 
	    }
	    dsdt->lanthi++;
   }

struct CauHoi{
	char MaMH[20];
	char noidung[100];
	char DapAnA[100];
	char DapAnB[100];
	char DapAnC[100];
	char DapAnD[100];
	int DapAn;
};
typedef struct CauHoi CAU_HOI;
	
struct node_avl
{
	int key;
	CAU_HOI cauhoi;
	int bal;
	node_avl *pLeft;
	node_avl *pRight;
};

typedef node_avl* TREE;

void Khoi_tao_cay(TREE &tree)
{
	tree=NULL;
}	

TREE Tao_node(CAU_HOI cauhoi)
{
	TREE temp= new node_avl();
	if(temp!=NULL)
	{
		temp->key=countkey++;
		temp->pLeft=NULL;
		temp->pRight=NULL;
		temp->bal=0;
		temp->cauhoi = cauhoi;
	}
	return temp;
}

void Xoay_trai_sang_phai(TREE &tree)
{
	TREE temp=tree->pRight;
	tree->pRight=temp->pLeft;
	temp->pLeft=tree;
	tree=temp;
}

void Xoay_phai_qua_trai(TREE &tree)
{
	TREE temp=tree->pLeft;
	tree->pLeft=temp->pRight;
	temp->pRight=tree;
	tree=temp;
}

void Can_bang_phai(TREE &tree)
{
	switch (tree->pRight->bal)
	{
		case 1:
			{
				Xoay_trai_sang_phai(tree);
				tree->bal=0;
				tree->pLeft->bal=0;
				break;
			}
			case -1:
				{
					Xoay_phai_qua_trai(tree->pRight);
					Xoay_trai_sang_phai(tree);
					switch(tree->bal)
					{
						case 1:
							{
								tree->pLeft->bal=-1;
								tree->pRight->bal=0;
							    break;
							}
						case -1:
						    {
							    tree->pLeft->bal=0;
							    tree->pRight->bal=1;
							    break;
							}	
					}
				}
	}
	
}

void Can_bang_trai(TREE &tree)
{
	switch (tree->pLeft->bal)
	{
		case 1:
			{
				Xoay_phai_qua_trai(tree);
				tree->bal=0;
				tree->pRight->bal=0;
				break;
			}
			case -1:
				{
					Xoay_trai_sang_phai(tree->pLeft);
					Xoay_phai_qua_trai(tree);
					switch(tree->bal)
					{
						case -1:
							{
								tree->pLeft->bal=-1;
								tree->pRight->bal=0;
							    break;
							}
						case 1:
						    {
							    tree->pLeft->bal=0;
							    tree->pRight->bal=1;
							    break;
							}	
					}
				}
	}
	
}


bool Them_mot_node(TREE &tree, CAU_HOI cauhoi)
{
	bool height=true;
	
	if(tree==NULL)
	{
		tree=Tao_node(cauhoi);
	}
	else
	{
		 if(countkey>tree->key)
		 {
		 	height=Them_mot_node(tree->pRight,cauhoi);
		 	if(height)
		 	{
		 		switch(tree->bal)
		 			{
		 				case -1:
						{
						    tree->bal=0;
		 				    return false;
		 				}
		 				case 0:
		 					{
		 						tree->bal=1;
		 						return true;
							}
						case 1:
						{
							
						     Can_bang_phai(tree);
							return false;
						}	
					}
				
			}
		 else if(countkey<tree->key)
		 {
		 	if(height)
		 	{
		 		switch(tree->bal)
		 		{
		 					case -1:
						{
						    Can_bang_trai(tree);
		 				    return false;
		 				}
		 				case 0:
		 					{
		 						tree->bal=-1;
		 						return true;
							}
						case 1:
						{
							tree->bal=0;
							return false;
						}
				 }
			 }
		 }
		 return height;
     	}  
   } 
	
}

void Duyet_cay_theo_NLR(TREE tree)
{
	if (tree != NULL)
	{
		cout<<setw(5)<<tree->key<<char(179)
		 	<<setw(10)<<tree->cauhoi.MaMH<<char(179)
			<<setw(30)<<tree->cauhoi.noidung<<char(179)
			<<setw(15)<<tree->cauhoi.DapAnA<<char(179)
			<<setw(15)<<tree->cauhoi.DapAnB<<char(179)
			<<setw(15)<<tree->cauhoi.DapAnC<<char(179)
			<<setw(15)<<tree->cauhoi.DapAnD<<char(179)
			<<setw(10)<<tree->cauhoi.DapAn<<char(179)<<endl;
		Duyet_cay_theo_NLR(tree->pLeft);
		Duyet_cay_theo_NLR(tree->pRight);
	}
}
CauHoi* DuyetDeSua(TREE tree, int key )
{
	
	TREE trav = tree;
	while(trav!=NULL){
		if(trav->key < key){
		
			trav = trav->pRight;
		}
		else if(trav->key > key) 
		{
			cout<<trav->key;
			system("pause");
			trav = trav->pLeft;
		}
		else return &trav->cauhoi;
		
	}
	return NULL;
}
bool KiemTraDuLieuRongCauHoi(int x,int y,string text[],danh_sach_mon_hoc dsmh)
{
	if(text[0].length()==0){
		gotoXY(x,y);
		cout<<"Chua nhap Ma Mon Hoc!!";
		return 0;
	}else if(text[1].length()==0)
	{
		gotoXY(x,y+3);
		cout<<"Chua nhap noi dung cau hoi!!";
		return 0;
	}
	else if(text[2].length()==0)
	{
		gotoXY(x,y+6);
		cout<<"Chua nhap dap an A!!";
		return 0;
	}
	 else if(text[3].length()==0)
	{
		gotoXY(x,y+9);
		cout<<"Chua nhap dap an B!!";
		return 0;
	}
	else if(text[4].length()==0)
	{
		gotoXY(x,y+12);
		cout<<"Chua nhap dap an C!!";
		return 0;
	}
	else if(text[5].length()==0)
	{
		gotoXY(x,y+12);
		cout<<"Chua nhap dap an D!!";
		return 0;
	} 
	
	//kiem tra mon hoc ton tai
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
CAU_HOI *themcauhoi(int x,int y, danh_sach_mon_hoc dsmh)
{
	ShowCur(true);
	TextColor(0x0007);
	system("cls");
	gotoXY(x,y);
	cout<<"MMH:";
	 vekhung(x+11,y-1,1,30);
	gotoXY(x,y+3);
	cout<<"Cau hoi:";
	 vekhung(x+11,y+2,1,30);
	gotoXY(x,y+6);
	cout<<"Cau a:"; 
	vekhung(x+11,y+5,1,30);
	gotoXY(x,y+9);
	cout<<"Cau b:";
	vekhung(x+11,y+8,1,30);
	gotoXY(x,y+12);
	cout<<"Cau c:";
	vekhung(x+11,y+11,1,30);	
	gotoXY(x,y+15);
	cout<<"Cau d:"; 
	vekhung(x+11,y+14,1,30);
	gotoXY(x,y+18);
	cout<<"Dap An:"; 
	vekhung(x+11,y+17,1,30);
	int key=0, dx = x +12,dy = y;
	int trangthai = 0;
	string text[8] = {"","","","","","",""};
	gotoXY(dx,dy);
	do{
		key = getKey();
		
		switch(key){
				case key_enter:{
					if( KiemTraDuLieuRongCauHoi(x+11+35,y,text,dsmh)){
						CAU_HOI *temp = new CAU_HOI();
						
						text[0].copy(temp->MaMH,20);
						text[1].copy(temp->noidung,100);					
						text[2].copy(temp->DapAnA,100);
						text[3].copy(temp->DapAnB,100);
						text[4].copy(temp->DapAnC,100);
						text[5].copy(temp->DapAnD,100);	
						temp->DapAn=atoi(text[7].c_str() )	;
						return temp;
					}
					gotoXY(dx,dy);
					cout<<text[trangthai];
					break;
				}
				case key_back:{
					if(text[trangthai].length()>0){	
						text[trangthai].erase(text[trangthai].length()-1,1);
						cout<<"\b \b";
					}
					break;
				}
				case key_tab:{
					trangthai = ++trangthai%7;
					dy = y+trangthai*3;
					gotoXY(dx,dy);
					cout<<text[trangthai];
							
					break;
				}
			default:
				{
					
					if((key>31&&key<123) &&text[trangthai].length()<30){
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

//doc file
void Doc_cau_hoi(TREE &tree)
{
	int n=0;
	fstream myfile("Cauhoithi.txt",ios::in|ios::binary);
	myfile.read(reinterpret_cast<char*>(&n),sizeof(int));
	system("pause");
	int KichThuoccauhoi=sizeof(CAU_HOI);
	for(int i=0;i<n;i++)
	{
		CAU_HOI cauhoi;
		myfile.read(reinterpret_cast< char*>(&cauhoi),(KichThuoccauhoi));
		Them_mot_node(tree,cauhoi);
	}
	myfile.close();
	
}


//luu cau hoi vao file
void Luu_mot_cau_hoi(TREE &tree, fstream &myfile)
{
	if(tree!=NULL)
	{
		int KichThuoccauhoi=sizeof(CAU_HOI);
		myfile.write(reinterpret_cast<const char*>(&tree->cauhoi),(KichThuoccauhoi));
		Luu_mot_cau_hoi(tree->pLeft,myfile);
		Luu_mot_cau_hoi(tree->pRight,myfile);
	}
}
void Luu_nhieu_cau_hoi(TREE &tree)
	{
		if(countkey>0)
		{	
	        fstream myfile("Cauhoithi.txt",ios::out|ios::binary);
    		myfile.write(reinterpret_cast<const char*>(&countkey),sizeof(int));
    		Luu_mot_cau_hoi(tree,myfile);
    		myfile.close();
	    }
	}
CAU_HOI *thongtinsuacauhoi(int x,int y,CauHoi ch)
{
	ShowCur(true);
	TextColor(0x0007);
	system("cls");
	gotoXY(x,y);
	cout<<"MMH:";
	 vekhung(x+11,y-1,1,30);
	gotoXY(x,y+3);
	cout<<"Cau hoi:";
	 vekhung(x+11,y+2,1,30);
	gotoXY(x,y+6);
	cout<<"Cau a:"; 
	vekhung(x+11,y+5,1,30);
	gotoXY(x,y+9);
	cout<<"Cau b:";
	vekhung(x+11,y+8,1,30);
	gotoXY(x,y+12);
	cout<<"Cau c:";
	vekhung(x+11,y+11,1,30);	
	gotoXY(x,y+15);
	cout<<"Cau d:"; 
	vekhung(x+11,y+14,1,30);
	gotoXY(x,y+18);
	cout<<"Dap An:"; 
	vekhung(x+11,y+17,1,30);
	int key=0, dx = x +12,dy = y;
	int trangthai = 0;
	string text[7] = {ch.MaMH,ch.noidung,ch.DapAnA,ch.DapAnB,ch.DapAnC,ch.DapAnD,""};
	char tmp[10];
	itoa(ch.DapAn,tmp,10);
	text[6] = tmp;
	
	for(int i=1;i<7;++i){
		gotoXY(dx,dy+i*3);
		cout<<text[i];
	}
	gotoXY(dx,dy);
	cout<<text[0];
	
	do{
		key = getKey();
		
		switch(key){
				case key_enter:{
						CauHoi * temp = new CauHoi();
						text[0].copy(temp->MaMH,20);
						text[1].copy(temp->noidung,100);					
						text[2].copy(temp->DapAnA,100);
						text[3].copy(temp->DapAnB,100);
						text[4].copy(temp->DapAnC,100);
						text[5].copy(temp->DapAnD,100);	
						temp->DapAn=atoi(text[6].c_str() )	;
						return temp;
					gotoXY(dx,dy);
					cout<<text[trangthai];
					break;
				}
				case key_back:{
					if(text[trangthai].length()>0){	
						text[trangthai].erase(text[trangthai].length()-1,1);
						cout<<"\b \b";
					}
					break;
				}
				case key_tab:{
					trangthai = ++trangthai%7;
					dy = y+trangthai*3;
					gotoXY(dx,dy);
					cout<<text[trangthai];
							
					break;
				}
			default:
				{
					
					if((key>31&&key<123) &&text[trangthai].length()<30){
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

void suacauhoi(TREE &tree){
	int key;
	cout<<"Nhap key cau can sua:";
	cin>>key;
	
	CauHoi * ch = DuyetDeSua(tree,key);
	system("pause");
	if(ch==NULL) return;
	system("pause");
	CauHoi *temp = thongtinsuacauhoi(10,1,*ch);
	if(temp==NULL) return;
	*ch = *temp;
	
}
void QuanLyCauHoi(TREE &tree,danh_sach_mon_hoc dsmh)
{
	int soluongmenu = 3;// so luong menu
	char a[3][20] =  // khai bao mang co 3 hang va moi hang co 20 ky tu
	{
		"Them Cau hoi",
		"Sua Cau Hoi",
		"Xuat Cau hoi"
	};
	// goi ham menu trong menu.h
	int m;
	do{
		TextColor(0x0004);
		system("cls");
		m = menu(30,10,a,soluongmenu);
		switch (m){
			case  0 ://xu ly quan ly lop hoc
				{
					CAU_HOI * CH = themcauhoi(10,4,dsmh);
					
					if(CH != NULL){
						
						Them_mot_node(tree,*CH);
					} 
					break;
				}
			case 1:{
				TextColor(0x0004);
				suacauhoi(tree);
				break;
			}
			case 2://xu ly quan ly mon hoc
				{
					TextColor(0x0004);
					cout<<endl<<right<<setfill(' ')
						<<setw(5)<<"KEY"<<char(179)
					 	<<setw(10)<<"MAMH"<<char(179)
						<<setw(30)<<"NOI DUNG"<<char(179)
						<<setw(15)<<"DAP AN A"<<char(179)
						<<setw(15)<<"DAP AN B"<<char(179)
						<<setw(15)<<"DAP AN C"<<char(179)
						<<setw(15)<<"DAP AN D"<<char(179)
						<<setw(10)<<"DAP AN"<<char(179)<<endl;
						TextColor(0x0003);
					Duyet_cay_theo_NLR(tree);
					system("pause");
					break;
				}
		}
	}while(m!=-1); // khi nhan esc menu tra ve -1 va thoat
}
#endif
