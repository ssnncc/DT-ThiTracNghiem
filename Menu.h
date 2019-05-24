#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "KHUNG.h"

using namespace std;

#define key_Up 1072
#define key_dw 1080
#define key_left 1075
#define key_right 1077
#define key_esc 27
#define key_enter 13
#define key_back 8
#define key_tab 9

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//ham bat mot phim
int getKey(){
	int key = getch();
	if(key==224) key=getch()+1000;
	return key;
}

int menu(int x,int y,char a[4][20],int soluongmenu){
	int key = 0; // luu gia tri phim duoc nhan
	int menuduocchon = 0;// luu menu dang duoc chon
	do{
		//in ra menu
		TextColor(7);
		for	(int i =0;i<soluongmenu;++i){
			vekhung(x-1,y+3*i-1,1,30);
			gotoXY(x,y+3*i);
			cout<<a[i]<<endl;
		}
		//chon mau va to nen cho menu duoc chon
		TextColor(0x0034);
		gotoXY(x,y+3*menuduocchon); 
		cout<<a[menuduocchon]; // in lai menu duoc chon
		
		key = getKey(); // bat phim
		
		switch(key){
			case key_Up:
				{
					if(menuduocchon>0)	menuduocchon--; // truong hop menu dang tren dau
					break;
				}
			case key_dw:
				{
					if(menuduocchon < soluongmenu-1) menuduocchon++;//truong hop menu duoi cuoi dung
					break;
				}
				case key_enter:
					{
						return menuduocchon; // tra ra gia tri menu dang duoc chon
						break;
					}
		}	
		//cout<< (char)key << " "<<key<<endl;
	}while(key!=key_esc);
return -1;
}
#endif
